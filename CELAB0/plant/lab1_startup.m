% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. In both cases a PID controller is 
% used, the parameters can be calculated based of a reduced model or 
% manually set.
clear



%% Load Predefined Parameters
load_params_inertial_case



%% User Inputs

% Motor Parameters
% Nominal Parameters (estimated from Blackbox)
mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
mld.tausf = 0.0056;     % [Nm]
mld.Jeq = mld.Jeq;          % [kg m^2]

% Actual Parameters (estimated from Motor 1)
mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
mld.tausf = 0.013;      % [Nm]
mld.Jeq = 3.4640e-07;     % [kg m^2]


% PID-Tuning
% magnitude of reference step in [deg]
step_resp.mag = [30,180,360,500];
% time for which each refference is applied [s]
step_resp.time = 5;


% Friction Estimation
% increment of steps for load angular velocity
frict_est.del_omega = 45;
% time for which each refference is applied [s]
frict_est.time = 5;
% number of increments
frict_est.num = 9;


% Inertia Estimation
% motor acceleration in [rpm/s]
inert_est.acc = 450;
% time for which acceleration is applied in one direction [s]
inert_est.time = 1;
% number of cycles (positive and negative acceleration)
inert_est.num = 10;


% Choice of Input => "Step"->1, "Beq"->2 or "Jeq"->3
sIn.program = 3;


%% PID Parameters

% reduced plant transfer function
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Ps = tf(plant.km, [(gbox.N*plant.Tm) gbox.N 0]); 

% resulting gains from bode method
%PID = computePIDGains(8, 0.15, 0.1, plant.Ps, "PID");
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
% PID-Tuning
step_resp.num = length(step_resp.mag)*2-1; %number of (steps + breaks)
step_resp.ref = zeros(1,step_resp.num);
step_resp.ref(1:2:end) = step_resp.mag;    %zeros between setpoints

% Friction Estimation
frict_est.ref = (1:frict_est.num)*frict_est.del_omega;
frict_est.ref = [frict_est.ref, 0, -1*frict_est.ref];

% Inertia Estimation
inert_est.ref = ones(2*inert_est.num,1);
inert_est.ref(2:2:end) = -1;
inert_est.ref = inert_est.ref*inert_est.acc/gbox.N;

% Total Simulation time
switch sIn.program
    case 1  %"Step"
        sIn.time = step_resp.time * step_resp.num;

    case 2  %"Beq"
        sIn.time = frict_est.time * (frict_est.num*2+1);

    case 3  %"Jeq"
        sIn.time = inert_est.time * inert_est.num*2;
end


