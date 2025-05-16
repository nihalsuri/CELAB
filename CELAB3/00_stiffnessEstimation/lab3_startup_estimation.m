% Matlab script to start the Simulink simulation of an accurate model of 
% the Quanser SRV-02 + NI DAQ with a resonant load and estimate the joint 
% parameters
clearvars -except simulation_resp



%% Load Predefined Parameters
load_params_resonant_case



%% Simulation Parameters 
% Solver step time (0.1 ms)
sIn.solver_time = 1e-4;

% Automatic calculation of total simulation time [s]
sIn.simulation_time = 100;

% Time for averaging the bias of displacement sensor
sIn.t0 = 0.2;
sIn.t1 = 0.7;


%% Measurements

% 1st measuer 10 deg
%Bb: 0.00775
%k : 0.72867
times = [10.423, 10.632, 10.758, 10.885, 11.016, 11.144];
peaks = [10.01, 5.254, 3.868, 3.353, 2.057, 1.229];

%Bb: 0.00579
%k : 0.73030
times = [18.072, 18.283, 18.413, 18.541, 18.671, 18.801, 18.929, 19.061];
peaks = [13.38, 6.361, 5.791, 4.829, 3.969, 2.918, 1.778, 0.805];

remove_last = 1;

times = times(1:end-remove_last);
peaks = peaks(1:end-remove_last);



%% Least Squares Fitting
% Model: Y = Phi*Theta + noise
Y = log(peaks');
Phi = [-1*(0:length(peaks)-1)', ones(length(peaks), 1)];
Theta = Phi\Y;

% Extract the slope/log. decrement and intercept
zeta_ls = Theta(1);
b_ls    = Theta(2);

% Damping from log. decrement
gamma_ls = zeta_ls/(sqrt(pi^2+zeta_ls^2));

% Damped frequency by Time intervals
sum = 0;
for i=1:length(times)-1
    omega_i = pi/(times(i+1)-times(i));
    sum = sum + omega_i;
end

% Damped frequency 
omega_hat = 1/(length(times)-1) *sum;

% Natural frequency
omega_n_hat = omega_hat/sqrt(1-gamma_ls^2); 

% Desired parameters
Bb_hat = 2*mld.Jb*gamma_ls*omega_n_hat;
k_hat  = mld.Jb*omega_n_hat^2;
fprintf("Bb: %.5f\n", Bb_hat)
fprintf("k : %.5f\n", k_hat)


%% Plot of the resulting exponential
sigma = -gamma_ls*omega_n_hat;
A = sqrt(peaks(1)^2 + (sigma*peaks(1)/omega_hat)^2);
phi = atan2(sigma, omega_hat);

t=0:0.005:1.2;
estimated_resp = A*exp(sigma*t).*cos(omega_hat*t+phi);


if exist('simulation_resp','var') == 1
    idx = find(simulation_resp.time >= times(1));
    simulation_resp.time = simulation_resp.time-times(1);
    f1 = figure(1);
    plot(simulation_resp.time(idx), simulation_resp.signals.values(idx))
    hold on
    plot(t, abs(estimated_resp))
    grid on
end