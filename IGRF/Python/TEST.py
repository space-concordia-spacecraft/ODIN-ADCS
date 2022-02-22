#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from scipy import interpolate
import igrf_utils as iut
import io_options_mod as ioo
import numpy as np

degree_sign= u'\N{DEGREE SIGN}'

# Load in the file of coefficients
IGRF_FILE = r'C:\Users\mario\Desktop\Folders\Programming\Python\release/IGRF13.shc'
igrf = iut.load_shcfile(IGRF_FILE, None)

if __name__ == '__main__':

    print('Enter latitude & longitude in decimal degrees')
    LTD, LND = input('-> ').rstrip().split(' ')
    latd = iut.check_float(LTD)
    lond = iut.check_float(LND)

    lat, lon = iut.check_lat_lon_bounds(latd, 0, lond, 0)
    colat = 90 - lat

    alt = input('Enter altitude in km: ').rstrip()
    alt = iut.check_float(alt)
    alt, colat, sd, cd = iut.gg_to_geo(alt, colat)

    while 1:
        date = input('Enter decimal date in years 1900-2025: ').rstrip()
        date = iut.check_float(date)
        if date < 1900 or date > 2030:
            continue
        else:
            break

    # Interpolate the geomagnetic coefficients to the desired date(s)
    # -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    f = interpolate.interp1d(igrf.time, igrf.coeffs, fill_value='extrapolate')
    coeffs = f(date)

    # Compute the main field B_r, B_theta and B_phi value for the location(s)
    Br, Bt, Bp = iut.synth_values(coeffs.T, alt, colat, lon,
                                  igrf.parameters['nmax'])

    # For the SV, find the 5 year period in which the date lies and compute
    # the SV within that period. IGRF has constant SV between each 5 year period
    # We don't need to subtract 1900 but it makes it clearer:
    epoch = (date - 1900) // 5
    epoch_start = epoch * 5
    # Add 1900 back on plus 1 year to account for SV in nT per year (nT/yr):
    coeffs_sv = f(1900 + epoch_start + 1) - f(1900 + epoch_start)
    Brs, Bts, Bps = iut.synth_values(coeffs_sv.T, alt, colat, lon,
                                     igrf.parameters['nmax'])

    # Use the main field coefficients from the start of each five epoch
    # to compute the SV for Dec, Inc, Hor and Total Field (F)
    # [Note: these are non-linear components of X, Y and Z so treat separately]
    coeffsm = f(1900 + epoch_start)
    Brm, Btm, Bpm = iut.synth_values(coeffsm.T, alt, colat, lon,
                                     igrf.parameters['nmax'])

    # Rearrange to X, Y, Z components
    X = -Bt
    Y = Bp
    Z = -Br
    # For the SV
    dX = -Bts
    dY = Bps
    dZ = -Brs
    Xm = -Btm
    Ym = Bpm
    Zm = -Brm

    # Compute the four non-linear components
    dec, hoz, inc, eff = iut.xyz2dhif(X, Y, Z)
    # The IGRF SV coefficients are relative to the main field components
    # at the start of each five year epoch e.g. 2010, 2015, 2020
    decs, hozs, incs, effs = iut.xyz2dhif_sv(Xm, Ym, Zm, dX, dY, dZ)

    # Finally, parse the outputs for writing to screen or file
    print('\nGeomagnetic field values at: ', str(np.round(lat, decimals=4))
        + degree_sign  + ' / ' + str(lon)
        + degree_sign + ', at altitude '
        + str(np.round(alt, decimals=3)) + ' for ' + str(date))
    print('Declination (D):', '{: .3f}'.format(dec), degree_sign)
    print('Inclination (I):', '{: .3f}'.format(inc), degree_sign)
    print('Horizontal intensity (H):', '{: .1f}'.format(hoz), 'nT')
    print('Total intensity (F)     :', '{: .1f}'.format(eff), 'nT')
    print('North component (X)     :', '{: .1f}'.format(X), 'nT')
    print('East component (Y)      :', '{: .1f}'.format(Y), 'nT')
    print('Vertical component (Z)  :', '{: .1f}'.format(Z), 'nT')

    #ioo.write1(date, alt, lat, colat, lon, X, Y, Z, dX, dY, dZ, dec, hoz, inc, eff, decs, hozs, incs, effs)

