% This script is used to evaluate the step response for different setpoints
% based on the simulation of the Quanser SRV-02 + NI DAQ. 
% There need to be two data ports connected to the scope. 
% In the 1st position is the original one, in the 2nd the improoved

clear sOut
% Name of the output sequence to be analyzed
sOut = thi_l;

%Stepinfo
sOut.orig = stepinfo(sOut.signals(1).values, sOut.time, ...
    'SettlingTimeThreshold', 0.05);
sOut.modif = stepinfo(sOut.signals(2).values, sOut.time, ...
    'SettlingTimeThreshold', 0.05);


% Output the PID-parameters used
disp("PID-Parmeters used:")
disp("Kp="+num2str(PID.Kp) + ";  Ki="+num2str(PID.Ki)+ ...
     ";  Kd="+num2str(PID.Kd) + ";  Tl="+num2str(PID.Tl)...
     + ";  Kw="+num2str(PID.Kw))
disp("Refference: "+num2str(windup.mag)+" deg")
disp("-------------------------------------")

% Output of the transient parameters
disp("Controller without Modification")
fprintf("Overshoot: Mp=%2.2f;  SettlingTime: t_s5=%.3f\n", ...
    sOut.orig.Overshoot,sOut.orig.SettlingTime)

disp("Controller without Modification")
fprintf("Overshoot: Mp=%2.2f;  SettlingTime: t_s5=%.3f\n", ...
    sOut.modif.Overshoot,sOut.modif.SettlingTime)
