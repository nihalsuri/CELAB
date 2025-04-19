% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. In both cases state-space feedback
% is used. 
clear



%% Load Predefined Parameters
load_params_inertial_case



%% User Inputs

% Define the time and output values
sIn.T_s = 1e-3; %1ms 
sIn.T_s2 = 1e-2; %10ms
sIn.T_s3 = 5e-2; %50ms

% Solver step time (0.1 ms)
sIn.step_size = 1e-4;


% Motor Parameters
% Nominal Parameters (estimated from Blackbox)
%mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
%mld.tausf = 0.0056;     % [Nm]
%mld.Jeq = mld.Jeq;      % [kg m^2]

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
eigP.values =  [eigP.real + 1i*eigP.img, ...
                     eigP.real - 1i*eigP.img, ...
                     eigP.real];

% Desired eigenvalues for nominal tracking discretized 
eigP.values_d=exp(sIn.T_s*eigP.values); 

% Plant's A, B, C, D matrix 
plant.A = [0 1; 0 -(1/plant.Tm)];
plant.B = [0 ;  plant.km/(gbox.N*plant.Tm)]; 
plant.C = [1 0];
plant.D = 0;

% Continous system 
plant.sys_c = ss(plant.A, plant.B, plant.C, plant.D); 

%% Calculating control values for 1st sampling time
%Descretised system 
plant.sys_d = c2d(plant.sys_c,sIn.T_s,"zoh"); 

%Augmented system for robust tracking 
obs.phi_e =[1, plant.sys_d.C; 
            zeros(2,1) plant.sys_d.A] ;
obs.gamma_e = [0;
              plant.sys_d.B]; 

% calculation of feedback via acker
feedback.K_e= acker(obs.phi_e, obs.gamma_e, eigP.values_d);
feedback.Ki = feedback.K_e(1);
feedback.K  = feedback.K_e(2:end);


% calculation of Nx(state feedforward gain), Nu (input feedforward gain)
plant.gains = ([plant.sys_d.A-eye(2), plant.sys_d.B; plant.sys_d.C, plant.sys_d.D])\[0;0;1];
feedback.Nx = plant.gains(1:2);
feedback.Nu = plant.gains(3);


%% Reduced Observer Model
obs.eigs = exp(-eigP.damping*5*eigP.wn*sIn.T_s);
obs.L = acker(plant.sys_d.A(2,2),plant.sys_d.A(1,2),obs.eigs);

obs.phi0 = plant.sys_d.A(2,2)-obs.L*plant.sys_d.A(1,2);
obs.gamma0 = [plant.sys_d.B(2)-obs.L*plant.sys_d.B(1) ...
             obs.phi0*obs.L+plant.sys_d.A(2,1)-obs.L*plant.sys_d.A(1,1)]; 
obs.H0 = [0 ; 1]; 
obs.J0 = [0 1
         0 obs.L;];


%% Calculating control values for 2nd sampling time

% Desired eigenvalues for nominal tracking discretized 
eigP.values_d2=exp(sIn.T_s2*eigP.values); 

%Descretised system 
plant.sys_d2 = c2d(plant.sys_c,sIn.T_s2,"zoh"); 

%Augmented system for robust tracking 
obs.phi_e2 =[1, plant.sys_d2.C; 
            zeros(2,1) plant.sys_d2.A] ;
obs.gamma_e2 = [0;
              plant.sys_d2.B]; 

% calculation of feedback via acker
feedback.K_e2= acker(obs.phi_e2, obs.gamma_e2, eigP.values_d2);
feedback.Ki2 = feedback.K_e2(1);
feedback.K2  = feedback.K_e2(2:end);


% calculation of Nx(state feedforward gain), Nu (input feedforward gain)
plant.gains2 = ([plant.sys_d2.A-eye(2), plant.sys_d2.B; plant.sys_d2.C, plant.sys_d2.D])\[0;0;1];
feedback.Nx2 = plant.gains2(1:2);
feedback.Nu2 = plant.gains2(3);


% Reduced Observer Model
obs.eigs2 = exp(-eigP.damping*5*eigP.wn*sIn.T_s2);
obs.L2 = acker(plant.sys_d2.A(2,2),plant.sys_d2.A(1,2),obs.eigs2);

obs.phi02 = plant.sys_d2.A(2,2)-obs.L2*plant.sys_d2.A(1,2);
obs.gamma02 = [plant.sys_d2.B(2)-obs.L2*plant.sys_d2.B(1) ...
             obs.phi0*obs.L2+plant.sys_d2.A(2,1)-obs.L2*plant.sys_d2.A(1,1)]; 
obs.H02 = [0 ; 1]; 
obs.J02 = [0 1
         0 obs.L2;];


%% Calculating control values for 3rd sampling time

% Desired eigenvalues for nominal tracking discretized 
eigP.values_d3=exp(sIn.T_s3*eigP.values); 

%Descretised system 
plant.sys_d3 = c2d(plant.sys_c,sIn.T_s3,"zoh"); 

%Augmented system for robust tracking 
obs.phi_e3 =[1, plant.sys_d3.C; 
            zeros(2,1) plant.sys_d3.A] ;
obs.gamma_e3 = [0;
              plant.sys_d3.B]; 

% calculation of feedback via acker
feedback.K_e3= acker(obs.phi_e3, obs.gamma_e3, eigP.values_d3);
feedback.Ki3 = feedback.K_e3(1);
feedback.K3  = feedback.K_e3(2:end);


% calculation of Nx(state feedforward gain), Nu (input feedforward gain)
plant.gains = ([plant.sys_d3.A-eye(2), plant.sys_d3.B; plant.sys_d3.C, plant.sys_d3.D])\[0;0;1];
feedback.Nx3 = plant.gains(1:2);
feedback.Nu3 = plant.gains(3);


% Reduced Observer Model
obs.eigs3 = exp(-eigP.damping*5*eigP.wn*sIn.T_s3);
obs.L3 = acker(plant.sys_d3.A(2,2),plant.sys_d3.A(1,2),obs.eigs3);

obs.phi03 = plant.sys_d3.A(2,2)-obs.L3*plant.sys_d3.A(1,2);
obs.gamma03 = [plant.sys_d3.B(2)-obs.L3*plant.sys_d3.B(1) ...
             obs.phi0*obs.L3+plant.sys_d3.A(2,1)-obs.L3*plant.sys_d3.A(1,1)]; 
obs.H03 = [0 ; 1]; 
obs.J03 = [0 1
         0 obs.L3;];
