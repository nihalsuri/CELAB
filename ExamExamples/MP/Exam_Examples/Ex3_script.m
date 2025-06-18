clear

%% System Definition
% Dynamic model
A = [0, 1; -2, -40];
B = [0; 40];
C = [1, 0];
D = 0;
sys = ss(A,B,C,D);

% Extended Model in CT
%Ae = [0,C; zeros(2,1), A];
%Be = [0;B];
%Ce = [0,C];
%De = D;
%syse = ss(Ae, Be, Ce, De);

% Sampling time
Ts = 0.01e-3;

%% Discretizing the Model
% discretizing the model and then extending
sysD = c2d(sys,Ts,'zoh');
[Phi, Gamma, H, J] = ssdata(sysD);

% Extending the discrete model
Phie = [1, H; zeros(2,1), Phi];    % Ts*H? -> same as discretizing extended
Gammae = [0;Gamma];
He = [0,H];
Je = J;
sysDe = ss(Phie, Gammae, He, Je, Ts);

% discretizing the extended model
%sysDe = c2d(syse, Ts, 'zoh');
%[Phie, Gammae, He, Je] = ssdata(sysDe);



%% Optimal Feedback Controller
% Cost matrices from Bryson's rule
Q = diag(ones(1,3)/10);
R = 4e8*1/20;

% Feedback gain and resulting closed loop poles
%[Ke,~,poles_cl_dt] = lqr(sysDe,Q,R);   % Same result as dlqr (sysDe is dt)
[Ke,~,poles_cl_dt] = dlqr(Phie,Gammae,Q,R);
Ki = Ke(1);
K = Ke(2:3);

% Feedforward gains
ff = [Phi-eye(2), Gamma; H,J]\[0;0;1];
Nx = ff(1:2);
Nu = ff(3);


%% Observer
% eigenvalues in z domain, 4-5 times faster than CL
eigs_obs_dt = abs(poles_cl_dt(1:2)).^[4;5];

% Observer Gain
L = place(Phi',H',eigs_obs_dt)';
Phio = Phi-L*H;
Gammao = [Gamma, L];
Ho = eye(2);
Jo = zeros(2);