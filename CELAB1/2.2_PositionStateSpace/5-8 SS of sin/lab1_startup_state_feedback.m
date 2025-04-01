% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. In both cases state-space feedback
% is used. 
clear



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



%% Plant parameters Parameters

% reduced plant transfer function
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));


%% State feedback matrix calculation [2.2.1]  
% High-pass filter (Continous - Time) for load velocity calculation
filt.high.omega_c = 2*pi*50; 
filt.high.delta = 1/sqrt(2);
filt.high.num = [filt.high.omega_c^2, 0];
filt.high.den = [1, 2*filt.high.delta*filt.high.omega_c, filt.high.omega_c^2];


% Desired specifications
specs.T_r = 0.15; 
specs.Freq = (1/specs.T_r)*2*pi; 
specs.mp = 0.1; 
specs.settling_time = 0.15; %[seconds]

% Plant's A, B, C, D matrix 
plant_SS.A = [0 1; 0 -(1/plant.Tm)];
plant_SS.B = [0 ;  plant.km/(gbox.N*plant.Tm)]; 
plant_SS.C = [1 0];
plant_SS.D = 0;

ref_SS.A_r = [0 1; -specs.Freq^2 0];
ref_SS.C_r = [1 0];

A_12 = [0 0 ;-ref_SS.C_r];
A_21 = zeros([size(plant_SS.A,1),size(ref_SS.A_r,2)]);
B_12 = zeros([size(ref_SS.A_r,1),size(plant_SS.B,2)]);

hat_SS.A = [ref_SS.A_r A_12;A_21 plant_SS.A ];
hat_SS.B = [B_12;plant_SS.B];



% eigenvalues (poles calculation)
[x, y] = pol2cart(-pi+pi/4, specs.Freq);
eig_val(1) = x + 1i * y;
[x, y] = pol2cart(-pi-pi/4,specs.Freq);
eig_val(2) = x + 1i * y;
[x, y] = pol2cart(-pi+pi/6,specs.Freq);
eig_val(3) =x + 1i * y;
[x, y] = pol2cart(-pi-pi/6,specs.Freq);
eig_val(4) =x + 1i * y;
%eig_val(5) = -specs.Freq;

% calculation of feedback via acker and place
[feedback.nominal.place.K, feedback.nominal.place.prec] = place(hat_SS.A, hat_SS.B, eig_val);


sIn.simulation_time = specs.T_r*2;


