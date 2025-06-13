% Startup file for ex1 example, added FF just as a test. Confrim if tr
% matches the required specs
clear; 
% 1 is antiwindup on, 0 is you can guess
sIn.aw = 1; 
% 1 for step, 2 for ramp, 3 for sin
sIn.input = 1; 
% switch off PID or FF
sIn.PID = 1; 
sIn.FF = 0;

% Create the plant, add specs
mp = 0.2; 
tr = 0.15; 

plant.A = [0 1; 0 -10];
plant.B = [0; 120];
plant.C = [1 0]; 
plant.D = 0; 

sys = ss(plant.A, plant.B, plant.C, plant.D); 
[b,a] = ss2tf(plant.A, plant.B, plant.C, plant.D); 
Ps = tf(b,a); 

% % Calculate PID gains, to track step and ramps using Bode's method 
% alpha = 6;
% % Gain cross over frequency 
% w_gc = 1.8/specs.tr; % same as w_b 
% 
% % damping ration calculation 
% d = log(1/specs.mp) / ( sqrt( (pi^2) + (log(1/specs.mp)^2) ) ); 
% 
% % Phase margin calculation 
% phi_m = atan(2*d / (sqrt( sqrt(1 + 4*(d^4)) - 2*(d^2) ) ) ); 
% 
% % Calculate plant gain and phase at wgc 
% [mag, phase] = bode(Ps, w_gc); 
% 
% % Delta K and delta phase calculation 
% delta_k = (1./mag); 
% delta_phi = -pi + phi_m - deg2rad(phase); 
% 
% % Final gain coeffs calculation 
% Kp = delta_k*cos(delta_phi); 
% Td = (tan(delta_phi) + sqrt( (tan(delta_phi)^2)  + 4/alpha) ) / (2*w_gc); 
% Ti = alpha*Td; 
% 
% Kd = Kp*Td; 
% Ki = Kp/Ti; 
% 
% Tl = 1/(4*w_gc); 
% 
% %AW
% Kw = 5/(3/(d*w_gc)); 

alpha = 6; 
wn = 1.8/ tr; 
Tl = 1/(4*wn); 
zeta = log(1/ mp) / sqrt ((pi^2) + (log(1/mp)^2) ); 
phi_m = atan(2*zeta /  sqrt( sqrt(1 + (4*zeta^4)) - 2*zeta^2)); 

[mag, phase] = bode(Ps, wn); 

delta_K = 1/mag; 
delta_phi = -pi + phi_m -deg2rad(phase); 

Kp = delta_K * cos(delta_phi); 
Td = (tan(delta_phi) + sqrt( (tan(delta_phi)^2) + (4/alpha) )) / (2*wn); 
Ti = alpha*Td; 

Ki = Kp/Ti; 
Kd = Kp*Td; 
Kw = 5/ (3/zeta*wn); 


% % Closed-loop system without feed froward or anti windup
% Cs = pid(Kp,Ki,Kd,Tl);
% cl_sys = feedback(Cs*Ps,1);
% 
% % Step response information
% info = stepinfo(cl_sys);
% disp("Overshoot:")
% disp(info.Overshoot)
% disp("")
% disp("Rise Time:")
% disp(info.RiseTime)


% Digital PID via emulation 
% Gains will stay the same 
Ts = 0.0001; 
derv_filter = tf([1 0], [Tl 1]);
derv_filter_d = c2d(derv_filter, Ts, 'tustin'); 
[n, d] = tfdata(derv_filter_d, 'v'); 

