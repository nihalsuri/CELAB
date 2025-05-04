% Script to automate nice plotting from Simulink
clear p i j

% Replace with the name of the output to plot and the filename for the .png
% For different responses with the same reference, enter as an array.
% Supports up to 4 different responses + 1 reference in the same plot (due to different line styles).
% The reference should be the last channel, as this is the only one to be ignored.
% The y-label will be extracted from the first entry.

p.simout = [one ten fifty];  % Replace with your actual Simulink output variables
p.save_name = "nominal_direct";
p.time_start = 0;
p.time_stop  = 2;
% =========================================================================

% Display input
disp("SaveName: " + p.save_name)

% Initialize styles and legends
p.styles = {"-", "--", "-.", ":"};
p.legends = {};

% Create figure
p.f1 = figure(1);
hold on

% Plot the reference signal (assumed to be the last signal in each dataset)
% Plot it only once using the first dataset
p.simout(1).time = p.simout(1).time - p.time_start;
if p.time_start >= p.simout(1).time(end)
    idx_ref = 1:length(p.simout(1).time);
elseif p.time_stop == 0 || p.time_stop > p.simout(1).time(end)
    idx_ref = find(p.simout(1).time >= p.time_start);
else
    idx_ref = find(p.simout(1).time >= p.time_start & p.simout(1).time < p.time_stop);
end
ref_signal = p.simout(1).signals(end);
plot(p.simout(1).time(idx_ref), ref_signal.values(idx_ref), 'LineWidth', 0.75);
p.legends{end + 1} = ref_signal.label;

% Loop over all provided datasets
for i = 1:length(p.simout)
    % Adjust time vector relative to p.time_start
    p.simout(i).time = p.simout(i).time - p.time_start;

    % Determine time window indices for the current dataset
    if p.time_start >= p.simout(i).time(end)
        idx = 1:length(p.simout(i).time);
    elseif p.time_stop == 0 || p.time_stop > p.simout(i).time(end)
        idx = find(p.simout(i).time >= p.time_start);
    else
        idx = find(p.simout(i).time >= p.time_start & p.simout(i).time < p.time_stop);
    end

    % Loop over all signals in the dataset except the last one (reference)
    for j = 1:length(p.simout(i).signals) - 1
        % Determine line style
        style_idx = mod((i - 1) * (length(p.simout(i).signals) - 1) + j - 1, length(p.styles)) + 1;
        line_style = p.styles{style_idx};

        % Plot the signal
        plot(p.simout(i).time(idx), ...
             p.simout(i).signals(j).values(idx), ...
             'LineWidth', 1.5, ...
             'LineStyle', line_style);

        % Append legend entry
        p.legends{end + 1} = p.simout(i).signals(j).label;
    end
end

% Configure plot
grid on
legend(p.legends{:}, 'Location', 'southeast')  % Position legend at bottom-right corner
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

