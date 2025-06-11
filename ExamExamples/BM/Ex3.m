clear
t_s = 0.01e-3; %0.01ms 

%plant 
A = [0 1; 
    -2 -40]; 
B = [0;
     40];
C = [1 0]; 
D = 0;
plant = ss(A,B,C,D); 
plant_d = c2d(plant, t_s);

%descrete plant 
[phi, gamma, H, J] = ssdata(plant_d);

gains = [phi-eye(2) gamma; H J] \ [0; 0; 1];
N_x = gains(1:2);
N_u = gains(3); 


%Augmented state for integrator 
phi_e = [1 H; 
        [0;0] phi];
gamma_e = [0; 
         gamma]; 
%LQR
Q = diag([0.01 1/10 1/10]);
R = 1/20; 
k = dlqr(phi_e,gamma_e,Q,R)


%Observer 
obs = 0.5*pole( ss(phi - gamma*k(2:3),gamma,H,J));
L = acker(phi',H',obs)';

Ao = phi-L*H;
Bo = [gamma L];
Co = eye(2); 
Do = zeros(2,2); 

