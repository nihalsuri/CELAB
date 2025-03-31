% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. In both cases a PID controller is 
% used, the parameters can be calculated based of a reduced model or 
% manually set.
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
specs.mp = 0.1; 
specs.settling_time = 0.15; %[seconds]

% Plant's A and B matrix 
plant_SS.A = [0 1; 0 -(1/plant.Tm)];
plant_SS.B = [0 ;  plant.km/(gbox.N*plant.Tm)]; 

% desired closed loop eigenvalues 
% Calculation of damping ratio from maximum overshoot
eig.nominal.damping = (log(1/specs.mp)) / (sqrt((pi^2) + (log(1/specs.mp)^2))); 
% calculation of gain cut-off frequency from settling time 5% 
eig.nominal.wn = 3/(eig.nominal.damping*specs.settling_time); %[rad/s]


% eigenvalues (poles calculation)
eig.nominal.real = -eig.nominal.damping*eig.nominal.wn; 
eig.nominal.img = eig.nominal.wn * sqrt(1 - eig.nominal.damping^2);
eig.nominal.values = [eig.nominal.real + 1i*eig.nominal.img, eig.nominal.real - 1i*eig.nominal.img];

% calculation of feedback via acker and place
[feedback.nominal.place.K, feedback.nominal.place.prec] = place(plant_SS.A, plant_SS.B, eig.nominal.values);
feedback.nominal.acker.K = acker(plant_SS.A, plant_SS.B, eig.nominal.values);

% Set-points for state-space control test
feedback.setpoints = [40 70 120]; %[degrees]



