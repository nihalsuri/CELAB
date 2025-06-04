% =========================================================================
% Plot all valid "Structure With Time" outputs from Simulink `out`
% =========================================================================
clearvars -except out

% === USER SETTINGS =======================================================
p.save_name   = "SimOutPlot";   % Save figure as this name
p.time_start  = 0;              % Start time (s)
p.time_stop   = 0;              % 0 = until end of sim
p.filter_keys = {};             % Optional: {"Theta"} to only include matching fields
% =========================================================================

disp("Plotting outputs from Simulink struct: 'out'")

% === Find all valid fields in `out` that are "Structure With Time" ===
vars = fieldnames(out);
p.simout = [];

for i = 1:length(vars)
    if strcmp(vars{i}, "SimulationMetadata") || strcmp(vars{i}, "ErrorMessage")
        continue
    end

    s = out.(vars{i});

    if isstruct(s) && isfield(s, "time") && isfield(s, "signals")
        if isempty(p.filter_keys) || any(contains(vars{i}, p.filter_keys))
            p.simout(end+1) = s; %#ok<SAGROW>
            p.simout(end).blockName = vars{i};  % store name for labeling
        end
    end
end

if isempty(p.simout)
    error("No valid 'Structure With Time' signals found inside 'out'.")
end

% === Time trim ===
if p.time_start >= p.simout(1).time(end)
    p.time_start = 0;
end
if p.time_stop == 0
    p.time_stop = p.simout(1).time(end);
end

for i = 1:length(p.simout)
    p.idx{i} = find(p.simout(i).time >= p.time_start & ...
                    p.simout(i).time <= p.time_stop);
    p.simout(i).time = p.simout(i).time - p.time_start;
end

% === Get Y-label ===
try
    p.ylab = p.simout(1).signals(1).label;
catch
    p.ylab = p.simout(1).blockName;
end

% === Plot Settings ===
p.styles = {"-", "--", "-.", ":"};
p.legends = {};
p.plot_count = 0;

p.f1 = figure(1); clf
hold on

for i = 1:length(p.simout)
    nsig = length(p.simout(i).signals);
    for j = 1:nsig
        p.plot_count = p.plot_count + 1;
        style = p.styles{mod(p.plot_count-1, length(p.styles)) + 1};
        values = squeeze(p.simout(i).signals(j).values);

        plot(p.simout(i).time(p.idx{i}), ...
             values(p.idx{i}), ...
             'LineWidth', 1.5, ...
             'LineStyle', style);

        if isfield(p.simout(i).signals(j), "label") && ~isempty(p.simout(i).signals(j).label)
            p.legends{end+1} = p.simout(i).signals(j).label;
        else
            p.legends{end+1} = p.simout(i).blockName + " - Signal " + j;
        end
    end
end

grid on
legend(p.legends{:}, 'Location', 'best')
xlabel("Time [s]")
ylabel(p.ylab)
ylim padded
set(p.f1, 'Position', [300 300 800 400])

% Save the figure
saveas(p.f1, p.save_name + ".png")
