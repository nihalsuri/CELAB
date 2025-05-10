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

% Desired specifications
% Overshoot
specs.mp = 0.3; % [30%] 
% Settling Time
specs.settling_time = 0.85; % [s]



%% Simulation Parameters 

% Solver step time (0.1 ms)
sIn.solver_time = 1e-4;

% List of reference positions [s]
sIn.position = [40, 0, 70, 0, 120]; 

% Time the reference positions are held [s]
sIn.step_time = 5; 

% Automatic calculation of total simulation time [s]
sIn.simulation_time = sIn.step_time*length(sIn.position);


%% State-Space Model
% with the state x=[theta_h, theta_d, omega_h, omega_d]

tmp.v1 = 1 /gbox.N^2 /mld.Jeq;
tmp.v2 = (mld.Beq + mot.Kt*mot.Ke) /mld.Jeq;
tmp.v3 = mot.Kt*drv.dcgain /gbox.N /mld.Jeq / mot.Req;

plant.A = [zeros(2,2),    eye(2,2);
      0,  mld.k*tmp.v1, -tmp.v2, 0;
      0, -mld.k/mld.Jb-mld.k*tmp.v1, tmp.v2-mld.Bb/mld.Jb, -mld.Bb/mld.Jb];

plant.B = [0;0; tmp.v3; -tmp.v3];

plant.Bd = [0;0; -tmp.v1; tmp.v1];


%% Feedback Controller Design
% Desired dynamic parameters for approximation
eigP.damping = log(1/specs.mp) / sqrt(pi^2 + log(1/specs.mp)^2); 
eigP.wn = 3/(eigP.damping*specs.settling_time);

% Phase of eigenvalues
eigP.phi = atan2(sqrt(1-eigP.damping^2), eigP.damping);

% Desired eigenvalues for nominal tracking
eigP.values = eigP.wn*exp(1i*[-pi+eigP.phi, -pi-eigP.phi, ...
                              -pi+eigP.phi/2, -pi-eigP.phi/2]);

% State feedback matrix
feedback.K = acker(plant.A, plant.B, eigP.values);


%{
% State feedforward gain and input feedforward gain
feedback.gains = ([plant.A, plant.B; plant.C, plant.D])\[0;0;1];
feedback.Nx = feedback.gains(1:2);
feedback.Nu = feedback.gains(3);

% Eigenvalues for robust tracking
eig.robustValues = [eig.real + 1i*eig.img, ...
                     eig.real - 1i*eig.img, ...
                     eig.real];

% State feedback matrix frot the robust case
feedback.robustKe = acker(plant.Ae, plant.Be, eig.robustValues);
feedback.robustKi = feedback.robustKe(1);
feedback.robustK  = feedback.robustKe(2:end);
%}

%% Simple Observer
filt.wc = 2*pi*50;
filt.del = 1/sqrt(2);
filt.num = [filt.wc^2, 0];
filt.den = [1, 2*filt.del*filt.wc, filt.wc^2];