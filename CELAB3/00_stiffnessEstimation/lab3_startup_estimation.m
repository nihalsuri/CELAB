% Matlab script to start the Simulink simulation of an accurate model of 
% the Quanser SRV-02 + NI DAQ with a resonant load and estimate the joint 
% parameters
clear



%% Load Predefined Parameters
load_params_resonant_case



%% User Inputs

% Actual parameters (estimated from motor 1, lab 0)
mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
mld.tausf = 0.013;      % [Nm]

% Parameters form lab0 blackbox
mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
mld.tausf = 0.0056;     % [Nm]


%% Simulation Parameters 

% Solver step time (0.1 ms)
sIn.solver_time = 1e-4;

% List of reference positions [s]
sIn.position = 50; 

% Time the reference positions are held [s]
sIn.step_time = 10; 

% Automatic calculation of total simulation time [s]
sIn.simulation_time = sIn.step_time*length(sIn.position);

% Time for averaging the bias of displacement sensor
sIn.t0 = 0.2;
sIn.t1 = 0.7;

%% Measurements
time = [0, 0.126, 0.253, 0.379, 0.505, 0.632, 0.754, 0.882, 1.009];
peaks = [10, 8.132, 6.602, 5.061, 4.029, 2.986, 2.140, 1.326, 0.6667];

