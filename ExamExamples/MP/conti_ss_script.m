clear

% Nominal(0) or Robust(1)
nominal_robust = 1;


%% Example Plant
% System Matrices
A = [0,1; 0,-10];
B = [0; 120];
C = [1, 0];
D = 0;

sys = ss(A,B,C,D);  % State Space Object
Ps = tf(sys);       % Transfer function object


%% Desired Dynamic Specifications
% Given
Mp = 0.2;   % Overshoot
ts = 0.2;   % Settling Time

% Resulting Parameters
delta = log(1/Mp) / sqrt(pi^2+log(1/Mp)^2); % Damping ratio
wn = 3/ts/delta;                            % Natural frequency

re = -delta*wn;              % Real part of eigenvalues
im = wn*sqrt(1-delta^2);    % Imaginary part of eigenvalues

eigs = re+1i*im;
eigs = [eigs, conj(eigs)];  % Cc eigenvalues for nominal tracking

eigsR = [eigs, re];         % Eigenvalues for robust tracking

% Extended System Matrices
Ae = [0,C; zeros(2,1), A];
Be = [0; B];
Ce = [0, C];

% Feedforward Gains
ff = [A, B; C, D] \ [zeros(2,1); 1];
Nx = ff(1:2);       % State feedforward
Nu = ff(3);         % Input feedforward

% Feedback Gains
K = place(A,B,eigs);        % Nominal tracking

Ke = place(Ae,Be,eigsR);    % Robust tracking
Ki = Ke(1);

if nominal_robust == 1
    K = Ke(2:end);
end