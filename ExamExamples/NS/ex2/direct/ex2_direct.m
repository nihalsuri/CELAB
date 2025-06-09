% Startup file for ex2 
% DT SS feedback controller with full state observer 
% Design by emulation 
clear;

% Plant 
ts = 0.0001; 
Ps = tf(90, [1, 60, 3]); 
[A, B, C, D] = tf2ss(90, [1, 60, 3]); 
sys = ss(A, B, C, D);

% Discrete Plant
sysD = c2d(sys, ts, 'zoh'); 
[phi, gamma, H, J] = ssdata(sysD); 

%specs 
mp = 0.2; 
tr = 0.25; 

% for eigenvalue calculation
wn = 1.8/tr; 
d = log(1/mp) / sqrt ((pi^2) + (log(1/mp)^2 ));

eig_cont_real = -wn*d; 
eig_cont_imag = wn*sqrt(1 - (d^2)); 

poles_cont = [eig_cont_real + 1i*eig_cont_imag, eig_cont_real - 1i*eig_cont_imag]; 
poles_cont_d = exp(ts*poles_cont); 
K = acker(phi,gamma,poles_cont_d);

feedforward_gains = ([phi - eye(2), gamma; H, J])\[0; 0; 1]; 
Nx = feedforward_gains(1:2);
Nu = feedforward_gains(3);

%% Observer calculation in DT
% 5 times faster poles
poles_observer = [4*eig_cont_real , 6*eig_cont_real ]; 
poles_observer_d = exp(ts*poles_observer);
L = place(phi', H', poles_observer_d)'; 

% Matrices in CT
Ao = phi-L*H; 
Bo = [gamma, L]; 
Co = eye(size(phi)); 
Do = zeros(2,2); 
