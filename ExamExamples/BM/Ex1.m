%Plant 
A = [0  1;
     0 -10]; 
B = [0; 
    120]; 
C =[1 0]; 
D = 0; 
plant = ss(A,B,C,D);

%specs
t_r = 0.15;
M_p = 0.2; 
alpha = 0.1; 
w_gc = 1.8/t_r; 
zeta = log(1/M_p)/sqrt(pi^2+(log(1/M_p))^2);
phi_m = atan(2*zeta/sqrt(sqrt(1+4*zeta^4)-2*zeta^2));

%Phase and magnetude of plant 
[mag, phase] = bode(plant,w_gc);
mag = mag(:);
phase = phase(:);

delta_K=1/mag;
delta_phi = -pi+phi_m-deg2rad(phase); 

%Pid gains 
Kp = delta_K*cos(delta_phi);
Td  = (tan(delta_phi)+sqrt((tan(delta_phi))^2+4/alpha))/(2*w_gc); 
Ti = alpha*Td; 

Ki = Kp/Ti; 
Kd = Kp*Td; 

Tl=1/(2*w_gc); 
kw = 1/(t_s/5);



