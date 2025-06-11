clear

%% Model
A = [0,1; 0,-20];
B = [0; 60];
C = [1,0];
D = 0;

sys = ss(A,B,C,D);      % State-Space Object
Ps = tf(sys);           % Transfer function Object


%% Exo System
wr = 6;
Ar = [0,   1,   0;
      0,   0,   1;
      0, -wr^2, 0];

%% Extended System
A12 = [zeros(2,2); C];
A21 = zeros(2,3);

Az = [Ar, A12;
      A21, A];
Bz = [zeros(3,1); B];

%% Performance Specifications
Mp = 0.1;
ts = 0.1;

delta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
wn = 3/delta/ts;

eigs = wn*exp(1i*(pi+pi./[4,6]));
eigs = [eigs, conj(eigs)];
eigs = [eigs, -wn];


%% Feedback 
% In error space
Kz = place(Az, Bz, eigs);   

% State feedback
K = Kz(4:5);


%% Simple Observer
wc_obs = 2*pi*50;
delta_obs = 1/sqrt(2);

num_obs = [wc_obs^2, 0];
den_obs = [1, 2*wc_obs*delta_obs, wc_obs^2];


%% Evaluation
% info = stepinfo(out.ScopeData.signals(1).values, out.ScopeData.time, 
%                 "SettlingTimeThreshold",0.05)