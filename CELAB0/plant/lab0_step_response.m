% This script is used to evaluate the step response for different setpoints
% based on the simulation of the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation on the blackbox model or the real
% model.



% Output the PID-parameters used
disp("PID-Parmeters used:")
disp("Kp="+num2str(PID.Kp) + ";  Ki="+num2str(PID.Ki)+ ...
     ";  Kd="+num2str(PID.Kd) + ";  Tl="+num2str(PID.Tl))
disp("-------------------------------------")

% Define the start and stoptimes of each step
tstp.starts = (0:sIn.num_resp-1)*2*sIn.length_steps;
tstp.ends = tstp.starts+sIn.length_steps;

% Assign only the pieces of the timeseries that correspond to steps to a
% struct
sOut = struct();
for i=1:(sIn.num_resp+1)/2
    % Indices corresponding to the i-th step
    idx.steps = (out.thi_l.Time <= tstp.ends(i)) .* ...
                (out.thi_l.Time >= tstp.starts(i));
    
    % dynamically grow the struct and assign the steps to different fields
    idx.field = sprintf('f%d',sIn.mag_steps(i));
    sOut.(idx.field).ts = getsamples(out.thi_l, find(idx.steps));
    sOut.(idx.field).info = stepinfo( ...
                       sOut.(idx.field).ts.Data, ...
                       sOut.(idx.field).ts.Time, ...
                       'SettlingTimeThreshold', 0.05);
    
    Mp  = sOut.(idx.field).info.Overshoot;
    ts5 = sOut.(idx.field).info.SettlingTime - tstp.starts(i);

    % Output of the transient parameters
    disp("Refference: "+num2str(sIn.mag_steps(i))+" deg")
    fprintf("Overshoot: Mp=%2.2f;  SettlingTime: t_s5=%.3f\n",Mp,ts5)
end