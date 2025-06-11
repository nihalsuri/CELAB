clear


%% State Space Model
A = [0,1; -3, -60];
B = [0; 1];
C = [90, 0];
D = 0;

sys = ss(A,B,C,D);
emu_dd = 1;

%% Performance Specs
Mp = 0.2;
tr = 0.25;
Ts = 1e-3;  % should be in [tr/1000, tr/20]

delta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
wn = 1.8/tr;

eigs = -delta*wn + 1i*wn*sqrt(1-delta^2);
eigs = [eigs, conj(eigs)];

%% Emulation
% Feedback
Kemu = place(A,B,eigs);

% Feedforward
ffemu = [A,B;C,D]\[0;0;1];
Nxemu = ffemu(1:2);
Nuemu = ffemu(3);


%% Direct Digital Method
% Eigenvalues in z-domain
eigsD = exp(Ts*eigs);

% Discretized Plant
sysD = c2d(sys,Ts,'zoh');
[Phi, Gam, H, J] = ssdata(sysD);

% Feedback
Kdd = place(Phi,Gam,eigsD);

% Feedforward
ffdd = [Phi-eye(2), Gam; H, J]\[0;0;1];
Nxdd = ffdd(1:2);
Nudd = ffdd(3);


%% Full Order Observer - Emulation
% Eigenvalues in CT
eigsOC = -wn*[4,5];

% Gain from CT plant
LC = place(A',C',eigsOC)';

% Observer Model in CT
Aoc = A-LC*C;
Boc = [B, LC];
Coc = eye(2);
Doc = zeros(2);
obsC = ss(Aoc,Boc,Coc,Doc);

% Discretization
obsD = c2d(obsC,Ts,'zoh');
[PhiO, GamO, HO, JO] = ssdata(obsD);


%% Full Order Observer - Direct Digital
% Eigenvalues in DT
eigsOD = exp(Ts*eigsOC);

% Gain from DT plant
LD = place(Phi',H',eigsOD)';

% Observer Model in DT
PhiOO = Phi-LD*H;
GamOO = [Gam, LD];
HOO = eye(2);
JOO = zeros(2);

% Choice
if emu_dd == 0
    Nx = Nxemu;
    Nu = Nuemu;
    K = Kemu; 
else
    Nx = Nxdd;
    Nu = Nudd;
    K = Kdd;
    PhiO = PhiOO;
    GamO = GamOO;
    HO = HOO;
    JO = JOO;
end