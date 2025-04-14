% Matlab script to start the Simulink simulation an accurate model of the 
% Quanser SRV-02 + NI DAQ with a discrete time state-space controller and
% a reduced state observer.
clear



%% Load Predefined Parameters
load_params_inertial_case



%% User Inputs

% Motor Parameters
% Nominal Parameters (estimated from Blackbox)
%mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
%mld.tausf = 0.0056;     % [Nm]
%mld.Jeq = mld.Jeq;      % [kg m^2]

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
% Sampling time (1 ms)
sIn.Ts = 1e-3; %[s]

% Solver step time (0.1 ms)
sIn.step_size = 1e-4;

% List of reference positions [s]
sIn.position = [0, 40, 0, 70, 0, 120, 0]; 

% Time the reference positions are held [s]
sIn.sample_time = 5; 

% Automatic calculation of total simulation time [s]
sIn.simulation_time = sIn.sample_time*length(sIn.position) - 1;



%% Reduced State-Space Model
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



%% Closed Loop Eigenvalues
% Damping ratio from maximum overshoot
eigP.damping = (log(1/specs.mp)) / (sqrt((pi^2) + (log(1/specs.mp)^2))); 

% Gain cut-off frequency from settling time, in [rad/s]
eigP.wn = 3/(eigP.damping*specs.settling_time);

% Real and imaginary parts
eigP.real = -eigP.damping*eigP.wn; 
eigP.img = eigP.wn * sqrt(1 - eigP.damping^2);

% Desired eigenvalues
eigP.values = [eigP.real + 1i*eigP.img, ...
               eigP.real - 1i*eigP.img];

% State feedback matrix
feedback.K = acker(plant.A, plant.B, eigP.values);

% State feedforward gain and input feedforward gain
feedback.gains = ([plant.A, plant.B; plant.C, plant.D])\[0;0;1];
feedback.Nx = feedback.gains(1:2);
feedback.Nu = feedback.gains(3);



%% Reduced Observer Model
% Observer eigenvalue
eigO.damping = eigP.damping;
eigO.wn = 5*eigP.wn;
eigO.value = -eigO.damping*eigO.wn;


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
obsD.Phi0 = 1+obs.A0*sIn.Ts;
obsD.Gamma0 = obs.B0*sIn.Ts;
obsD.H0 = obs.C0;
obsD.J0 = obs.D0;




%% Butterworth Derrivator for Comparison with Simple Observer
filt.omega_c = 2*pi*50; 
filt.delta = 1/sqrt(2);
filt.num = [filt.omega_c^2, 0];
filt.den = [1, 2*filt.delta*filt.omega_c, filt .omega_c^2];


obs.sys = ss(obs.A0, obs.B0, obs.C0, obs.D0);
plant.sys = ss(plant.A-plant.B*feedback.K, plant.B, plant.C, plant.D);