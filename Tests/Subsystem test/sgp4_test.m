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

%Initialize SGP4

[satrec] = twoline2rv(longstr1, longstr2, opsmode, whichconst);

A = satrec;

[satrec,r,v] = sgp4(satrec,1440);