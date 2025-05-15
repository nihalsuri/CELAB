% Choose to load parameters estimated from the motor or nominal

if sIn.motor_or_nominal == 0
    % Parameters estimated from motor 1 
    % Motor Friction (lab0)
    mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
    mld.tausf = 0.013;      % [Nm]
    
    % Resonant Load (lab3)
    %mld.Bb = ;
    %mld.k = ;
end