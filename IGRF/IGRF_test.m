time = datenum([Yr Month Day Hr Min Sec]);
lat = 30; % Geodetic latitudes in degrees.
lon = 330; % Geodetic longitudes in degrees.
alt_start = 0; % Altitude in km.


B_ECI = igrf(time,lat,lon,100 );