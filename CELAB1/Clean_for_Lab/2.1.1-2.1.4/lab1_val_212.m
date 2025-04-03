% This script is used to evaluate the step response for one step with
% multiple signals (i.e. comparison between models or controllers)


% Name of the output variable
sOut = betterpid_theta_l;

% Port of the scope to analyze (1 for nominal; 2 for integral)
sOut.inport = 2;



sInfo = stepinfo(sOut.signals(sOut.inport).values, ...
                   sOut.time, windup.mag, 'SettlingTimeThreshold', 0.05);
Mp  = sInfo.Overshoot;
ts5 = sInfo.SettlingTime;
tr  = sInfo.RiseTime;

% Output of the transient parameters
fprintf("Refference: %d deg\n",windup.mag)
fprintf("Overshoot: Mp=%2.2f;  SettlingTime: t_s5=%.3f;  RiseTime: tr=%.3f\n",Mp,ts5,tr)
