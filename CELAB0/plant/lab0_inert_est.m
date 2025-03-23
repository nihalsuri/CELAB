% This script is used to perform the estimation of friction and inertia
% values for the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation on the blackbox model or the real
% model

%% Loading Data

% Load the experimental data from the 21.03.2025
load('C:\01 Daten\00 Uni Padova ConM\2. Semester\Control_Engineering_Lab\Git_gang\CELAB\CELAB0\plant\simout_inertia.mat')


% Previously estimated friction parameters
ls.Beq = 2.5663e-6;         % [Nm/(rad/s)]
ls.tau_sf = 0.013;          % [Nm]


% Unpacking simulation data
sOut.time = out_omega_motor.time;                       % [s]
sOut.omeg = out_omega_motor.signals.values*rpm2rads;    % [rad/s]
sOut.curr = out_i_a.signals.values;                     % [A]
sOut.acc.data = out_a_motor.signals.values*rpm2rads;    % [rad/s^2]



%% Calculating the Inertial Torque

% Torque due to friction [Nm]
sOut.tau_f = ls.Beq*sOut.omeg + ls.tau_sf/gbox.N *sign(sOut.omeg);
% Torque due to inertia [Nm]
sOut.tau_i.data = sOut.curr*mot.Kt - sOut.tau_f;



%% Averaging the Data

% Computation of the means for each interval, truncated by 0.2 seconds at
% the beginning and end to neglect transient effects

% Initializing arrays
sOut.acc.means = zeros(inert_est.num*2,1);
sOut.tau_i.means = zeros(inert_est.num*2,1);

plt.xfill = zeros(4*inert_est.num*2, 1);
plt.yfill = ones(4*inert_est.num*2, 1);

for i=1:inert_est.num*2
    % Start and stop times of each interval
    lp.int_start = (i-1)*inert_est.time+0.2;
    lp.int_stop = (i)*inert_est.time-0.2;
    % Indices for the interval
    lp.idx = (sOut.time <= lp.int_stop) .* (sOut.time >= lp.int_start);
    lp.idx = find(lp.idx);
    
    % Mean values on the interval for acceleration and inertial torque
    sOut.acc.means(i) = weighted_mean(sOut.acc.data(lp.idx), ...
                                      sOut.time(lp.idx));       % [rad/s^2]
    sOut.tau_i.means(i) = weighted_mean(sOut.tau_i.data(lp.idx),...
                                        sOut.time(lp.idx));     % [Nm]

    % Plot params
    plt.xfill((i-1)*4+1:i*4) = [[1 1]*lp.int_start, [1 1]*lp.int_stop];
end



%% Calculation of the Moment of Inertia 

lp.Jeq_sum = 0;
for i=1:2:inert_est.num
    % estimation for one cycle [Nm/(rad/s^2)] = [kg m^2]
    lp.Jeq_i = (sOut.tau_i.means(i) - sOut.tau_i.means(i+1))/...
                 (sOut.acc.means(i) - sOut.acc.means(i+1));
    % summing the cycles
    lp.Jeq_sum = lp.Jeq_sum + lp.Jeq_i;
end
% average of the cycles [kg m^2]
Jeq = lp.Jeq_sum/10;

disp("Estimated Moment of Inertia [kg m^2]:")
disp(Jeq)



%% Plotting
plt.f1 = plot_meas(sOut.tau_i.data, sOut.time, sOut.tau_i.means, ...
                   1, inert_est, plt, "\tau_i [Nm]");
plt.f2 = plot_meas(sOut.acc.data, sOut.time, sOut.acc.means, ...
                   2, inert_est, plt, "a_m [rad/s^2]");





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



function [f] =  plot_meas(data, time, means, fig, inert_est, plt, ylab)
    % Plots the measured timeseries against the calculated means
    % data - measured data (array)
    % time - timestamps of the measured data (array)
    % means - array of calculated means (array)
    % fig - index of the figure created (int)
    % frict_est - struct containing the time and number of steps with
    %             field names num and time (struct)
    % plt - struct containing coordinates of averaging intervall to be 
    %       highlighted, with field names xfill and yfill (struct)
    % ylab - string with the y-axis label (string)

    % y-lims of the plot
    bot_lim = min(min(data)*1.1, 0);
    top_lim = max(max(data)*1.1, 0);
    lim = [bot_lim, [1,1]*top_lim, bot_lim];
    
    % limits of highlight
    plt.yfill = plt.yfill'.*lim';
    plt.yfill = plt.yfill(1:inert_est.num*2*4);

    % Trail time steps
    sim_time = (0:inert_est.num*2)*inert_est.time;

    f = figure(fig);
    hold on
    % Highlighted areas
    fill(plt.xfill, plt.yfill, [0.9 0.9 0.9],...
        'EdgeColor', 'none', 'FaceAlpha', 0.5)
    plot(time, data, 'LineWidth', 1)
    stairs(sim_time, [means; means(end)],'LineWidth', 1)
    hold off

    legend("Averaging Interval", "Measured", "Averaged")
    xlabel("Time [s]")
    ylabel(ylab)
    ylim([bot_lim, top_lim])
    grid on
end



