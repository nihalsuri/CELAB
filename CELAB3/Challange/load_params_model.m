%% Updated Values

if sIn.motor_or_blackbox_params == 0
    % Parameters estimated from motor 1 
    % Motor Friction (lab0)
    mld.Beq = 2.5663e-6;    % [Nm/(rad/s)]
    mld.tausf = 0.013;      % [Nm]
    
    % Resonant Load (lab3)
    %mld.Bb = ;
    %mld.k = ;
    
else
    % Blackbox
    % Motor Friction (lab0)
    mld.Beq = 1.2224e-6;    % [Nm/(rad/sec)] 
    mld.tausf = 0.0056;     % [Nm]
    
    % Resonant Load (lab3)
    mld.Bb = 0.00508;
    mld.k = 87153;
end



%% Transfer function parameters
% Transfer function tau_m -> theta_hub
% denominator missing an integrator => to extract omega
sIn.num_taum_thh = [mld.Jb, mld.Bb, mld.k];

sIn.den_taum_thh = gbox.N*[mld.Jeq*mld.Jb, ...
    (mld.Jeq*mld.Bb+mld.Jb*mld.Beq), ... 
    (mld.Beq*mld.Bb+mld.k*(mld.Jeq+mld.Jb/gbox.N^2)), ...
    mld.k*(mld.Beq+mld.Bb/gbox.N^2)];

% Transfer function tau_m ->theta_beam
sIn.num_taum_thb = mld.k;
sIn.den_taum_thb = [sIn.den_taum_thh, 0]; % include integrator directly