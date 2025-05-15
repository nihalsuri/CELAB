% Matlab script to start the Simulink simulation of an accurate model of 
% the Quanser SRV-02 + NI DAQ with a resonant load and a position state-
% space controller with chosen eigenvalues.
clear


%% Load Predefined Parameters
load_params_resonant_case

sIn.motor_or_nominal = 0;   % 0: motor;  1: blackbox
load_params_model


%% User Inputs
% Normal PID(1) or With Anti Windup(0)
sIn.AntiWindup = 0;
%PID-par Bode's method (0) or Selftuned (1) 
sIn.SelftunedPID = 0; 
% List of reference positions [s]
sIn.position =50; 

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
% Time the reference positions are held [s]
sIn.step_time = 3; 
% Automatic calculation of total simulation time [s]
sIn.simulation_time = sIn.step_time*length(sIn.position);
% Time for averaging the bias of displacement sensor
sIn.t0 = 0.2;
sIn.t1 = 0.3;

%% State-Space Model
% with the state x=[theta_h, theta_d, omega_h, omega_d]
tmp.v1 = 1 /(gbox.N^2 * mld.Jeq);
tmp.v2 = (mld.Beq + mot.Kt*mot.Ke/mot.Req) /mld.Jeq;
tmp.v3 = mot.Kt*drv.dcgain /gbox.N /mld.Jeq / mot.Req;

plant.A = [zeros(2,2),    eye(2,2);
      0,  mld.k*tmp.v1, -tmp.v2, 0;
      0, -mld.k/mld.Jb-mld.k*tmp.v1, tmp.v2-mld.Bb/mld.Jb, -mld.Bb/mld.Jb];
plant.B = [0;0; tmp.v3; -tmp.v3];
plant.C = [1,0,0,0];
plant.D = 0;

sys = ss(plant.A, plant.B, plant.C, plant.D); 

%% Computing PID gains 
%Compute PID with Bode's method
PID = computePIDGains(4, specs.settling_time, specs.mp, tf(sys), "PID");
PID.Kw = 1/(specs.settling_time/5); % anit windup gain: 1/Tw, Tw=t_s5/5

%Use tuned PID parameters 
if ( sIn.SelftunedPID>0)
PID.Kp = 7.5; 
PID.Ki = 28; 
PID.Kd = 2;
end

%Use tuned PID parameters 
if ( sIn.SelftunedPID>0) && (sIn.AntiWindup==0)
    PID.Kp = 2; 
    PID.Ki = 3; 
    PID.Kd = 5;
end

%%Run simulation and evaluate the results 
set_param('lab3_PID', 'AlgebraicLoopMsg', 'none');
simOut = sim('lab3_PID');
evalPID

