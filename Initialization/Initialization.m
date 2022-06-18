%% Mission Parameters

%Mission epoch

%Start Date
Yr = 2022;
M = 05;
D = 21;
Hr = 0;
Min = 0;
Sec = 0;

[JD_0,jd_frac] = jday(Yr,M,D,Hr,Min,Sec); % Initial julian date for sim
JD_0 = JD_0 + jd_frac;

%Stop date

Yr_f = 2022;
M_f = 05;
D_f = 25;
Hr_f = 22;
Min_f = 0;
Sec_f = 0;

startprop = [Yr M D Hr Min Sec]; % Array  with the start date for the orbit propagator
stopprop = [Yr_f M_f D_f Hr_f Min_f Sec_f]; % Array  with the end date for the orbit propagator

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

%% Orbit propagator

deltamin = 1; %Sample time for SGP4 orbit propagator in minutes

% SGP4 orbit propagator 
[r_ecef,v_ecef,tsince] = orbit_propagator(longstr1,longstr2,startprop,stopprop,deltamin);

t_orbit = tsince - tsince(1,1);

orbit_param = [tsince r_ecef v_ecef];

load nut80.dat;

plot3(r_ecef(:,1),r_ecef(:,2),r_ecef(:,3))

LLA = zeros(length(r_ecef),3);
[~,LLA(:,1),LLA(:,2),LLA(:,3)] = ecef2llb(r_ecef(1));
%% Spacecraft mass properties

%Mass

%Inertia
J =[0.04582275 0 0;
    0 0.04561065 0;
    0 0 0.0085932349] ;

%% Components orientation with respect to spacecraft

% Sun sensor

Tsun_bs = [1 0 0;
            0 1 0;
            0 0 1];

% Magnetometer

Tmag_bs = [1 0 0;
            0 1 0;
            0 0 1];

% Reaction Wheels

% Magnetorquers

%Payload

%Payload FOV

payload_fov = 10; %FOV in deg

%% Actuators

% Reaction Wheels characteristics

Jw = 2.0292e-06; % Wheel Inertia

f = 4.55e-6;% Viscous Damping

% Magnetorquer

m_max = 0.24; % Am2

%% Disturbances
%Atmospheric Drag

A = 0.2*0.3; %m^2
Cd = 2.0; %dimensionless
L = [0.0000812 -0.0022136 -0.0225868]; %m
V_Vec = [7600 1 0]; %m/s / Not the real reference frame

%Gravity Gradient

Ra = 6721000;
G = 6.67408e-11; %Gravitational Constant (m^3*kg^-1*s^-2)
M = 5.9722e24;  %Mass of Earth (kg)

%Solar Radiation Pressure

As = 0.2*0.3 ; %Sunlit Area
c = 2.99792458e8; %Speed of Light (m/s)
q = 0.6; %Unitless Reflectance Factor (Varies from 0 to 1)
Ks = 1367; %Solar Constant (W/m^2)
Ls =0.01*[-3; 3; 5]; %Vector from center of mass to center of pressure

D=0.01*[1;1;1];%overall residual dipole
