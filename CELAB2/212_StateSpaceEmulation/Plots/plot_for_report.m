% Script to automate nice plotting from Simulink
clear p i j

% Replace with the name of the output to plot and the filename for the .png
% For different responses with the same reference, enter as an array.
% Supports up to 4 different responses + 1 reference in the same plot (due to different line styles).
% The reference should be the last channel, as this is the only one to be ignored.
% The y-label will be extracted from the first entry.

p.simout = [one two three];  % Replace with your actual Simulink output variables
p.save_name = "backward";
p.time_start = 0;
p.time_stop  = 1;
% =========================================================================

% Display input
disp("SaveName: " + p.save_name)

% Initialize styles and legends
p.styles = {"-", "--", "-.", ":"};
p.legends = {};

% Create figure
p.f1 = figure(1);
hold on

% Plot the reference signal (assumed to be the last signal in the first dataset)
ref_signal = p.simout(1).signals(end);
ref_time = p.simout(1).time - p.time_start;

% Determine time window indices for the reference signal
if p.time_start >= ref_time(end)
    idx_ref = 1:length(ref_time);
elseif p.time_stop == 0 || p.time_stop > ref_time(end)
    idx_ref = find(ref_time >= p.time_start);
else
    idx_ref = find(ref_time >= p.time_start & ref_time < p.time_stop);
end

% Plot the reference signal
stairs(ref_time(idx_ref), ref_signal.values(idx_ref), 'k', 'LineWidth', 0.75);
p.legends{end + 1} = ref_signal.label;

% Loop over all provided datasets
for i = 1:length(p.simout)
    % Adjust time vector relative to p.time_start
    time = p.simout(i).time - p.time_start;

    % Determine time window indices for the current dataset
    if p.time_start >= time(end)
        idx = 1:length(time);
    elseif p.time_stop == 0 || p.time_stop > time(end)
        idx = find(time >= p.time_start);
    else
        idx = find(time >= p.time_start & time < p.time_stop);
    end

    % Loop over all signals in the dataset, excluding the last (reference) signal
    for j = 1:length(p.simout(i).signals) - 1
        % Determine line style
        style_idx = mod((i - 1) * (length(p.simout(i).signals) - 1) + j - 1, length(p.styles)) + 1;
        line_style = p.styles{style_idx};

        % Plot the signal
        stairs(time(idx), ...
             p.simout(i).signals(j).values(idx), ...
             'LineWidth', 1.5, ...
             'LineStyle', line_style);

        % Append legend entry
        p.legends{end + 1} = p.simout(i).signals(j).label;
    end
end

% Configure plot
grid on
legend(p.legends{:})
xlabel("Time [s]")

% Extract y-label from the name of the scope
p.ylab = split(p.simout(1).blockName, "/");
p.ylab = join(p.ylab(2:end), "/");
ylabel(p.ylab)

ylim("padded")

% Set figure dimensions for report
set(p.f1, 'Position', [300 300 800 400])

% Save figure as a .png file
if ~exist('clean_figures', 'dir')
    mkdir('clean_figures');
end
filename = fullfile('clean_figures', [char(p.save_name), '.png']);
saveas(p.f1, filename);
