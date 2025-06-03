% Clear and load
clear; clc;
load('nominal_1st_gains.mat');

% Rename for convenience
data = nominalDisturbance;

% Extract time
time = data.time(:);  % Ensure column vector
num_signals = length(data.out);

% Optional: define your own labels
labels = {
    "Signal 1", 
    "Signal 2", 
    "Signal 3", 
    "Signal 4", 
    "Signal 5", 
    "Signal 6"
};

% Create separate figures for each signal
for i = 1:num_signals
    y = data.out{i};
    if isrow(y)
        y = y';  % ensure column
    end

    figure(i);
    plot(time, y, 'b', 'LineWidth', 1.5);
    grid on;
    xlabel('Time [s]');
    ylabel('Value');
    title(labels{i});
    set(gcf, 'Position', [300 + 50*i, 200 + 50*i, 600, 300]);  % cascade figure windows

    % Optional: save each plot
    % saveas(gcf, sprintf('signal_%d.png', i));
end
