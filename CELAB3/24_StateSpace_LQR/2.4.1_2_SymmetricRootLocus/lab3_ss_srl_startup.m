% Matlab script to start the Simulink simulation of an accurate model of 
% the Quanser SRV-02 + NI DAQ with a resonant load and a position state-
% space controller with chosen eigenvalues.
clear



%% Load Predefined Parameters
load_params_resonant_case

sIn.motor_or_nominal = 0;   % 0: motor;  1: nominal
load_params_model


%% User Inputs

% The choice of r should satisfy the following specs mentioned below: 
% Desired specifications
% Overshoot
specs.mp = 0.3; % [30%] 
% Settling Time
specs.settling_time = 0.5; % [s]



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


%% State-Space Model
% with the state x=[theta_h, theta_d, omega_h, omega_d]
tmp.v1 = 1 /(gbox.N^2 * mld.Jeq);
tmp.v2 = (mld.Beq + mot.Kt*mot.Ke/mot.Req) /mld.Jeq;
tmp.v3 = mot.Kt*drv.dcgain /gbox.N /mld.Jeq / mot.Req;

% eqn 53 handout
plant.A = [zeros(2,2),    eye(2,2);
      0,  mld.k*tmp.v1, -tmp.v2, 0;
      0, -mld.k/mld.Jb-mld.k*tmp.v1, tmp.v2-mld.Bb/mld.Jb, -mld.Bb/mld.Jb];

% eqn 54 handout
plant.B = [0;0; tmp.v3; -tmp.v3];

plant.C = [1,0,0,0];
plant.D = 0;


%% Feedback Controller Design using Symmetric Root Locus
% % % Desired dynamic parameters for approximation
eigP.damping = log(1/specs.mp) / sqrt(pi^2 + log(1/specs.mp)^2);
eigP.wn = 3/(eigP.damping*specs.settling_time);

% Phase of eigenvalues
eigP.phi = atan2(sqrt(1-eigP.damping^2), eigP.damping);

% Desired eigenvalues for nominal tracking
eigP.values = eigP.wn*exp(1i*[-pi+eigP.phi,-pi+eigP.phi/2]);
eigP.values = [eigP.values, conj(eigP.values)];

% LTI objects of the plant for sketching of the locus
plant.sysG = ss(plant.A,plant.B,plant.C,0);
plant.sysGp = ss(-plant.A,-plant.B,plant.C,0);

% Plotting the symmetric root locus of the system
figure;
rlocus(plant.sysG*plant.sysGp);
hold on;

% Add settling time constraint (vertical line)
xline(-(3/specs.settling_time), 'k--', 'LineWidth', 2);
hold on; 
% Add overshoot constraint (radial lines)
length = 1000; % Length of the constraint lines

% Calculate endpoints of lines at the specified angle
x_end = length * cos(eigP.phi + pi);
y_end_pos = length * sin(eigP.phi + pi);
y_end_neg = -length * sin(eigP.phi + pi);

% Plot the two radial lines (positive and negative imaginary)
plot([0, x_end], [0, y_end_pos], 'g--', 'LineWidth', 2);
plot([0, x_end], [0, y_end_neg], 'g--', 'LineWidth', 2);

% Add legend and improve plot appearance
legend('Root Locus','Settling Time Constraint', 'Overshoot Constraint');
grid on;
title('Symmetric Root Locus with Design Specifications');

%value obtained from visually examining the rlocus plot 
feedback.r = 1/3.53e+03;
feedback.K = lqry(plant.sysG, 1, feedback.r);

% State feedforward gain and input feedforward gain
feedback.gains = ([plant.A, plant.B; plant.C, plant.D])\[zeros(4,1);1];
feedback.Nx = feedback.gains(1:end-1);
feedback.Nu = feedback.gains(end);


%% Simple Observer
filt.wc = 2*pi*50;
filt.del = 1/sqrt(2);
filt.num = [filt.wc^2, 0];
filt.den = [1, 2*filt.del*filt.wc, filt.wc^2];

%% Evaluation script to check if specs match
sim('lab3_ss_srl')
evalLQR