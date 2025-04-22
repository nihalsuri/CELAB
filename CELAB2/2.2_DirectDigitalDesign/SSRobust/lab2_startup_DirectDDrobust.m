% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. In both cases state-space feedback
% is used. 
clear
%% Load Predefined Parameters
load_params_inertial_case

%% User Inputs
% Define the sampler times for the controler and observer 
sIn.T_s = 1e-3; %1ms 
sIn.T_s2 = 1e-2; %10ms
sIn.T_s3 = 5e-2; %50ms
% Solver step time (0.1 ms)
sIn.step_size = 1e-4;

% Actual Parameters (estimated from Motor 1)
mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
mld.tausf = 0.013;      % [Nm]
mld.Jeq = 3.4640e-07;   % [kg m^2]

%% Plant Parameters
% reduced plant transfer function
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));

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
eigP.values =  [eigP.real + 1i*eigP.img, ...
                eigP.real - 1i*eigP.img, ...
                eigP.real];

% Desired eigenvalues for nominal tracking discretized 
eigP.values_d=exp(sIn.T_s*eigP.values); 

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
    % Discretize system
    sys_d = c2d(plant_c, T_s, "zoh");

    % Augmented matrices
    phi_e = [1, sys_d.C; 
             zeros(2,1), sys_d.A];
    gamma_e = [0;
               sys_d.B];

    % Discrete desired poles
    eig_d = exp(T_s * eigP.values);

    % Feedback gain (pole placement)
    K_e = place(phi_e, gamma_e, eig_d);

    % Separate feedback
    feedback_out.Ki = K_e(1);
    feedback_out.K  = K_e(2:end);

    % Feedforward gains
    gains = ([sys_d.A - eye(2), sys_d.B; sys_d.C, sys_d.D]) \ [0; 0; 1];
    feedback_out.Nx = gains(1:2);
    feedback_out.Nu = gains(3);

    %% Reduced observer
    %Calculate the eigenvalue for the observer  
    eigs_obs = exp(-eigP.damping * 5 * eigP.wn * T_s);
    %Calculate the observer gains 
    obs_out.L = place(sys_d.A(2,2), sys_d.A(1,2), eigs_obs);
    %Calcualte the observer matrices 
    obs_out.phi0  = sys_d.A(2,2) - obs_out.L * sys_d.A(1,2);
    obs_out.gamma0 = [sys_d.B(2) - obs_out.L * sys_d.B(1), ...
              obs_out.phi0  * obs_out.L + sys_d.A(2,1) - obs_out.L * sys_d.A(1,1)];
    obs_out.H0 = [0; 1];
    obs_out.J0 = [0 1; 0 obs_out.L];
end
