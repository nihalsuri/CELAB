clear 

%% Sysste
A = [0  1;
    -3  -60]; 
B = [0; 
     1]; 
C = [90 0]; 
D = 0;
sys = ss(A,B,C,D);

t_s = 0.001; 

%Descrete system
sys_d = c2d(sys,t_s,"zoh");
[phi, gamma, H , J] = ssdata(sys_d);

%Dessired values 
t_r = 0.25; 
M_p = 0.2; 
w_n = 1.8/t_r; 
zeta = log(1/M_p)/sqrt(pi^2+(log(1/M_p)^2)); 

%Poles 
real = -w_n*zeta;
img = w_n*sqrt(1-zeta^2); 
eigs = [real + 1i*img, real-1i*img];
eigs_d = exp(t_s*eigs);

%Gains 
k = acker(phi, gamma,eigs_d);
gains  = [phi-eye(2), gamma; H, J] \ [0;0;1]; 
N_x = gains(1:2);
N_u = gains(3);


% Obser 
obsEigs = exp(2*t_s*eigs); 
L = acker(phi', H', obsEigs)';

Ao = phi-L*H;
Bo = [gamma L]; 
Co = eye(2); 
Do = zeros(2,2);



