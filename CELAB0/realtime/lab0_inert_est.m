% This script is used to perform the estimation of friction and inertia
% values for the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation on the blackbox model or the real
% model


B_eq = 2.5663e-6;
tau_sf = 0.013;

% Initialization for plotting
plt.xfill = zeros(4*sIn.acc_cycles*2,1);
plt.yfill = zeros(4*sIn.acc_cycles*2,1);

a_avrg = zeros(sIn.acc_cycles*2,1);
tau_i_avrg = zeros(sIn.acc_cycles*2,1);

for i=1:sIn.acc_cycles*2
    
    lp.t_start = (i-1)*sIn.acc_step_time+0.2;
    lp.t_stop = (i)*sIn.acc_step_time-0.2;

    idx.steps = (out_a_motor.time <= lp.t_stop) .* ...
                (out_a_motor.time >= lp.t_start);



    a_mot_int = timeseries(out_a_motor.signals.values(find(idx.steps)),...
                           out_a_motor.time(find(idx.steps)));
    
    tau_f = B_eq*out_omega_motor.signals.values(find(idx.steps)) +...
            tau_sf/gbox.N * sign(out_omega_motor.signals.values(find(idx.steps)));

    tau_i = out_i_a.signals.values(find(idx.steps))*mot.Kt - tau_f;

    tau_i_int = timeseries(tau_i,...
                           out_i_a.time(find(idx.steps)));


    a_avrg(i) = ts_weighted_mean(a_mot_int);
    tau_i_avrg(i) = ts_weighted_mean(tau_i_int);


    %plt.xfill(lp.t_start:lp.t_stop) = [[1 1]*lp.t_start, [1 1]*lp.t_stop];
    %plt.yfill(lp.t_start:lp.t_stop) = [0,1,1,0];
end



%% Plotting
tau_f_whole = B_eq*out_omega_motor.signals.values +...
            tau_sf/gbox.N * sign(out_omega_motor.signals.values);

tau_i_whole = out_i_a.signals.values(find(idx.steps))*mot.Kt - tau_f;

tau_i_whole_struct.signals.values = tau_i_whole;
tau_i_whole_struct.time = out_i_a.time;



% Measurements with mean values over time
%plt.f1 = plot_meas(out_a_motor, a_avrg, 1, sIn, plt, "a");
%plt.f2 = plot_meas(tau_i_whole_struct, tau_i_avrg, 2, sIn, plt, "\tau");

J_eq = 0;
for i=1:2:10
    runnning_sum = (tau_i_avrg(i)-tau_i_avrg(i+1))/(a_avrg(i)-a_avrg(i+1));
    J_eq = J_eq+runnning_sum;
end
J_eq = J_eq/10



%% Functions Used
function [weighted_mean] = ts_weighted_mean(ts)
    % Computes the weighted mean of a timeseries over an interval.
    % ts - timeseriesobject, may be of variable step size

    % Select the data in the considered inteval
    time_int = ts.Time;
    data_int = ts.Data;

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

    ts = timeseries(ts.signals.values, ts.time);
    
    

    % Trail time
    sim_time = (0:sIn.acc_cycles*2)*sIn.acc_step_time;

    f = figure(fig);
    hold on
    % Highlighted areas
    %fill(plt.xfill, plt.yfill*lim, [0.9 0.9 0.9], 'EdgeColor', 'none', 'FaceAlpha', 0.5)
    plot(ts/1000, 'LineWidth', 1)
    stairs(sim_time, [means; means(end)]/1000,'LineWidth', 1)
    hold off
    legend("Averaging Interval", "Measured", "Averaged")
    xlabel("Time [s]")
    ylabel(ylab)
    %y-limits depending on positive or negative trail
    ylim([min(ts.Data) max(ts.Data)])
    grid on
end
