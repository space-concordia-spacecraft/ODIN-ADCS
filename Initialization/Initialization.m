%% Mission Parameters

%Mission epoch

%Start Date
Yr = 2022;
M = 05;
D = 22;
Hr = 5;
Min = 6;
Sec = 35;

JD_0 = jday(Yr,M,D,Hr,Min,Sec); % Initial julian date for sim

%Stop date

Yr_f = 2022;
M_f = 05;
D_f = 22;
Hr_f = 6;
Min_f = 40;
Sec_f = 35;

startprop = [Yr M D Hr Min Sec]; 
stopprop = [Yr_f M_f D_f Hr_f Min_f Sec_f];

%Initial TLE
% longstr1 = '1 44332U 98067QH  19350.77721468  .00006274  00000-0  10054-3 0  9998';
% longstr2 = '2 44332  51.6386 172.4798 0005656  48.9347 311.2132 15.54514188 2835547';

%ISS TLE

longstr1 = '1 25544U 98067A   22142.84944972  .00009074  00000+0  16902-3 0  9998';
longstr2 = '2 25544  51.6437 102.0782 0004923 144.5877 253.9094 15.49613269341255';

%Earth targets
ground = [1266.06;-4295.81;4526.14]; %ITRF [X;Y;Z] %concordia
argentina = [1612.36;-4182.16;-4522.83]; %ITRF [X;Y;Z]
namibia = [5659.26;1238.85;-2659.2]; %ITRF [X;Y;Z;]

%Initialize SGP4

deltamin = 4;
[r_ecef,v_ecef] = orbit_propagator(longstr1,longstr2,startprop,stopprop,deltamin);

load nut80.dat;

plot3(r(:,1),r(:,2),r(:,3))
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
