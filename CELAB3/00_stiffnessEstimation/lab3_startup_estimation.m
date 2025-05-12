% Matlab script to start the Simulink simulation of an accurate model of 
% the Quanser SRV-02 + NI DAQ with a resonant load and estimate the joint 
% parameters
clearvars -except simulation_resp



%% Load Predefined Parameters
load_params_resonant_case

sIn.motor_or_blackbox_params = 1;   % 0: motor;  1: blackbox
load_params_model



%% Simulation Parameters 
% Solver step time (0.1 ms)
sIn.solver_time = 1e-4;

% Automatic calculation of total simulation time [s]
sIn.simulation_time = 1.2;

% Time for averaging the bias of displacement sensor
sIn.t0 = 0.2;
sIn.t1 = 0.7;


%% Measurements
times = [0, 0.126, 0.253, 0.379, 0.505, 0.632, 0.754, 0.882, 1.009];
peaks = [10, 8.132, 6.602, 5.061, 4.029, 2.986, 2.140, 1.326, 0.6667];

times = times(1:end-4);
peaks = peaks(1:end-4);


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
fprintf("Bb: %.5f  vs. Prev: %.5f\n", Bb_hat, mld.Bb)
fprintf("k : %.5f  vs. Prev: %.5f\n", k_hat, mld.k)


%% Plot of the resulting exponential
sigma = -gamma_ls*omega_n_hat;
A = sqrt(peaks(1)^2 + (sigma*peaks(1)/omega_hat)^2);
phi = atan2(sigma, omega_hat);

t=0:0.005:1.2;
estimated_resp = A*exp(sigma*t).*cos(omega_hat*t+phi);


if exist('simulation_resp','var') == 1
    f1 = figure(1);
    plot(simulation_resp.time, simulation_resp.signals.values)
    hold on
    plot(t, abs(estimated_resp))
    grid on
end