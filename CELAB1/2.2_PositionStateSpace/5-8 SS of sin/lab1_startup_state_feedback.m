% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. In both cases state-space feedback
% is used. 
clear
clc



%% Load Predefined Parameters
load_params_inertial_case



%% User Inputs

% Motor Parameters
% Nominal Parameters (estimated from Blackbox)
mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
mld.tausf = 0.0056;     % [Nm]
mld.Jeq = mld.Jeq;      % [kg m^2]

% Actual Parameters (estimated from Motor 1)
%mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
%mld.tausf = 0.013;      % [Nm]
%mld.Jeq = 3.4640e-07;   % [kg m^2]

% High-pass filter (Continous - Time) for load velocity calculation
filt.high.omega_c = 2*pi*50; 
filt.high.delta = 1/sqrt(2);
filt.high.num = [filt.high.omega_c^2, 0];
filt.high.den = [1, 2*filt.high.delta*filt.high.omega_c, filt.high.omega_c^2];


%% Plant parameters Parameters

% reduced plant transfer function
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));


% Desired specifications
specs.T_r = 1; 
specs.Freq = (1/specs.T_r)*2*pi;
specs.W_n = 12; %sqrt(plant.km); 
specs.mp = 0.1; 
specs.settling_time = 0.15; %[seconds]

% Plant's A, B, C, D matrix 
plant_SS.A = [0 1; 0 -(1/plant.Tm)];
plant_SS.B = [0 ;  plant.km/(gbox.N*plant.Tm)]; 
plant_SS.C = [1 0];
plant_SS.D = 0;

ref_SS.A_r = [0 1; -specs.Freq^2 0];
ref_SS.C_r = [1 0];

math.A_12 = [0 0 ;-ref_SS.C_r];
math.A_21 = zeros([size(plant_SS.A,1),size(ref_SS.A_r,2)]);
math.B_12 = zeros([size(ref_SS.A_r,1),size(plant_SS.B,2)]);

hat_SS.A = [ref_SS.A_r math.A_12;math.A_21 plant_SS.A ];
hat_SS.B = [math.B_12;plant_SS.B];



% eigenvalues (poles calculation)
% First conjugate pair (-pi ± pi/4)
[math.x1, math.y1] = pol2cart(-pi+pi/4, specs.W_n);
[math.x2, math.y2] = pol2cart(-pi-pi/4, specs.W_n);

% Second conjugate pair (-pi ± pi/6)
[math.x3, math.y3] = pol2cart(-pi+pi/6, specs.W_n);
[math.x4, math.y4] = pol2cart(-pi-pi/6, specs.W_n);

% Ensure conjugate pairs
math.eig_val = [math.x1 + 1i*math.y1, math.x1 - 1i*math.y1, math.x3 + 1i*math.y3, math.x3 - 1i*math.y3];

% calculation of feedback via acker and place
[feedback.K, feedback.prec] = place(hat_SS.A, hat_SS.B, math.eig_val);

sIn.simulation_time = specs.T_r*10;


