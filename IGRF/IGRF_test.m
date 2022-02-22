time = datenum([Yr Month Day Hr Min Sec]);
lat = 90; % Geodetic latitudes in degrees.
lon = 0; % Geodetic longitudes in degrees.
alt_start = 0; % Altitude in km.


B_ECI = igrf(time,lat,lon,100 );
B = norm(B_ECI);