% Startup file for ex2 
% DT SS feedback controller with full state observer 
% Design by emulation 
clear;

% Plant 
ts = 0.001; 
Ps = tf(90, [1, 60, 3]); 
%[A, B, C, D] = tf2ss(90, [1, 60, 3]);
A = [0,1; -3, -60];
B = [0; 1];
C = [90, 0];
D = 0;
sys = ss(A, B, C, D);

% Discrete Plant
sysD = c2d(sys, ts, 'tustin'); 
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

%% For Robust SS
phi_e = [0, H; zeros(2,1), phi]; 
gamma_e = [0; gamma]; 
poles_cont_e = [eig_cont_real + 1i*eig_cont_imag, eig_cont_real - 1i*eig_cont_imag, eig_cont_real];
poles_cont_ed = exp(ts*poles_cont_e); 
Ke = place(phi_e, gamma_e, poles_cont_ed); 
Ki = Ke(1); 
K_robust = Ke(2:end);

%% Observer calculation in DT
% 5 times faster poles
poles_observer = [4*eig_cont_real , 6*eig_cont_real ]; 
poles_observer_d = exp(ts*poles_observer);
L = place(phi', H', poles_observer_d)'; 

% Matrices in DT
Ao = phi-L*H; 
Bo = [gamma, L]; 
Co = eye(size(phi)); 
Do = zeros(2,2); 

%% Reduced observer calculation in DT (place only one eigenvalue)
Ld = place(phi(2,2), phi(1,2), exp(ts*5*eig_cont_real)); 
% Matrices in DT
phio = phi(2,2)-Ld*phi(1,2); 
gammao = [gamma(2) - Ld*gamma(1), phio*Ld + phi(2,1) - phi(1,1)*Ld]; 
Ho = [0; 1]; 
Jo = [0,1; 0,Ld]; 


