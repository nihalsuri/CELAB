    
%Plant 
plant.A = [0 1; 
           0 -20]; 
plant.B = [0; 
           60];
plant.C = [1 0]; 
plant.P = ss(plant.A,plant.B,plant.C,0); 

w = 6; %rad/sec
t_s = 0.2; 
m_p = 0.15; %Choose my self 
zeta = log(1/m_p)/sqrt(pi^2+(log(1/m_p)^2));
w_n = 3/(zeta*t_s); 


[math.x1, math.y1] = pol2cart(-pi+pi/4, w_n);
[math.x2, math.y2] = pol2cart(-pi-pi/4, w_n);

% Second conjugate pair (-pi ± pi/6)
[math.x3, math.y3] = pol2cart(-pi+pi/6, w_n);
[math.x4, math.y4] = pol2cart(-pi-pi/6, w_n);

eigs = [math.x1 + 1i*math.y1, math.x1 - 1i*math.y1, math.x3 + 1i*math.y3, math.x3 - 1i*math.y3, -w_n];

A_r = [0 1 0;
       0 0 1;
       0 -w^2 0];
C_r = [1 0 0]; 

A_12 = [0 0;
       0 0; 
       plant.C];

%Error space 
A_z = [A_r      ,    A_12; 
       zeros(2,3) plant.A];
B_z = [0;
       0;
       0;
    plant.B]; 

k = acker(A_z,B_z,eigs);

Tl = 1/(2*w_n);