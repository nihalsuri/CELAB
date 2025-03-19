% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. In both cases a PID controller is 
% used, the parameters can be calculated based of a reduced model or 
% manually set.
clear



%% Load Predefined Parameters
load_params_inertial_case



%% User Inputs

% PID-Tuning -> Step Input
% magnitude of reference step in [deg]
sIn.mag_step = 5;
% use step input? -> [y=1] / [n=0] (only effect on sim. time => y->10s)
sIn.pid = 1;


% Friction Estimation -> Stepwise Constant Angular Velocity
% time of steps/increments in seconds
sIn.step_time = 5;
% number of steps
sIn.step_number = 9;
% load reference velocities in rpm
sIn.step_omega = 50;



%% PID Parameters
% viscous and static friction parameters
mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
mld.tausf = 0.0056;     % [Nm]

% reduced plant transfer function
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Ps = tf(plant.km, [(gbox.N*plant.Tm) gbox.N 0]); 

% resulting gains from bode method
PID = computePIDGains(8, 0.15, 0.1, plant.Ps, "PID");
PID.i_saturation = 5000;  %saturation on integral part

% Manual PID tuning Nihal
%  10 deg => Mp = 0.00%, t_s5% = 0.544s
%  30 deg => Mp = 0.00%, t_s5% = 0.240s
%  90 deg => Mp = 0.00%, t_s5% = 0.208s
% 180 deg => Mp = 0.10%, t_s5% = 0.212s
% 360 deg => Mp = 0.15%, t_s5% = 0.237s
%PID.Kp = 24; 
%PID.Ki = 0.43; 
%PID.Kd = 1.0; 


% Manual PID tuning Max 
%  10 deg => Mp = 9.80%, t_s5% = 0.039s
%  30 deg => Mp = 8.60%, t_s5% = 0.048s
%  90 deg => Mp = 7.60%, t_s5% = 0.076s
% 180 deg => Mp = 7.40%, t_s5% = 0.115s
% 360 deg => Mp = 8.00%, t_s5% = 0.394s
PID.Kp = 90; 
PID.Ki = 60; 
PID.Kd = 0.40; 





%% Filter Parameters for Friction Estimation
% Butterworth high-pass for differentiating measured position
filt.butt.omega_c = 2*pi*20;
filt.butt.delta =1/sqrt(2);
filt.butt.num = [filt.butt.omega_c^2, 0];
filt.butt.den = [1, 2*filt.butt.delta*filt.butt.omega_c, filt.butt.omega_c^2];

% Low-pass noise reduction on current
filt.low.omega_ci = 2*pi*20;
filt.low.delta_i = 1/sqrt(2);
filt.low.num = filt.low.omega_ci^2;
filt.low.den = [1, 2*filt.low.delta_i*filt.low.omega_ci, filt.low.omega_ci^2];



%% Simulation Parameters from User Input
% total simulation time
%sIn.t_sim = sIn.step_time*sIn.step_number;      %only positive trai
sIn.t_sim = sIn.step_time*(sIn.step_number*2+1); %pos and neg trail

% staircase of reference velocities
sIn.omega_l = (1:sIn.step_number)*sIn.step_omega;   %only positive trail
sIn.omega_l = [sIn.omega_l, 0, -1*sIn.omega_l];     %pos and neg trail 

% check if pid or param_est
sIn.t_sim = 10*sIn.pid + sIn.t_sim*(1-sIn.pid);
