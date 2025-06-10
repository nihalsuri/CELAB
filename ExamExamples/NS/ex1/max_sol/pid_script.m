clear

%% Example Plant
% System Matrices
A = [0,1; 0,-10];
B = [0; 120];
C = [1, 0];
D = 0;

sys = ss(A,B,C,D);  % Make a State-Space Object
Ps = tf(sys);       % Make a Transfer Function Object



%% PID-Controller
% Controller Type
type = 'PID';

% Tunable Parameters
alpha = .1;     % Ti=alpha*Td; choose <=4
filter_co = 4;  % w_filter=filter_co*w_gc; choose in [2,5]

% Desired Specifications
Mp = 0.2;   % Overshoot
ts = 0.2;   % Settling time [s]
tr = 0.15;  % Rise time [s]

% Desired dynamic parameters
delta = log(1/Mp) / sqrt(pi^2+log(1/Mp)^2); % damping factor
%w_n = 3/ts/delta;                          % natural frequency
w_n = 1.8/tr;

% Phase Margin
phi_m = atan2(2*delta, sqrt(sqrt(1+4*delta^4)-2*delta^2));

% Gain Crossover
w_gc = w_n;
[mag_gc, phase_gc] = bode(Ps, w_gc);

% Delta K
dK = 1/mag_gc;

% Delta phi
dphi = -pi + phi_m - phase_gc;

% PID
Kp = dK*cos(dphi);
Td = (tan(dphi) + sqrt(tan(dphi)^2 + 4/alpha)) / (2*w_gc);
Ti = alpha*Td;
Tl = 1/filter_co/w_gc;

switch type
    case 'PID'
        Kd = Kp*Td;
        Ki = Kp/Ti;
    case 'PD'
        Kd = 1/w_gc * dK*sin(dphi);
    case 'Pi'
        Ki = -w_gc * dK*sin(dphi);
end

% Closed-loop system without feed froward or anti windup
Cs = pid(Kp,Ki,Kd,Tl);
cl_sys = feedback(Cs*Ps,1);

% Step response information
info = stepinfo(cl_sys);
disp("Overshoot:")
disp(info.Overshoot)
disp("")
disp("Rise Time:")
disp(info.RiseTime)

% Anti Windup gain
ts = tr/delta*3/1.8;
Kw = 5/ts;

