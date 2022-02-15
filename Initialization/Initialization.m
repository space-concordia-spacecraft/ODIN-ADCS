%% Mission Parameters

<<<<<<< Updated upstream
=======
%Mission epoch
Yr = 2000;
Month = 01;
Day = 01;
Hr = 12;
Min = 00;
Sec = 00;
JD = jday(Yr,Month,Day,Hr,Min,Sec);
>>>>>>> Stashed changes

%Initial TLE

%% Spacecraft mass properties

%Mass

%Inertia
J =[0.04582275 0 0;
    0 0.04561065 0;
    0 0 0.0085932349] ;

%% Components orientation with respect to spacecraft

% Sun sensor

% Magnetometer

% Reaction Wheels

% Magnetorquers

%% Reaction Wheels characteristics

Jw = 2.029e-6; % Wheel Inertia

f = 4.55e-6;% Viscous Damping

%
