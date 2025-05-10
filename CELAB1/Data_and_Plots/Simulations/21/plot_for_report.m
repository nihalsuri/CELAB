% Script to automate nice plotting from simulink
clear p i j


% Replace with the name of the output to plot and the filename for the .png
% for different responses with same reference, enter as array. Supports up
% to 4 different responses +1 reference in the same plot (due to different
% line styles).
% The reference should be the last channel as this is the only one to be
% ignored.
% the y-label will be extracted form the first entry.

p.simout = [theta_pid, theta_aw];
p.save_name = "simulation_aw_comparison_theta";
p.time_start = 0;
p.time_stop  = 1;
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
p.idx = find((p.simout(1).time >= p.time_start & ...
              p.simout(1).time < p.time_stop));
p.simout(1).time = p.simout(1).time - p.time_start;


% Get the x-label from the name of the scope
p.ylab = split(p.simout(1).blockName,"/");
p.ylab = join(p.ylab(2:end), "/");

% Plot cell arrays
p.styles = {"-", "--", "-.", ":"};
p.legends = cell(length(p.simout(1).signals),1);

% Plot all signals connected to the scope
% Legend entries will be the names of the signals, same as in simulink
p.f1 = figure(1);

hold on
p.legends{1}= p.simout(1).signals(end).label;
plot(p.simout(1).time(p.idx), p.simout(1).signals(end).values(p.idx), ...
            "LineWidth", 0.75);

% loop over all provided datasets
for i=1:length(p.simout)
    % loop over all signals in the datasets
    for j = 1:length(p.simout(i).signals)-1
        plot(p.simout(1).time(p.idx), ...
             p.simout(i).signals(j).values(p.idx), ...
            "LineWidth", 1.5, ...
            "LineStyle", p.styles{((i-1)*(length(p.simout(i).signals)-1)+j)});
    
        p.legends{1+((i-1)*(length(p.simout(i).signals)-1)+j)} = ...
            p.simout(i).signals(j).label;
    end
end


grid on
legend(p.legends{:})
xlabel("Time [s]")
ylabel(p.ylab)
ylim("padded")


% a nice dimension to put into a report
set(p.f1,'Position',[300 300 800 400])

%%save figure as a .png file and save the corresponding data
saveas(p.f1, p.save_name+'.png')
%save('Data_and_Plots/'+p.save_name+'.mat', "p.simout")