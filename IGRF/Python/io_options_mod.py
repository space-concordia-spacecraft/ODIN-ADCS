#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr  2 22:54:35 2020

@author: Ciaran Beggan (British Geological Survey)

A set of functions to parse the three input options of the IGRF code
         '1 - values at one or more locations & dates'
         '2 - values at yearly intervals at one location'
         '3 - values on a latitude/longitude grid at one date'

"""

import igrf_utils as iut
import numpy as np

degree_sign= u'\N{DEGREE SIGN}'

def option1():

    print( 'Enter latitude & longitude in decimal degrees')
    LTD,LND = input('-> ').rstrip().split(' ')
    latd = iut.check_float(LTD)
    lond = iut.check_float(LND)

    lat, lon = iut.check_lat_lon_bounds(latd,0,lond,0)
    colat = 90-lat

    alt = input( 'Enter altitude in km: ').rstrip()
    alt = iut.check_float(alt)
    alt, colat, sd, cd = iut.gg_to_geo(alt, colat)

        
    while 1: 
        date = input('Enter decimal date in years 1900-2025: ').rstrip()
        date = iut.check_float(date)
        if date < 1900 or date > 2030: continue
        else:
            break   

    return date, alt, lat, colat, lon, sd, cd

def write1(date, alt, lat, colat, lon, X, Y, Z, dX, dY, dZ, \
                  dec, hoz, inc, eff, decs, hozs, incs, effs):

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
    print('Declination SV (D):', '{: .2f}'.format(decs), 'arcmin/yr')
    print('Inclination SV (I):', '{: .2f}'.format(incs), 'arcmin/yr')
    print('Horizontal SV (H):', '{: .1f}'.format(hozs), 'nT/yr')
    print('Total SV (F)     :', '{: .1f}'.format(effs), 'nT/yr')
    print('North SV (X)     :', '{: .1f}'.format(dX), 'nT/yr')
    print('East SV (Y)      :', '{: .1f}'.format(dY), 'nT/yr')
    print('Vertical SV (Z)  :', '{: .1f}'.format(dZ), 'nT/yr')

            
