% Rename for convenience
data = robustYaw1;

% Extract time and trim to first 60 seconds
time = data.time(:);  % Ensure column vector
idx = time <= 60;     % Logical index for first 60 seconds
time = time(idx);

num_signals = length(data.out);

% Optional: define your own labels
labels = {
    "\gamma [deg]", 
    "\vartheta [deg]", 
    "$\dot{\gamma}$ [$\frac{deg}{s}$]", 
    "$\dot{\vartheta}$ [$\frac{deg}{s}$]", 
    "\psi [deg]", 
    "duty [V]",
    "Reference \gamma [deg]"
};

% Create separate figures for each signal
for i = 1:num_signals
    y = data.out{i};
    if isrow(y)
        y = y';  % Ensure column
    end

    y = y(idx);  % Trim signal to first 60 seconds

    figure(i);
    plot(time, y, 'b', 'LineWidth', 1.5);
    grid on;
    xlabel('Time [s]');
    ylabel('Value');
    title(labels{i}, 'Interpreter', 'latex');
    set(gcf, 'Position', [300 + 50*i, 200 + 50*i, 600, 300]);  % Cascade figure windows
end
    % Optional: save each plot
    % saveas
