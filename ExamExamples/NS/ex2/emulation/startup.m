% Startup file for ex2 
% DT SS feedback controller with full state observer 
% Design by emulation 
clear;

% Plant 
Ps = tf(90, [1, 60, 3]); 
[A, B, C, D] = tf2ss(90, [1, 60, 3]); 
sys = ss(A, B, C, D);

% check if a controller is possible 
if rank(ctrb(A,B)) == 2
    disp("Reachable!")
else 
    disp("Can't form a controller..check if unreachable part is stable")
end

% check if a observer is possible 
if rank(obsv(A,C)) == 2
    disp("Observable!")
else 
    disp("Can't form an observer..check if unreachable part is stable")
end


%specs 
mp = 0.2; 
tr = 0.25; 

% Rule of thumb for Ts:  tr/1000 < Ts < tr/20
ts = 0.0001; 
% for eigenvalue calculation
wn = 1.8/tr; 
d = log(1/mp) / sqrt ((pi^2) + (log(1/mp)^2 ));

eig_cont_real = -wn*d; 
eig_cont_imag = wn*(sqrt(1 - (d^2))); 

poles_cont = [eig_cont_real + 1i*eig_cont_imag, eig_cont_real - 1i*eig_cont_imag]; 
K = acker(A,B,poles_cont);

feedforward_gains = ([A B; C D])\[0; 0; 1]; 
Nx = feedforward_gains(1:2);
Nu = feedforward_gains(3);

%% Observer calculation
% 5 times faster poles
poles_observer = [4*eig_cont_real , 6*eig_cont_real]; 
L = place(A', C', poles_observer)'; 

% Matrices in CT
Ao = A-L*C; 
Bo = [B, L]; 
Co = eye(size(A)); 
Do = zeros(length(A), length(Bo(1,:))); 
obssys = ss(Ao, Bo, Co, Do);

% Matrices in DT via Tustin
obssysd = c2d(obssys, ts, 'zoh'); 






