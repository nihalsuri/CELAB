% This script is used to evaluate the step response for different setpoints
% based on the simulation of the Quanser SRV-02 + NI DAQ. 
% It is to be run after the simulation on the blackbox model or the real
% model.


% Name of the output variable
sOut = ScopeData;

% Port of the scope to analyze (1 for selfmade; 2 for blackbox)
sOut.inport = 2;



sInfo = stepinfo(sOut.signals(sOut.inport).values, ...
                   sOut.time, sIn.position, 'SettlingTimeThreshold', 0.05);
Mp  = sInfo(1).Overshoot;
ts5 = sInfo(1).SettlingTime -sIn.t1;
tr  = sInfo(1).RiseTime;

% Output of the transient parameters
fprintf("Overshoot: Mp=%2.2f;  SettlingTime: t_s5=%.3f; risteTime t_r,=%.3f\n",Mp,ts5,tr)

