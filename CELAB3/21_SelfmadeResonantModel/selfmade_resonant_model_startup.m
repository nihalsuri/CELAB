% Matlab script to start the Simulink simulation of an accurate model of 
% the Quanser SRV-02 + NI DAQ with a resonant load and a position state-
% space controller with chosen eigenvalues.
clear



%% Load Predefined Parameters
load_params_resonant_case


%% User Inputs

% Actual parameters (estimated from motor 1, lab 0)
mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
mld.tausf = 0.013;      % [Nm]

% Resonant load nominal parameters
% Hub friction coeff
mld.Bb = 3.4e-3;       % [Nm/(rad/s)]
% Joint stiffness 
mld.K = 0.83;          % [Nm/rad]


%% Simulation Parameters 

% Solver step time (0.1 ms)
sIn.solver_time = 1e-4;

% List of reference positions [s]
sIn.position = [40, 0]; 

% Time the reference positions are held [s]
sIn.step_time = 5; 

% Automatic calculation of total simulation time [s]
sIn.simulation_time = sIn.step_time*length(sIn.position);
