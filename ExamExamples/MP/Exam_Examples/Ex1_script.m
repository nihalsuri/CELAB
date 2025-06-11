clear


%% System Definition
A = [0, 1; 0, -10];
B = [0; 120];
C = [1, 0];
D = 0;

sys = ss(A,B,C,D);

% A has one eigenvalue in zero, meaning the transfer function has one pole
% in the origin, to track linear ramps, two poles in the origin are needed
% in the open-loop transfer function L(s) = C(s)*P(s). Together with the
% integrator pole from the PID this is given.


%% Tunable Parameters
alpha = .1; % Relation Ti=alpha*Ti
tau = 3;    % Tl = 1/(tau*wgc)

%% Desired Dynamics
% Specs
Mp = 0.2;
tr = 0.15;

% Damping and natural frequency
delta = log(1/Mp) / sqrt(pi^2+log(1/Mp)^2);
wn = 1.8/tr;

% Gain crossover
wgc = wn;
[mag_gc, phase_gc] = bode(sys,wgc);
phase_gc = phase_gc*pi/180;

% Phase Margin
phi_m = atan2(2*delta, sqrt(sqrt(1+4*delta^4) - 2*delta^2));

% Available Phase and Magnitude
dphi = -pi + phi_m - phase_gc;
dK = 1/mag_gc;

% Controller Gains
Kp = dK*cos(dphi);
Td = (tan(dphi)+sqrt(tan(dphi)^2+4/alpha))/(2*wgc);
Ti = alpha*Td;

Kd = Kp*Td;
Ki = Kp/Ti;

% Time constant for real derivative
Tl = 1/(tau*wgc);


%% Anti Windup Gain
ts = 3/delta/wn;
Kw = 5/ts;