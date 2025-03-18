% This script is used to load the parameters needed to test the
% blackbox model of the Quanser SRV-02 + NI DAQ 
% and estimate friction and inertia values.
% It includes hardware and filter parameters input definitions
clear

%% Load Predefined Parameters
load_params_inertial_case


%% Filter Parameters for Friction Estimation

% Butterworth high-pass for differentiating measured position
filt.butt.omega_c = 2*pi*20;
filt.butt.delta =1/sqrt(2);
filt.butt.num = [filt.butt.omega_c^2, 0];
filt.butt.den = [1, 2*filt.butt.delta*filt.butt.omega_c, filt.butt.omega_c^2];


% Low-pass noise reduction on current
filt.low.omega_ci = 2*pi*20;
filt.low.delta_i = 1/sqrt(2);
filt.low.num = filt.low.omega_ci^2;
filt.low.den = [1, 2*filt.low.delta_i*filt.low.omega_ci, filt.low.omega_ci^2];



%% Input Samples

sIn.step_time = 5;
sIn.step_number = 9;
sIn.t_sim = sIn.step_time*(sIn.step_number*2+1);

% input for open loop [V] (estimated values)
u_ref_p = [1.3, 2.3, 3.3, 4.3, 5.3, 6.3, 7.3, 8.3, 9.3];
u_ref_m = -1*u_ref_p;
u_ref = [u_ref_p, 0, u_ref_m];
