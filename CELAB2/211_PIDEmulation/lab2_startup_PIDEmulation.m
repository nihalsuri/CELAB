% Matlab script to start the Simulink simulation of an accurate model of the 
% Quanser SRV-02 + NI DAQ with a discrete time PID controller and its 
% improvements such as feedforward and antiwindup.
clear

%% Load Predefined Parameters
load_params_inertial_case

%% User Inputs

% Actual Parameters (estimated from Motor 1)
mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
mld.tausf = 0.013;      % [Nm]
mld.Jeq = 3.4640e-07;   % [kg m^2]

% Desired specifications
% Overshoot
specs.mp = 0.1; 
% Settling Time
specs.settling_time = 0.15; %[s]

%% PID Parameters

% reduced plant transfer function
plant.km = (drv.dcgain*mot.Kt)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Tm = (mot.Req*mld.Jeq)/((mot.Req*mld.Beq) + (mot.Kt*mot.Ke));
plant.Ps = tf(plant.km, [(gbox.N*plant.Tm) gbox.N 0]); 

% resulting gains from bode method
%PID = computePIDGains(8, specs.settling_time, specs.mp, plant.Ps, "PID");
PID.Kp = 7.845;
PID.Ki = 100.8347;
PID.Kd = 0.0763;
PID.Tl = 9.7252e-04;
PID.Cs = pid(PID.Kp, PID.Ki, PID.Kd, PID.Tl); 

% Anit Windup
PID.t_s5 = 0.15; % 5% settling time from lab0
PID.Kw = 1/(PID.t_s5/4.5); % anit windup gain: 1/Tw, Tw=t_s5/5


%% Discrete-Time PID
% Backward-Euler, this is only for visualization (NOT USED IN SIMULATION)
PID.Discrete.CzBE = pid(PID.Kp, PID.Ki, PID.Kd, PID.Tl, 1e-3, ...
    'IFormula', 'BackwardEuler', 'DFormula', 'BackwardEuler');

% Forward-Euler
PID.Discrete.CzFE = pid(PID.Kp, PID.Ki, PID.Kd, PID.Tl, 1e-3, ...
    'IFormula', 'ForwardEuler', 'DFormula', 'ForwardEuler');

% Tustin
PID.Discrete.CzTustin = pid(PID.Kp, PID.Ki, PID.Kd, PID.Tl, 1e-3, ...
    'IFormula', 'Trapezoidal', 'DFormula', 'Trapezoidal');






%% Simulation Parameters 
% Sampling Time Vector [1 ms 10ms 50ms]
specs.Ts = [1e-3; 1e-2; 5e-2]; % [s]
% Step reference input
sIn.position = [50, 360];
sIn.simulation_time = 5;