A = [0 1
    0 -20]; 
B = [0;
     60]; 
C = [1 0]; 

w = 6; 
ts = 0.2; 
mp = 0.15; 
d = log(1/mp)/sqrt(pi^2+(log(1/mp))^2); 
wn = 3/(d*ts); 
Tl = 1/(2*wn); 

Ar =[0  1   0;
     0  0   1;
     0 -w^2 0]; 
Cr = [1 0 0]; 

Ae = [Ar    zeros(3,2);
      B*Cr     A]; 
Be = [zeros(3,1);
         B]; 
Ce = [0 0 0 C]; 

P1 = 2*wn*exp(1i*(-pi-pi/6));
P2 = 2*wn*exp(1i*(-pi-pi/4));
P_des = [P1, P1', P2, P2', -2*wn]; 

L = acker(Ae',Ce',P_des)'; 

Ao = Ae-L*Ce; 
Bo = [Be L]; 
Co = eye(5); 
Do = zeros(5,2); 

real = -wn*d;
img = wn*sqrt(1-d^2);
pol_c = [real+1i*img, real-1i*img]; 
k = acker(A,B,pol_c);

