% This script is used to evaluate the step response for different setpoints
% based on the simulation of the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation on the blackbox model or the real
% model.


% Name of the output variable
sOut = out_th_l;

% Port of the scope to analyze (1 for nominal; 2 for integral)
sOut.inport = 2;


% extract only the step values from the input sequence
sIn.mag = sIn.position(find(ismember(sIn.position,0).*(-1)+1));

% Define the start and stoptimes of each step
idx.t_starts = (0:sIn.num-3)*2*sIn.sample_time + sIn.sample_time;
idx.t_ends = idx.t_starts+sIn.sample_time;

% Assign only the pieces of the timeseries that correspond to steps to a
% struct
for i=1:(sIn.num-1)/2
    % Indices corresponding to the i-th step
    idx.steps = (sOut.time <= idx.t_ends(i)) .* ...
                (sOut.time >= idx.t_starts(i));
    
    % dynamically grow the struct and assign the steps to different fields
    idx.field = sprintf('f%d',sIn.mag(i));
    sOut.(idx.field).time = sOut.time(find(idx.steps));
    sOut.(idx.field).data = sOut.signals(sOut.inport).values(find(idx.steps));
    sOut.(idx.field).info = stepinfo(sOut.(idx.field).data, ...
                     sOut.(idx.field).time, 'SettlingTimeThreshold', 0.05);
    
    Mp  = sOut.(idx.field).info.Overshoot;
    ts5 = sOut.(idx.field).info.SettlingTime - idx.t_starts(i);

    % Output of the transient parameters
    disp("Refference: "+num2str(sIn.mag(i))+" deg")
    fprintf("Overshoot: Mp=%2.2f;  SettlingTime: t_s5=%.3f\n",Mp,ts5)
end