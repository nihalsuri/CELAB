% Start 12:25
clear

%% System Definition
A = [0,1; 0,-20];
B = [0; 60];
C = [1, 0];
D = 0;


%% Exo Model
wr = 6;
Ar = [0,   1,   0;
      0,   0,   1;
      0, -wr^2, 0];
Cr = [1,0,0];


%% Extenden Model - IMP
A12 = [zeros(2,2); C];
A21 = zeros(2,3);

Ae = [Ar, A12;
      A21, A];
Be = [zeros(3,1); B];


%% Desired Dynamics
Mp = 0.2;
ts = 0.1;

delta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
wn = 3/ts/delta;

eigs = wn*exp(1i*(pi+pi./[4,6]));
eigs = [eigs, conj(eigs)];
eigs = [eigs, -wn];


%% Feedback
% Gains in Error space
Ke = place(Ae,Be,eigs);

% Transfer fucntion for error
Ktf = Ke(1:3);          % [k0, k1, k2]
num_tf = flip(Ktf);     % [k2, k1, k0]
den_tf = [1, -Ar(end,:)];


% State feedback
K = Ke(4:5);


%% Filtered Derivative -> High Pass
wc = 2*pi*50;   % cut-off
del = 1/sqrt(2);

num_hp = [wc^2, 0];
den_hp = [1, 2*del*wc, wc^2];