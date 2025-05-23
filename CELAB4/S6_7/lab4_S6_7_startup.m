% Startup file so as to estimate the state of the balancing robot from the
% measurements of the MPU and incremental encoder
clear 

% load robot parameters file 
balrob_params

% simulation parameters
sIn.Ts = 0.01;
sIn.simulation_time = 10; 

% Tilt angle estimation via a complementary filter approach
% Low-pass filter for the accelerometer, high-pass for the gyroscope
% Their sum is valid on the entire frequency range

% Low pass filter cutoff frequency 
filter.low.fc = 0.35; 
% Low pass filter time constant 
filter.low.Tc = 1/(2*pi*filter.low.fc); 
% First order low pass filter
filter.low.firstorderCT = tf(1, [filter.low.Tc 1]);
% Strictly proper discrete time filter
filter.low.firstorderDT = c2d(filter.low.firstorderCT, sIn.Ts, 'zoh');

% High pass filter ("real derivative")
% as mentioned in eqn 7 in assignment
filter.high.N = 3; 
filter.high = tf([-1 0 0 1], filter.high.N*sIn.Ts, sIn.Ts);

% DT SS control based on LQR using Bryson's rule







