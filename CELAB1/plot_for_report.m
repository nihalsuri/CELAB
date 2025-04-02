% Script to automate nice plotting from simulink
clear simout legends xlab f1 save_name


% Replace with the name of the output to plot and the filename for the .png
simout = betterpid_omega_m;
save_name = "windup_sim";
% =========================================================================




% Get the x-label from the name of the scope
xlab = split(simout.blockName,"/");
xlab = xlab(end);

% Initialize cellarray
legends = cell(length(simout.signals),1);

% Plot all signals connected to the scope
% Legend entries will be the names of the signal, same as in simulink
f1 = figure(1);
hold on
for i=1:length(simout.signals)
    plot(simout.time, simout.signals(i).values, "LineWidth", 1.5)
    legends{i} = simout.signals(i).label;
end
grid on
legend(legends{:})
xlabel("Time [s]")
ylabel(xlab)
% a nice dimension to put into a report
set(f1,'Position',[300 300 800 400])

% save figure as a .png file and save the corresponding data
%saveas(f1, 'Data_and_Plots/'+save_name+'.png')
%save('Data_and_Plots/'+save_name+'.mat', "simout")