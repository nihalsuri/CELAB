% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. For discrete nominal tracking where
% you can choose 3 different sampling times for the controllers
clear
%% Load Predefined Parameters
load_params_inertial_case

%% User Inputs
%Define the sampler times for the controler and observer 
sIn.T_s = 1e-3; %1ms 
sIn.T_s2 = 1e-2; %10ms
sIn.T_s3 = 5e-2; %50ms

% Solver step time (0.1 ms)
sIn.step_size = 1e-4;

sIn.simulation_time = 5; 

% Actual Parameters (estimated from Motor 1)
mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
mld.tausf = 0.013;      % [Nm]
mld.Jeq = 3.4640e-07;   % [kg m^2]

%% Plant parameters Parameters

% reduced plant transfer function
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));

%% State feedback matrix calculation   
% High-pass filter (Continous - Time) for load velocity calculation
filt.high.omega_c = 2*pi*50; 
filt.high.delta = 1/sqrt(2);
filt.high.num = [filt.high.omega_c^2, 0];
filt.high.den = [1, 2*filt.high.delta*filt.high.omega_c, filt.high.omega_c^2];

%% Closed Loop Eigenvalues 
% Desired specifications
specs.mp = 0.1; 
specs.settling_time = 0.15; %[seconds]

% Damping ratio from maximum overshoot
eigP.damping = (log(1/specs.mp)) / (sqrt((pi^2) + (log(1/specs.mp)^2))); 

% Gain cut-off frequency from settling time, in [rad/s]
eigP.wn = 3/(eigP.damping*specs.settling_time);

% Real and imaginary parts
eigP.real = -eigP.damping*eigP.wn; 
eigP.img = eigP.wn * sqrt(1 - eigP.damping^2);

% Desired eigenvalues for nominal tracking
eigP.values = [eigP.real + 1i*eigP.img, eigP.real - 1i*eigP.img];

%% Creating a SS for the reduced system
% Plant's A, B, C, D matrix 
plant.A = [0 1; 0 -(1/plant.Tm)];
plant.B = [0 ;  plant.km/(gbox.N*plant.Tm)]; 
plant.C = [1 0];
plant.D = 0;
% Create a ss model 
plant.sys_c = ss(plant.A, plant.B, plant.C, plant.D); 

%% Calculate controler and observer gains 
%Calculate controler and observer gains for t_s= 0.001 
[feedback, obs] = calculate_controller(sIn.T_s, plant.sys_c, eigP);
%Calculate controler and observer gains for t_s = 0.01 
[feedback2, obs2] = calculate_controller(sIn.T_s2, plant.sys_c, eigP);
%Calculate controler and observer gains for t_s = 0.05 
[feedback3, obs3] = calculate_controller(sIn.T_s3, plant.sys_c, eigP);



function [feedback_out, obs_out] = calculate_controller(T_s, plant_c, eigP)
    %Descretised system 
    plant.sys_d = c2d(plant_c,T_s,"zoh"); 
    % Desired eigenvalues for nominal tracking discretized 
    eig_d = exp(T_s * eigP.values); 
    % calculation of feedback via acker
    feedback_out.K= acker(plant.sys_d.A, plant.sys_d.B, eig_d);
    
    % calculation of Nx(state feedforward gain), Nu (input feedforward gain)
    plant.gains = ([plant.sys_d.A-eye(2), plant.sys_d.B; plant.sys_d.C, plant.sys_d.D])\[0;0;1];
    feedback_out.Nx = plant.gains(1:2);
    feedback_out.Nu = plant.gains(3);
    
    %% Reduced Observer Model
    %Calculate the eigenvalue for the observer
    eigs = exp(-eigP.damping*5*eigP.wn*T_s);
    %Calculate the observer gains 
    obs_out.L = acker(plant.sys_d.A(2,2),plant.sys_d.A(1,2),eigs);
    %Calcualte the observer matrices
    obs_out.phi0 = plant.sys_d.A(2,2)-obs_out.L*plant.sys_d.A(1,2);
    obs_out.gamma0 = [plant.sys_d.B(2)-obs_out.L*plant.sys_d.B(1) ...
             obs_out.phi0*obs_out.L+plant.sys_d.A(2,1)-obs_out.L*plant.sys_d.A(1,1)]; 
    obs_out.H0 = [0 ; 1]; 
    obs_out.J0 = [0     1;
                  0 obs_out.L];
end



