% Matlab script to start the Simulink simulation of the blackbox- and real
% model of the Quanser SRV-02 + NI DAQ. In both cases state-space feedback
% is used. 
clear
clc



%% Load Predefined Parameters
load_params_inertial_case



%% User Inputs


% Refereance specs 

% Choice of Input => "Sine wave reference"->1 or "Step reference "->2
sIn.program = 1; 

specs.Amp = 30;  %Amplitude of referance signal 
specs.T_r = 0.15;   % Periode of referance signal if a sin wave 
specs.Freq = (1/specs.T_r)*2*pi;  %Frequency of the sin wave 

%% Inputs for simulation 
sIn.simulation_time = specs.T_r*10;



%% Motor Parameters
% Nominal Parameters (estimated from Blackbox)
mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
mld.tausf = 0.0056;     % [Nm]
mld.Jeq = mld.Jeq;      % [kg m^2]

% Actual Parameters (estimated from Motor 1)
mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
mld.tausf = 0.013;      % [Nm]
mld.Jeq = 3.4640e-07;   % [kg m^2]

% High-pass filter (Continous - Time) for load velocity calculation
filt.high.omega_c = 2*pi*200; 
filt.high.delta = 1/sqrt(2);
filt.high.num = [filt.high.omega_c^2, 0];
filt.high.den = [1, 2*filt.high.delta*filt.high.omega_c, filt.high.omega_c^2];


%% Plant parameters Parameters
% reduced plant transfer function
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));


% Desired specifications
specs.mp = 0.1; 
specs.settling_time = 0.15; %[seconds]

% Calculation of damping ratio from maximum overshoot
specs.damping = (log(1/specs.mp)) / (sqrt((pi^2) + (log(1/specs.mp)^2))); 
% calculation of gain cut-off frequency from settling time 5% 
specs.W_n = 3/(specs.damping*specs.settling_time); %[rad/s]



% Plant's A, B, C, D matrix 
plant_SS.A = [0 1; 0 -(1/plant.Tm)];
plant_SS.B = [0 ;  plant.km/(gbox.N*plant.Tm)]; 
plant_SS.C = [1 0];
plant_SS.D = 0;



% Exo–system for refferance signal with constant disturbance
ref_SS.A_r = [0 1 0; 0 0 1 ; 0 -specs.Freq^2 0];
ref_SS.C_r = [1 0 0];

% Estimator Ae, Be, Ce, De
Ae = [ref_SS.A_r zeros(3,2); plant_SS.B*ref_SS.C_r plant_SS.A];
Be = [zeros(3,1); plant_SS.B];
Ce = [zeros(1,3) plant_SS.C];


% State-Space controller eigenvalues
cont_eig = [-specs.damping*specs.W_n + 1i*(specs.W_n)*(sqrt(1 - specs.damping^2))
    -specs.damping*specs.W_n - 1i*(specs.W_n)*(sqrt(1 - specs.damping^2))];

% estimator eigenvalues
[math.x1, math.y1] = pol2cart(-pi + pi/3, 2*specs.W_n);
[math.x3, math.y3] = pol2cart(-pi + pi/6, 2*specs.W_n);

est_eig = [math.x1 + 1i*math.y1, math.x1 - 1i*math.y1, math.x3 + 1i*math.y3, math.x3 - 1i*math.y3, -2*specs.W_n];


feedback.K = place(plant_SS.A, plant_SS.B, cont_eig); 
feedback.Ke = place(transpose(Ae), transpose(Ce), est_eig);
feedback.L = transpose(feedback.Ke);














