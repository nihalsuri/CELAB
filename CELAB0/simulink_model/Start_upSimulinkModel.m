% Startup file for loading all parameters for the "CEL_Lab0_Simulink.slx"
% Simulink file. It loads the parameters for the dynamic system and 
% computes the gains for the PID controller.
clear

%% Load the parameters 
load_params_inertial_case


%% Input of friction parameters
mld.Beq = 0.0;
mld.tausf = 0.0056;


%% Definition of PID reduced plant
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));

plant.Ps = tf(plant.km, [(gbox.N*plant.Tm) gbox.N 0]); 


%% PID gains
gains = computePIDGains(8, 0.15, 0.1, plant.Ps, "PID");
k_p = gains.Kp;
k_i = gains.Ki;
k_d = gains.Kd;
T_l = gains.Tl;
%change simulink so that the gains dont need to be reassigned?
%i.e. reference the struct in simulink

i_saturation = 5;
%{
k_p = 10; 
k_i = 2; 
k_d = 0; 
T_l = 0.001;
%}

