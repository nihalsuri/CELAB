% Startup file for loading all parameters for the "CEL_Lab0_Simulink.slx"
% Simulink file. It loads the parameters for the dynamic system and 
% computes the gains for the PID controller.
clear

%% Load the parameters 
load_params_inertial_case


%% Input of friction parameters
mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
mld.tausf = 0.0056;     % [Nm]


%% Definition of PID reduced plant
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));

plant.Ps = tf(plant.km, [(gbox.N*plant.Tm) gbox.N 0]); 


%% PID gains
PID = computePIDGains(8, 0.15, 0.1, plant.Ps, "PID"); %Compute the PID parameters 
PID.i_saturation = 5000;  %Min and max value for the I 

% Manual PID tuning 
PID.Kp = 8.7; 
PID.Ki = 77.9; 
PID.Kd = 0.12; 






