%% Mission Parameters

%Mission epoch
Yr = 2009;
Month = 04;
Day = 02;
Hr = 11;
Min = 07;
Sec = 18;
JD = jday(Yr,Month,Day,Hr,Min,Sec);

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

%% Actuators

% Reaction Wheels characteristics

Jw = 2.029e-6; % Wheel Inertia

f = 4.55e-6;% Viscous Damping

% Magnetorquer

m_max = 0.24; % Am2
