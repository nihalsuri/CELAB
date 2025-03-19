% This script is used to evaluate the step response for different setpoints
% based on the simulation of the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation on the blackbox model or the real
% model.



%% Data Preparation

% Define the start and stoptimes of each step
tstp.starts = (0:2:2*sIn.num_resp)*sIn.length_steps;
tstp.ends = tstp.starts+sIn.length_steps;

% Assign only the pieces of the timeseries that correspond to steps to a
% struct
sOut.step_resp = struct();
for i=1:sIn.num_resp
    % Indices corresponding to the i-th step
    idx.steps = (out.thi_l.Time <= tstp.ends(i)) .* ...
                  (out.thi_l.Time >= tstp.starts(i) );
    
    % dynamically grow the struct and assign the steps to different fields
    idx.field = sprintf('f%d',i);
    sOut.step_resp.(idx.field).ts = getsamples(out.thi_l, idx.steps);
    sOut.step_resp.(idx.field).info = stepinfo( ...
                       sOut.step_resp.(idx.field).ts.Data, ...
                       sOut.step_resp.(idx.field).ts.Time, ...
                       'SettlingTimeThreshold', 0.05);
end

