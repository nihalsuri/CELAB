% Script to automate nice plotting from simulink
clear p i j

% Supports up to 4 different responses +1 reference in the same plot 
% (due to different line styles).
%
% Responses can be stored in one or multiple structs. Each struct should
% include a reference on the last channel.
% 
% Supports fixed and variable time (also varying for differnt signals)


p.simout = [ct_nom_rob];
p.fname = "simulation_results\";
p.save_name = "CT_nominal_robust_3x";
p.time_start = 0;
p.time_stop  = 0;
% =========================================================================


% display input
disp("SaveName: "+p.save_name)

% change the timewindow
if p.time_start >= p.simout(1).time(end)
    p.time_start = 0;
end
if p.time_stop == 0
    p.time_stop = p.simout(1).time(end);
end

p.idx = {};
for i=1:length(p.simout)
    p.idx{i} = find((p.simout(i).time >= p.time_start & ...
                  p.simout(i).time < p.time_stop));
    p.simout(i).time = p.simout(i).time - p.time_start;
end




% Get the x-label from the name of the scope
p.ylab = split(p.simout(1).blockName,"/");
p.ylab = join(p.ylab(2:end), "/");

% Plot cell arrays
p.styles = {"-", "--", "-.", ":"};
p.legends = cell(length(p.simout(1).signals),1);
p.plot_count = 0;

% Plot all signals connected to the scope
% Legend entries will be the names of the signals, same as in simulink
p.f1 = figure(1);

hold on
p.legends{1}= p.simout(1).signals(end).label;
plot(p.simout(1).time(p.idx{1}), p.simout(1).signals(end).values(p.idx{1}), ...
            "LineWidth", 0.75);

% loop over all provided datasets
for i=1:length(p.simout)
    % loop over all signals in the datasets
    for j = 1:length(p.simout(i).signals)-1
        % Increment the plot counter - after loops = #plots-reference
        p.plot_count = p.plot_count+1;

        % Plot the j-th signal from the i-th structure
        plot(p.simout(i).time(p.idx{i}), ...
             p.simout(i).signals(j).values(p.idx{i}), ...
            "LineWidth", 1.5, ...
            "LineStyle", p.styles{p.plot_count});
    
        % Add the corresponding label to the legend
        p.legends{1+p.plot_count} = p.simout(i).signals(j).label;
    end
end


grid on
legend(p.legends{:}, 'Location', 'southeast')
xlabel("Time [s]")
ylabel(p.ylab)
ylim("padded")


% a nice dimension to put into a report
set(p.f1,'Position',[300 300 800 400])

%%save figure as a .png file and save the corresponding data
saveas(p.f1, fullfile(p.fname, p.save_name) + ".png");
%save('Data_and_Plots/'+p.save_name+'.mat', "p.simout")