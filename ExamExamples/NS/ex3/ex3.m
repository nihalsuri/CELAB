clear; 

A = [0 1; -2 -40]; 
B = [0; 40];
C = [1 0]; 
D = 0; 

Ts = 0.01*1e-3;
sys = ss(A,B,C,D);
sysd = c2d(sys, Ts, 'zoh'); 

% Feedforward gains 
ff_gains = [sysd.A - eye(2,2), sysd.B; sysd.C, sysd.D]\[0;0;1];
Nx = ff_gains(1:2); 
Nu = ff_gains(3); 

% Form the extended matrices
Ae = [1, sysd.C; zeros(2,1) sysd.A]; 
Be = [0; sysd.B]; 

% Form the Q and R matrices 
s = 10; 
c = 20; 
Q = diag([1/s, 1/s, 1/s]);
R = 1/c; 

[K,S,poles] = dlqr(Ae,Be,Q,R);
K = K(2:end); 
Ki = K(1); 

% Observer design
L = place(sysd.A', sysd.C', [real(poles(1))^4; real(poles(1))^6])';
Ao = sysd.A - L*sysd.C; 
Bo = [sysd.B, L]; 
Co = eye(2,2); 
Do = zeros(2,2);

% reduced observer
Ld = place(sysd.A(2,2), sysd.A(1,2), real(poles(1))^5)';

Aod = sysd.A(2,2) - Ld*sysd.A(1,2); 
Bod = [sysd.B(2) - Ld*sysd.B(1), Aod*Ld + sysd.A(2,1) - Ld*sysd.A(1,1)];

Cod = [0;1]; 
Dod = [0 1; 0 Ld];



