function [recef,vecef,t] = orbit_propagator(longstr1,longstr2,startprop,stopprop,deltamin)

opsmode = 'i';
whichconst = 84;

[startmfe,stopmfe,satrec] = twoline2rv(longstr1, longstr2,'m','e', opsmode, whichconst,startprop,stopprop); %initialise for SGP4

 %               // call the propagator to get the initial state vector value
 [satrec, rteme ,vteme] = sgp4 (satrec,  0.0);
 
 tsince = startmfe;

  %                // check so the first value isn't written twice
    if ( abs(tsince) > 1.0e-8 )
        tsince = tsince - deltamin;
    end
    
% set some EOP parameter that stay constant
            conv = pi / (180.0*3600.0);
            eqeterms = 2;  % terms for equation of the equinoxes
            
N = floor((stopmfe - startmfe)/deltamin);
recef = zeros(N,3);
vecef = zeros(N,3);
decef = zeros(N,3);
t = zeros(N,1);

i = 1;
            % // loop to perform the propagation
while ((tsince < stopmfe) && (satrec.error == 0))
    
    tsince = tsince + deltamin;
    t(i) = tsince;
    
    if(tsince > stopmfe)
        tsince = stopmfe;
    end

    [satrec, rteme, vteme] = sgp4 (satrec,  tsince);

    if (satrec.error == 0)
            jdutc = satrec.jdsatepoch;
            jdutcfrac = satrec.jdsatepochf + tsince/1440.0;
            if jdutcfrac < 0.0
                jdutc = jdutc - 1.0;
                jdutcfrac = jdutcfrac + 1.0;
            end
            [year,mon,day,hr,minute,sec] = invjday ( jdutc, jdutcfrac );
            
            % demo getting lat lon
            % set the EOP parameters. normally this would be at each time instant in the loop, but
            % we'll keep it constant here for illustration
            lod = 0.0015563; % sec
            xp   = -0.140682 * conv;  % polar motion values in rad from arcsec
            yp   =  0.333309 * conv;
            dut1 = -0.4399619;  % sec
            jdut1 = jdutc;
            jdut1frac = jdutcfrac + dut1/86400.0;
            ttt = (jdut1-2451545.0)/36525.0;
            ateme = [0.0 0.0 0.0];
            [r, v, aecef] = teme2ecef( rteme', vteme', ateme', ttt, jdut1, lod, xp, yp, eqeterms );
            %[latgc,latgd,lon,hellp] = ijk2ll ( recef );

            recef(i,1) = r(1);
            recef(i,2) = r(2);
            recef(i,3) = r(3);
            vecef(i,1) = v(1);
            vecef(i,2) = v(2);
            vecef(i,3) = v(3);
            
            decef(i) = norm(r);
            i = i + 1 ;

       
    end % if satrec.error == 0

end % while 

end

