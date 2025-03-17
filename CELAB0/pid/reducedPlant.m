clear
% laod all parameters
load_params_inertial_case; 
% Reduced Plant (eqn 29)
B_eq_user = 0.0; % Total viscous friction coeff set by user after estimation (N·m·s/rad)

N = gbox.N; % planetary gearbox reduction ratio (constant value of 14)
R_eq = sens.curr.Rs + mot.R; % armature and shunt resistance (eqn 22) (ohms)
J_eq = mot.J + ((mld.J)/(N^2));  % motor and load moment of inertia (eqn 10) (kgm^2)
k_drv = drv.dcgain; % voltage driver attenuation gain (eqn 17)
k_t = mot.Kt; % torque constant (Nm/A)
k_e = mot.Ke; % bemf constant (Vs/rad)

km = (k_drv*k_t)/((R_eq*B_eq_user) + (k_t*k_e)); % for plant numerator: km
Tm = (R_eq*J_eq)/((R_eq*B_eq_user) + (k_t*k_e)); % for plant denominator: NTms^2 + Ns

% reduced plant transfer function 
Ps = tf(km, [(N*Tm) N 0]); 

% computation of PID gains
gains = computePIDGains(8, 0.15, 0.1, Ps, "PID"); 

% test on the plant
 C = pid(gains.Kp, gains.Ki, gains.Kd);
 sys_cl = feedback(C * Ps, 1);

% Plot the step response with annotated characteristics
%figure;
%step(sys_cl);


