% This script is used to perform the estimation of friction and inertia
% values for the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation of "lab0_model_blackbox.slx"



%% Data Preparation

% Define indices of positive and negative staircases
tstp.end_staircase_p = sIn.step_time*sIn.step_number;
tstp.start_staircase_n = tstp.end_staircase_p + sIn.step_time;
idx.staircase_p = (out.omega_motor.Time <= tstp.end_staircase_p);
idx.staircase_n = (out.omega_motor.Time >= tstp.start_staircase_n);


% Split the timeseries in positive and negative trails
% Units: omega_motor - [deg/s]    i_a - [A]
sOut.mot.omeg.p = getsamples(out.omega_motor, idx.staircase_p);
sOut.mot.curr.p = getsamples(out.i_a, idx.staircase_p);

sOut.mot.omeg.n = getsamples(out.omega_motor, idx.staircase_n);
sOut.mot.curr.n = getsamples(out.i_a, idx.staircase_n);


% Shift the time of the negative staircase to start at 0
sOut.mot.omeg.n.Time = sOut.mot.omeg.n.Time - sOut.mot.omeg.n.Time(1);
sOut.mot.curr.n.Time = sOut.mot.curr.n.Time - sOut.mot.curr.n.Time(1);


% Initialization of arrays for motor angular velocity, current and torque
% Different steps in rows, pos/neg trail in columns
mot.omeg_means = zeros(sIn.step_number, 2);
mot.curr_means = zeros(sIn.step_number,2);
mot.tau_means = zeros(sIn.step_number, 2);


% Initialization for plotting
plt.xfill = zeros(4*sIn.step_number,1);
plt.yfill = zeros(4*sIn.step_number,1);



%% Averaging the Data

% Computation of the means for each interval, truncated by one second at
% the beginning and end to neglect transient effects
for i=1:sIn.step_number
    % Start and stpo times of each intervall
    lp.t_start = (i-1)*sIn.step_time+1;
    lp.t_stop = (i)*sIn.step_time-1;

    % Function handle for calculation of mean of one timeseries
    lp.calc_mean = @(ts) ts_weighted_mean(ts, lp.t_start, lp.t_stop);
    
    % Calculating the means for both pos. and neg. trail at once
    mot.omeg_means(i,:) = structfun(lp.calc_mean, sOut.mot.omeg)';
    mot.curr_means(i,:) = structfun(lp.calc_mean, sOut.mot.curr)';

    % Motor torque [Nm]
    mot.tau_means(i,:) = mot.Kt.*mot.curr_means(i,:);

    plt.xfill(lp.t_start:lp.t_stop) = [[1 1]*lp.t_start, [1 1]*lp.t_stop];
    plt.yfill(lp.t_start:lp.t_stop) = [0,1,1,0];
end



%% Least Squares Estimation of the Friction Parameters

% Function handles for easy repeatability
% The input matrix for LS fitting is Phi, omega with unit [krpm]
ls.Phi = @(omega)[omega/1000, 1/gbox.N1*sign(omega)];
ls.LS = @(omega,i) ls.Phi(omega(:,i))\mot.tau_means(:,i);

% Least squares estimate for positive and negative trail
ls.est_p = ls.LS(mot.omeg_means, 1);
ls.est_n = ls.LS(mot.omeg_means, 2);

% Average of friction parameters from positive and negative trail
ls.Beq = sum([ls.est_p(1), ls.est_n(1)])/2
ls.tau_sf = sum(abs([ls.est_p(2), ls.est_n(2)]))/2



%% Plotting

% Measurements with mean values over time
%{
plt.f1 = plot_meas(sOut.mot.omeg.p, mot.omeg_means(:,1), 1, sIn, plt, "\omega_m [krpm]");
plt.f2 = plot_meas(sOut.mot.omeg.n, mot.omeg_means(:,2), 2, sIn, plt, "\omega_m [krpm]");
plt.f3 = plot_meas(sOut.mot.curr.p, mot.curr_means(:,1), 3, sIn, plt, "i_a [A]");
plt.f4 = plot_meas(sOut.mot.curr.n, mot.curr_means(:,2), 4, sIn, plt, "i_a [A]");
%}

% Friction torque over motor speed
plt.f5 = figure(5);
hold on
scatter(mot.omeg_means/1000, mot.tau_means, "MarkerEdgeColor", "#0072BD")

% Whole Phi matrix
plt.Phi_p = ls.Phi(mot.omeg_means(:,1));
% Extraxting the last element and "extrapolating to 0"
plt.Phi_p = [0, plt.Phi_p(1,2); plt.Phi_p(end,:)];
% Estimation of the torque
plt.tau_p = plt.Phi_p*ls.est_p;
plot([0,plt.Phi_p(2,1)], plt.tau_p, "Color", "#D95319")

plt.Phi_n = ls.Phi(mot.omeg_means(:,2));
plt.Phi_n = [0, plt.Phi_n(1,2); plt.Phi_n(end,:)];
plt.tau_n = plt.Phi_n*ls.est_n;
plot([0,plt.Phi_n(2,1)], plt.tau_n, "Color", "#D95319")

xlim([plt.Phi_n(end,1),plt.Phi_p(end,1)])
xlabel("\omega_m [krpm]")
ylabel("\tau_m = \tau_d' [A]")
legend("Experimental Data", "", "LS Fitting")
grid on







function [weighted_mean] = ts_weighted_mean(ts, t_start, t_end)
    % Computes the weighted mean of a timeseries over an interval.
    % ts - timeseriesobject, may be of variable step size
    % t_start & t_stop - start and stop times of the interval

    % Compute indices in the considered time interval
    idx = (ts.Time >= t_start) & (ts.Time <= t_end);

    % Select the data in the considered inteval
    time_int = ts.Time(idx);
    data_int = ts.Data(idx);

    % True interval
    true_interval = time_int(end)-time_int(1);

    % Compute weighted mean using trapezoidal integration
    integral_value = trapz(time_int, data_int);
    weighted_mean = integral_value/true_interval;
end

function [f] =  plot_meas(ts, means, fig, sIn, plt, ylab)

    % Plots the measured timeseries against the calculated means
    % ts - measured timeseries; means - array of calculated means
    % fig - index of the figure created
    % sIn - struct containing the time and number of steps with
    %       field names step_number and step_time
    % plt - struct containing coordinates of averaging intervall to be 
    %       highlighted, with field names xfill and yfill
    % ylab - string with the y-axis label

    % Check if positive or negative trail and assignment of the y-limit
    if (means(end)>0)
        lim = max(ts.Data)/1000*1.1;
    else
        lim = min(ts.Data)/1000*1.1;
    end

    % Trail time
    sim_time = (0:sIn.step_number)*sIn.step_time;

    f = figure(fig);
    hold on
    % Highlighted areas
    fill(plt.xfill, plt.yfill*lim, [0.9 0.9 0.9], 'EdgeColor', 'none', 'FaceAlpha', 0.5)
    plot(ts/1000, 'LineWidth', 1)
    stairs(sim_time, [means; means(end)]/1000,'LineWidth', 1)
    hold off
    legend("Averaging Interval", "Measured", "Averaged")
    xlabel("Time [s]")
    ylabel(ylab)
    %y-limits depending on positive or negative trail
    ylim([min(lim,0) max(lim,0)])
    grid on
end
