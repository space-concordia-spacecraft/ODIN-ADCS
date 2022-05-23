%% Mission Parameters

%Mission epoch
Yr = 2019;
Month = 2;
Day = 19;
Hr = 11;
Min = 07;
Sec = 18;
JD = jday(Yr,Month,Day,Hr,Min,Sec);

%Initial TLE
longstr1 = '1 44332U 98067QH  19350.77721468  .00006274  00000-0  10054-3 0  9998';
longstr2 = '2 44332  51.6386 172.4798 0005656  48.9347 311.2132 15.54514188 2835547';
opsmode = 'i';
whichconst = 84;

%Earth targets
ground = [1266.06;-4295.81;4526.14]; %ITRF [X;Y;Z] %concordia
argentina = [1612.36;-4182.16;-4522.83]; %ITRF [X;Y;Z]
namibia = [5659.26;1238.85;-2659.2]; %ITRF [X;Y;Z;]

%Initialize SGP4

[satrec] = twoline2rv(longstr1, longstr2, opsmode, whichconst);

A = satrec.jdsatepoch;

[satrec,r,v] = sgp4(satrec,14400);

load nut80.dat;


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
