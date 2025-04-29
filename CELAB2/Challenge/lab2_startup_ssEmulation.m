% Matlab script to start the Simulink simulation an accurate model of the 
% Quanser SRV-02 + NI DAQ with a discrete time state-space controller and
% a reduced state observer.
clear



%% Load Predefined Parameters
load_params_inertial_case



%% User Inputs

% Motor Parameters
% Actual Parameters (estimated from Motor 1)
mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
mld.tausf = 0.013;      % [Nm]
mld.Jeq = 3.4640e-07;   % [kg m^2]

% Desired specifications
% Overshoot
specs.mp = 0.1; 
% Settling Time
specs.settling_time = 0.15; %[s]



%% Simulation Parameters 
% Sampling time
sIn.T_s =190e-3; %[s]

% Solver step time (0.1 ms)
sIn.step_size = 1e-4;

% Integration methos (1:FE,  2:BE,  3:Tustin)
sIn.integrationMethod = 2;

% Choice of nominal or robust controller (0:nominal,  1:robust)
sIn.nominal_robust = 1;

% List of reference positions [s]
sIn.position = 60;

% Time the reference positions are held [s]
sIn.sample_time = 5; 

% Automatic calculation of total simulation time [s]
sIn.simulation_time = sIn.sample_time*length(sIn.position);



%% State-Space Model
% Plant Parameters
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));

% System matrices
plant.A = [0,       1;
           0,  -(1/plant.Tm)];
plant.B = [0;
           plant.km/(gbox.N*plant.Tm)]; 
plant.C = [1, 0];
plant.D = 0;

% Extended state-space model
plant.Ae = [0, plant.C; zeros(2,1), plant.A];
plant.Be = [0; plant.B];
plant.Ce = [0, plant.C];
plant.De = plant.D;


%% Closed Loop Eigenvalues
% Damping ratio from maximum overshoot
eigP.damping = (log(1/specs.mp)) / (sqrt((pi^2) + (log(1/specs.mp)^2))); 

% Gain cut-off frequency from settling time, in [rad/s]
eigP.wn = 3/(eigP.damping*specs.settling_time);

% Real and imaginary parts
eigP.real = -eigP.damping*eigP.wn; 
eigP.img = eigP.wn * sqrt(1 - eigP.damping^2);

% Desired eigenvalues for nominal tracking
eigP.values = [eigP.real + 1i*eigP.img, ...
               eigP.real - 1i*eigP.img];

% State feedback matrix
feedback.K = acker(plant.A, plant.B, eigP.values);

% State feedforward gain and input feedforward gain
feedback.gains = ([plant.A, plant.B; plant.C, plant.D])\[0;0;1];
feedback.Nx = feedback.gains(1:2);
feedback.Nu = feedback.gains(3);


% Eigenvalues for robust tracking
eigP.robustValues = [eigP.real + 0.1*1i*eigP.img, ...
                     eigP.real - 0.1*1i*eigP.img, ...
                     eigP.real];

% State feedback matrix frot the robust case
feedback.robustKe = acker(plant.Ae, plant.Be, eigP.robustValues);
feedback.robustKi = feedback.robustKe(1);
feedback.robustK  = feedback.robustKe(2:end);

% Controller Tuning ideal impulse
% Sampling Time: 0.1s
%impVal = 2.46;
%thError = 0.2115;
%w = 45.66;

% Sampling Time: 0.15s
%impVal = 1.74;
%thError = 0.3665;
%w = 51.71;

% Sampling Time: 0.15s
impVal = 1.44;
thError = 0.3215;
w = 26.55;

k1 = (impVal*180)/(60*pi*feedback.robustK(1));
k2 = (thError*feedback.robustK(1)*k1)/(w*feedback.robustK(2));

feedback.stateTune = [k1, k2];
feedback.intTune = 0.01;

%% Reduced Observer Model
% Observer eigenvalue
eigO.damping = eigP.damping;
eigO.wn = 40*eigP.wn;
eigO.value = -eigO.damping*eigO.wn;
%eigO.value = -10;


% Observer gain
obs.L = acker(plant.A(2,2), plant.A(1,2), eigO.value);


% Observer matrices (simpilifcations applied)
obs.A0 = plant.A(2,2)-obs.L*plant.A(1,2);
obs.B0 = [plant.B(2), obs.A0*obs.L];
obs.C0 = [0; 
          1];
obs.D0 = [0,   1;
          0, obs.L];



%% Discretized Reduced Observer
% Forward Euler
obsFe.Phi0 = 1+obs.A0*sIn.T_s;
obsFe.Gamma0 = obs.B0*sIn.T_s;
obsFe.H0 = obs.C0;
obsFe.J0 = obs.D0;

% Backward Euler
obsBe.Phi0 = 1/(1-obs.A0*sIn.T_s);
obsBe.Gamma0 = 1/(1-obs.A0*sIn.T_s) *obs.B0*sIn.T_s;
obsBe.H0 = obs.C0/(1-obs.A0*sIn.T_s);
obsBe.J0 = obs.D0 + obs.C0/(1-obs.A0*sIn.T_s) *obs.B0*sIn.T_s;

% Tustin
obsTu.Phi0 = (1+(obs.A0*sIn.T_s)/2)/(1-(obs.A0*sIn.T_s)/2);
obsTu.Gamma0 = 1/(1-(obs.A0*sIn.T_s)/2) *obs.B0*sqrt(sIn.T_s);
obsTu.H0 = sqrt(sIn.T_s)*obs.C0 /(1-(obs.A0*sIn.T_s)/2);
obsTu.J0 = obs.D0 + obs.C0/(1-(obs.A0*sIn.T_s)/2) *obs.B0*sIn.T_s/2;

% Selection
obs.tmp = [obsFe, obsBe, obsTu];
obsD = obs.tmp(sIn.integrationMethod);

%% Simulation and Results
sim("lab2_model_ssEmulation_choices.slx");
lab2_eval_challenge