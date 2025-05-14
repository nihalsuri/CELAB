% Matlab script to start the Simulink simulation of an accurate model of 
% the Quanser SRV-02 + NI DAQ with a resonant load and a position state-
% space controller with chosen eigenvalues.
clear

%% Load Predefined Parameters
load_params_resonant_case

sIn.motor_or_blackbox_params = 1;   % 0: motor;  1: blackbox
load_params_model

% Time for averaging the bias of displacement sensor
sIn.t0 = 0.2;
sIn.t1 = 0.7;


%% Simulation Parameters 

% Solver step time (0.1 ms)
sIn.solver_time = 1e-4;

% List of reference positions [s]
sIn.position = [0, 50]; 

% Time the reference positions are held [s]
sIn.step_time = 3; 

% Automatic calculation of total simulation time [s]
sIn.simulation_time = sIn.step_time*length(sIn.position);

%% PID Controller to test simulink model against blackbox 

%PID = computePIDGains(8, 0.15, 0.1, plant.Ps, "PID");
PID.Kp = 5.845;
PID.Kd = 0.3;
PID.Ki = 0.2;
PID.Tl = 9.7252e-04;

% Anit Windup
PID.t_s5 = 0.85; % 5% settling time 
PID.Kw = 1/(PID.t_s5/5); % anit windup gain: 1/Tw, Tw=t_s5/5


