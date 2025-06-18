% Evaluate the step response for a given Simulink simulation result.
% This script assumes that the simulation output is saved in a variable
% named 'position_1ms', with 'Structure with Time' format (fields: time, signals, blockName).
% It computes overshoot, rise time, and settling time for a specific setpoint.

% --- Configuration ---

% Select the logged simulation data
sOut = ScopeData;

% Choose the output signal index from the 'signals' array
% (1 = nominal response, 2 = with integral control, etc.)
inport = 2;

% Define the expected final value of the step input (reference)
% If you're using sIn.position in your workspace, make sure it's a scalar
refValue = 50;    % Replace with sIn.position if available and valid
t1 = 0.0;          % Replace with sIn.t1 if known (e.g., time step starts at nonzero)


% --- Step Response Analysis ---

% Extract time and signal
t = sOut.time;
y = sOut.signals(inport).values;

% Compute step response characteristics
sInfo = stepinfo(y, t, refValue, 'SettlingTimeThreshold', 0.05);

% Extract performance metrics
Mp  = sInfo.Overshoot;                        % Percent overshoot
ts5 = sInfo.SettlingTime - t1;               % Settling time (adjusted if t1 ≠ 0)
tr  = sInfo.RiseTime - t1;                   % Rise time (adjusted if t1 ≠ 0)

% Display results
fprintf("Overshoot: Mp = %.2f%%\n", Mp);
fprintf("Settling Time (5%%): t_s5 = %.3f s\n", ts5);
fprintf("Rise Time: t_r = %.3f s\n", tr);

% --- Optional Plot ---
figure;
plot(t, y, 'LineWidth', 1.5); hold on;
yline(refValue, 'k--', 'Reference');
xlabel('Time (s)');
ylabel('Output');
title('Step Response');
xlim([0,1]);
grid on;
legend('Response', 'Reference');
