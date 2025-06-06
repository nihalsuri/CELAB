% Script to automate nice plotting from simulink
clear p

% Only one response + reference expected (due to single struct)
% If you plan to support more, switch to cell array as explained.

p.simout = out.simout; % sc is a single 1x1 struct
p.fname = "plots/";
p.save_name = "nominal";
p.time_start = 0;
p.time_stop  = 2;

% Display input
disp("SaveName: " + p.save_name)

% Change time window if needed
if p.time_start >= p.simout.time(end)
    p.time_start = 0;
end
if p.time_stop == 0
    p.time_stop = p.simout.time(end);
end

% Extract the relevant time indices
p.idx = find((p.simout.time >= p.time_start & ...
              p.simout.time < p.time_stop));

% Shift time to start at 0
p.simout.time = p.simout.time - p.time_start;

% Get the y-label from the block name
p.ylab = split(p.simout.blockName, "/");
p.ylab = join(p.ylab(2:end), "/");

% Plot setup
p.styles = {"-", "--", "-.", ":"};
p.legends = cell(numel(p.simout.signals), 1);
p.plot_count = 0;

% Create figure
p.f1 = figure(1);
hold on

% Plot reference (assumed to be the last signal)
p.legends{1} = p.simout.signals(end).label;
plot(p.simout.time(p.idx), ...
     p.simout.signals(end).values(p.idx), ...
     "LineWidth", 0.75);

% Plot all other signals
for j = 1:numel(p.simout.signals)-1
    p.plot_count = p.plot_count + 1;

    plot(p.simout.time(p.idx), ...
         p.simout.signals(j).values(p.idx), ...
         "LineWidth", 1.5, ...
         "LineStyle", p.styles{p.plot_count});

    p.legends{1 + p.plot_count} = p.simout.signals(j).label;
end

% Plot settings
grid on
legend(p.legends{:}, 'Location', 'southeast')
xlabel("Time [s]")
ylabel(p.ylab)
ylim("padded")
set(p.f1, 'Position', [300 300 800 400])

% Save figure
saveas(p.f1, fullfile(p.fname, p.save_name) + ".png")