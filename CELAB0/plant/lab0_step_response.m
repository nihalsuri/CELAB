% This script is used to evaluate the step response for different setpoints
% based on the simulation of the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation on the blackbox model or the real
% model.

%

% Output the PID-parameters used
disp("PID-Parmeters used:")
disp("Kp="+num2str(PID.Kp) + ";  Ki="+num2str(PID.Ki)+ ...
     ";  Kd="+num2str(PID.Kd) + ";  Tl="+num2str(PID.Tl))
disp("-------------------------------------")

% Define the start and stoptimes of each step
idx.t_starts = (0:step_resp.num-1)*2*step_resp.time;
idx.t_ends = idx.t_starts+step_resp.time;

% Assign only the pieces of the timeseries that correspond to steps to a
% struct
sOut = struct();
for i=1:(step_resp.num+1)/2
    % Indices corresponding to the i-th step
    idx.steps = (out_thi_l.time <= idx.t_ends(i)) .* ...
                (out_thi_l.time >= idx.t_starts(i));
    
    % dynamically grow the struct and assign the steps to different fields
    idx.field = sprintf('f%d',step_resp.mag(i));
    sOut.(idx.field).time = out_thi_l.time(find(idx.steps));
    sOut.(idx.field).data = out_thi_l.signals.values(find(idx.steps));
    sOut.(idx.field).info = stepinfo(sOut.(idx.field).data, ...
                     sOut.(idx.field).time, 'SettlingTimeThreshold', 0.05);
    
    Mp  = sOut.(idx.field).info.Overshoot;
    ts5 = sOut.(idx.field).info.SettlingTime - idx.t_starts(i);

    % Output of the transient parameters
    disp("Refference: "+num2str(step_resp.mag(i))+" deg")
    fprintf("Overshoot: Mp=%2.2f;  SettlingTime: t_s5=%.3f\n",Mp,ts5)
end