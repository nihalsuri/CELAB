clear 

%% State Space Model
A = [0,1; 0,-20];
B = [0; 60];
C = [1,0];
D = 0;

sys = ss(A,B,C,D);      % State-Space Object
Ps = tf(sys);           % Transfer function Object


%% Extended State Space Model - Robust
Ae = [0,C; zeros(2,1), A];
Be = [0; B];
Ce = [0, C];
De = 0;


%% Performance Specs
Mp = 0.2;
ts = 0.2;

delta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
wn = 3/delta/ts;


%% Closed loop eigenvalues
eigs = -delta*wn + 1i*wn*sqrt(1-delta^2);
eigs = [eigs, conj(eigs), -delta*wn];


%% Feedback Gains
Ke = place(Ae, Be, eigs);
Ki = Ke(1);
K = Ke(2:end);


%% Feedforward Gains
ff = [A,B;C,D]\[0;0;1];
Nx = ff(1:2);
Nu = ff(3);


%% Observer - Full Order
% Eigenvalues
eigsObsFull = -wn*[4,5];

% Observer Gain
Lfull = place(A', C', eigsObsFull)';

% Observer Matrices
AobsFull = A-Lfull*C;
BobsFull = [B, Lfull];
CobsFull = eye(2);
DobsFull = zeros(2);


%% Observer - Reduced Order
% Eigenvalues
eigsObsRed = -wn*5;

% Observer Gain
Lred = place(A(2,2), A(1,2), eigsObsRed)';

% Observer Matrices
AobsRed = A(2,2)-Lred*A(1,2);
BobsRed = [B(2)-Lred*B(1), AobsRed*Lred+A(2,1)-Lred*A(1,1)];
CobsRed = [0;1];
DobsRed = [0,1; 0,Lred];

