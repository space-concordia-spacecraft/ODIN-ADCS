% ----------------------------------------------------------------------------
%
%                           function teme2ecef
%
%  this function trsnforms a vector from the true equator mean equniox frame
%    (teme), to an earth fixed (ITRF) frame.  the results take into account
%    the effects of sidereal time, and polar motion.
%
%  author        : david vallado                  719-573-2600   30 oct 2017
%
%  revisions
%
%  inputs          description                    range / units
%    rteme       - position vector teme           km
%    vteme       - velocity vector teme           km/s
%    ateme       - acceleration vector teme (if available, else set to 0)      km/s2
%    ttt         - julian centuries of tt         centuries
%    jdut1       - julian date of ut1             days from 4713 bc
%    lod         - excess length of day           sec
%    xp          - polar motion coefficient       rad
%    yp          - polar motion coefficient       rad
%    eqeterms    - use extra two terms (kinematic) after 1997  0, 2
%
%  outputs       :
%    recef       - position vector earth fixed    km
%    vecef       - velocity vector earth fixed    km/s
%    aecef       - acceleration vector earth fixedkm/s2
%
%  locals        :
%    st          - matrix for pef - tod 
%    pm          - matrix for ecef - pef 
%
%  coupling      :
%   gstime       - greenwich mean sidereal time   rad
%   polarm       - rotation for polar motion      pef - ecef
%
%  references    :
%    vallado       2013, 231-233
%
% [recef, vecef, aecef] = teme2ecef( rteme, vteme, ateme, ttt, jdut1, lod, xp, yp, eqeterms );
% ----------------------------------------------------------------------------

function [recef, vecef, aecef] = teme2ecef( rteme, vteme, ateme, ttt, jdut1, lod, xp, yp, eqeterms )

        deg2rad = pi/180.0;
        
        % ------------------------ find gmst --------------------------
        gmst= gstime( jdut1 );

        % find omega from nutation theory
        omega=  125.04452222  + (   -6962890.5390 *ttt + ...
                7.455 *ttt*ttt + 0.008 *ttt*ttt*ttt )  / 3600.0;
        omega= rem( omega, 360.0  ) * deg2rad;
        
        % ------------------------ find mean ast ----------------------
        % teme does not include the geometric terms here
        % after 1997, kinematic terms apply
        if (jdut1 > 2450449.5 ) && (eqeterms > 0)
            gmstg = gmst ...
                   + 0.00264*pi /(3600*180)*sin(omega) ...
                   + 0.000063*pi /(3600*180)*sin(2.0 *omega);
        else
            gmstg = gmst;
        end

        gmstg = rem (gmstg, 2.0*pi);

        st(1,1) =  cos(gmstg);
        st(1,2) = -sin(gmstg);
        st(1,3) =  0.0;
        st(2,1) =  sin(gmstg);
        st(2,2) =  cos(gmstg);
        st(2,3) =  0.0;
        st(3,1) =  0.0;
        st(3,2) =  0.0;
        st(3,3) =  1.0;

        [pm] = polarm(xp,yp,ttt,'80');

        rpef  = st'*rteme;
        recef = pm'*rpef;

        thetasa    = 7.29211514670698e-05 * (1.0  - lod/86400.0 );
        omegaearth = [0; 0; thetasa;];

        vpef  = st'*vteme - cross( omegaearth,rpef );
        vecef = pm'*vpef;

        temp  = cross(omegaearth,rpef);

        aecef = pm'*(st'*ateme - cross(omegaearth,temp) ...
                - 2.0*cross(omegaearth,vpef));


function [pm] = polarm ( xp, yp, ttt, opt )


        cosxp = cos(xp);
        sinxp = sin(xp);
        cosyp = cos(yp);
        sinyp = sin(yp);

        if (opt == '80')
            pm = zeros(3,3);
            pm(1,1) =  cosxp;
            pm(1,2) =  0.0;
            pm(1,3) = -sinxp;
            pm(2,1) =  sinxp * sinyp;
            pm(2,2) =  cosyp;
            pm(2,3) =  cosxp * sinyp;
            pm(3,1) =  sinxp * cosyp;
            pm(3,2) = -sinyp;
            pm(3,3) =  cosxp * cosyp;

            % a1 = rot2mat(xp);
            % a2 = rot1mat(yp);
            % pm = a2*a1;          
            % Approximate matrix using small angle approximations
            %pm(1,1) =  1.0;
            %pm(2,1) =  0.0;
            %pm(3,1) =  xp;
            %pm(1,2) =  0.0;
            %pm(2,2) =  1.0;
            %pm(3,2) = -yp;
            %pm(1,3) = -xp;
            %pm(2,3) =  yp;
            %pm(3,3) =  1.0;
        else  
            convrt = pi / (3600.0*180.0);
            % approximate sp value in rad
            sp = -47.0e-6 * ttt * convrt;
            cossp = cos(sp);
            sinsp = sin(sp);

            % form the matrix
            pm = zeros(3,3);
            pm(1,1) =  cosxp * cossp;
            pm(1,2) = -cosyp * sinsp + sinyp * sinxp * cossp;
            pm(1,3) = -sinyp * sinsp - cosyp * sinxp * cossp;
            pm(2,1) =  cosxp * sinsp;
            pm(2,2) =  cosyp * cossp + sinyp * sinxp * sinsp;
            pm(2,3) =  sinyp * cossp - cosyp * sinxp * sinsp;
            pm(3,1) =  sinxp;
            pm(3,2) = -sinyp * cosxp;
            pm(3,3) =  cosyp * cosxp;

            % a1 = rot1mat(yp);
            % a2 = rot2mat(xp);
            % a3 = rot3mat(-sp);
            % pm = a3*a2*a1;
        end