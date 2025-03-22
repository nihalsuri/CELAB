% This script is used to perform the estimation of friction and inertia
% values for the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation on the blackbox model or the real
% model



%% Data Preparation

% Define indices of positive and negative staircases
idx.t_end_staircase_p = friction_est.time*friction_est.num;
idx.t_start_staircase_n = idx.t_end_staircase_p + friction_est.time;

idx.staircase_p = (out_omega_motor.time <= idx.t_end_staircase_p);
idx.staircase_n = (out_omega_motor.time >= idx.t_start_staircase_n);



% Extract the Data and Timestapms (one time array for pos and one for neg)
% for fixed timesteps this could be ommited but for varaible not
% Units: omega_motor - [deg/s]    i_a - [A]
% Times
sOut.time.p = out_omega_motor.time(find(idx.staircase_p));
sOut.time.n = out_omega_motor.time(find(idx.staircase_n));

% Positive trail
sOut.omeg.p = out_omega_motor.signals.values(find(idx.staircase_p));
sOut.curr.p = out_i_a.signals.values(find(idx.staircase_p));

% Negative trail
sOut.omeg.n = out_omega_motor.signals.values(find(idx.staircase_n));
sOut.curr.n = out_i_a.signals.values(find(idx.staircase_n));

% Shift the time of the negative staircase to start at 0
sOut.time.n = sOut.time.n - sOut.time.n(1);



% Initialization of arrays for motor angular velocity, current and torque
% Different steps in rows, pos/neg trail in columns
sOut.omeg.means = zeros(friction_est.num, 2);
sOut.curr.means = zeros(friction_est.num, 2);
sOut.tau.means  = zeros(friction_est.num, 2);


% Initialization for plotting
plt.xfill = zeros(4*friction_est.num, 1);
plt.yfill = zeros(4*friction_est.num, 1);



%% Averaging the Data
% Computation of the means for each interval, truncated by one second at
% the beginning and end to neglect transient effects

for i=1:friction_est.num
    % Start and stpo times of each intervall
    lp.int_start = (i-1)*friction_est.time+1;
    lp.int_stop = (i)*friction_est.time-1;
    % Function handle to compute indices
    lp.get_idx = @(time) (time >= lp.int_start) .* (time <= lp.int_stop);
    % Calculation of indices, lp.idx contains fields .p and .n
    lp.idx = structfun(lp.get_idx, sOut.time, 'UniformOutput',false);
    lp.idx.p = find(lp.idx.p);
    lp.idx.n = find(lp.idx.n);

    % Calculating the means for both pos. and neg. trail 
    sOut.omeg.means (i,1) = weighted_mean(sOut.omeg.p(lp.idx.p),...
                                        sOut.time.p(lp.idx.p));
    sOut.omeg.means (i,2) = weighted_mean(sOut.omeg.n(lp.idx.n),...
                                        sOut.time.n(lp.idx.n));

    sOut.curr.means(i,1) = weighted_mean(sOut.curr.p(lp.idx.p),...
                                       sOut.time.p(lp.idx.p));
    sOut.curr.means(i,2) = weighted_mean(sOut.curr.n(lp.idx.n),...
                                       sOut.time.n(lp.idx.n));
    % Motor torque [Nm]
    sOut.tau.means(i,:) = mot.Kt.*sOut.curr.means(i,:);

    plt.xfill((i-1)*4+1:i*4) = [[1 1]*lp.int_start, [1 1]*lp.int_stop];
    plt.yfill((i-1)*4+1:i*4) = [0,1,1,0];
end



%% Least Squares Estimation of the Friction Parameters

% Function handles for easy repeatability
% The input matrix for LS fitting is Phi, omega with unit [krpm]
ls.Phi = @(omega)[omega/1000, 1/gbox.N1*sign(omega)];
ls.LS = @(omega,i) ls.Phi(omega(:,i))\sOut.tau.means(:,i);

% Least squares estimate for positive and negative trail
ls.est_p = ls.LS(sOut.omeg.means, 1);
ls.est_n = ls.LS(sOut.omeg.means, 2);

% Average of friction parameters from positive and negative trail
ls.Beq = sum([ls.est_p(1), ls.est_n(1)])/2;         %[Nm/krpm]
ls.tau_sf = sum(abs([ls.est_p(2), ls.est_n(2)]))/2; %[Nm]

% Output of the estimated parameters in correct unit
disp("Estimated viscous friction parameter in [Nm/(rad/s)]:")
disp(ls.Beq/1000/rpm2rads)
disp(" ")
disp("Estimated static friction parameter in [Nm]:")
disp(ls.tau_sf)



%% Plotting

% Measurements with mean values over time

plt.f1 = plot_meas(sOut.omeg.p, sOut.time.p, sOut.omeg.means(:,1), ...
                   1, friction_est, plt, "\omega_m [krpm]");
plt.f2 = plot_meas(sOut.omeg.n, sOut.time.n, sOut.omeg.means(:,2), ...
                   2, friction_est, plt, "\omega_m [krpm]");
plt.f3 = plot_meas(sOut.curr.p, sOut.time.p, sOut.curr.means(:,1), ...
                   3, friction_est, plt, "i_a [A]");
plt.f4 = plot_meas(sOut.curr.n, sOut.time.n, sOut.curr.means(:,2), ...
                   4, friction_est, plt, "i_a [A]");


% Friction torque over motor speed

% Whole Phi matrix (positive)
plt.Phi_p = ls.Phi(sOut.omeg.means(:,1));
% Extraxting the last element and "extrapolating to 0"
plt.Phi_p = [0, plt.Phi_p(1,2);
             plt.Phi_p(end,:)];
% Estimation of the torque
plt.tau_p = plt.Phi_p*ls.est_p;

% (negative)
plt.Phi_n = ls.Phi(sOut.omeg.means(:,2));
plt.Phi_n = [0, plt.Phi_n(1,2);
             plt.Phi_n(end,:)];
plt.tau_n = plt.Phi_n*ls.est_n;

% Stacking reduced Phi matrices from negative and positive
% (reordered in ascending order of omegas)
plt.Phi_pn = [plt.Phi_n(end,:);
            plt.Phi_n(1,:);
            plt.Phi_p];
% Calculate torque with averaged estiamtes
plt.tau_pn = plt.Phi_pn*[ls.Beq; ls.tau_sf];


plt.f5 = figure(5);
hold on
% Measured tau [Nm] over omega [krpm]
scatter(sOut.omeg.means/1000, sOut.tau.means, "MarkerEdgeColor", "#0072BD")
% LS estimate positive
plot(plt.Phi_p(:,1), plt.tau_p, "Color", "#D95319")
% LS estimate negative
plot(plt.Phi_n(:,1), plt.tau_n, "Color", "#D95319")
% Average from LS estimate -> Deadzone
plot(plt.Phi_pn(:,1), plt.tau_pn)
hold off

% additional plot configs
xlim([plt.Phi_n(end,1),plt.Phi_p(end,1)])
xlabel("\omega_m [krpm]")
ylabel("\tau_m = \tau_d' [A]")
legend("Experimental Data", "", "LS Fitting")
grid on







%% Functions Used
function [weighted_mean] = weighted_mean(data, time)
    % Computes the weighted mean of an array "data" specified at timestapms
    % in "data"
    
    % True interval
    true_interval = time(end)-time(1);

    % Compute weighted mean using trapezoidal integration
    integral_value = trapz(time, data);
    weighted_mean = integral_value/true_interval;
end



function [f] =  plot_meas(data, time, means, fig, friction_est, plt, ylab)
    % Plots the measured timeseries against the calculated means
    % data - measured data (array)
    % time - timestamps of the measured data (array)
    % means - array of calculated means (array)
    % fig - index of the figure created (int)
    % friction_est - struct containing the time and number of steps with
    %                field names step_number and step_time (struct)
    % plt - struct containing coordinates of averaging intervall to be 
    %       highlighted, with field names xfill and yfill (struct)
    % ylab - string with the y-axis label (string)

    % Check if positive or negative trail and assignment of the y-limit
    if (means(end)>0)
        lim = max(data)/1000*1.1;
    else
        lim = min(data)/1000*1.1;
    end

    % Trail time steps
    sim_time = (0:friction_est.num)*friction_est.time;

    f = figure(fig);
    hold on
    % Highlighted areas
    fill(plt.xfill, plt.yfill*lim, [0.9 0.9 0.9],...
        'EdgeColor', 'none', 'FaceAlpha', 0.5)
    plot(time, data/1000, 'LineWidth', 1)
    stairs(sim_time, [means; means(end)]/1000,'LineWidth', 1)
    hold off

    legend("Averaging Interval", "Measured", "Averaged")
    xlabel("Time [s]")
    ylabel(ylab)
    %y-limits depending on positive or negative trail
    ylim([min(lim,0) max(lim,0)])
    grid on
end
