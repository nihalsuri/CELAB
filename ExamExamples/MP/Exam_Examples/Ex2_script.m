clear


%% Nominal / Robust choice
nominal_robust = 1;


%% System definition
Ps = tf(90, [1,60,3]);
sys = compreal(Ps,'o'); % Observable Companion From
[A,B,C,D] = ssdata(sys);


%% Desired Performance
% Specs
Mp = 0.2;
tr = 0.25;

% Sampling time
Ts = tr/250;    % in [tr/1000, tr/20]

% Damping and Natural Frequency
delta = log(1/Mp) / sqrt(pi^2+log(1/Mp)^2)*1.1;
wn = 1.8/tr;

% Desired eigenvalues in CT
eigs = -delta*wn + 1i*wn*sqrt(1-delta^2);
eigs = [eigs, conj(eigs)];


%% Controller Design in CT (Nominal)
% Feedforward 
ff = [A,B;C,D]\[0;0;1];
Nx = ff(1:2);
Nu = ff(3);

% Feedback
K = place(A,B,eigs);


%% Controller Design in CT (Robust)
% Extended System
Ae = [0, C; zeros(2,1), A];
Be = [0;B];

% Add integrator eigenvalue
eigsR = [eigs, -delta*wn];

% Feedback
Ke = place(Ae,Be,eigsR);
Ki = Ke(1);
Kr = Ke(2:3);

if nominal_robust == 1
    K = Kr;
end


%% Full Order Observer
% Observer eigenvalue sin CT
eigsO = -wn*[4, 5];

% Gain
L = place(A',C',eigsO)';

% Observer in CT
Ao = A-L*C;
Bo = [B, L];
Co = eye(2);
Do =zeros(2);
obsC = ss(Ao,Bo,Co,Do);

% Observer in DT
Phi = eye(2)+Ao*Ts;
Gamma = Bo*Ts;
H = Co;
J = Do;