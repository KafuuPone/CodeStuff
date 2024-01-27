from skyfield import api
from skyfield import timelib
from skyfield import almanac
from skyfield.api import wgs84
from skyfield.api import load

import datetime as dt
import numpy as np
import matplotlib as plt

year = int(input('Year: '))
timezone = int(input('Timezone(eg. 8 for UTC+8): '))
# lat = float(input('Latitude(+ for N, - for S): '))
# lon = float(input('Longitude(+ for E, - for W): '))
lat, lon = 2.182721, 102.270318

# Convert to timescale
ts = api.load.timescale()

planets = load('de421.bsp')
invalid_planet = ['earth', 'sun']
earth, sun = planets['earth'], planets['sun']
planet_name = input('Planet: ')
while planet_name.lower() in invalid_planet:
    print("Invalid planet.")
    planet_name = input('Planet: ')
planet = planets[f'{planet_name} BARYCENTER']
current_loc = earth + wgs84.latlon(lat, lon)

# Initialize time
py_time_start = dt.datetime(year, 1, 1)
py_time_start = py_time_start.replace(tzinfo=dt.timezone(dt.timedelta(hours=timezone)))
t_start = ts.from_datetime(py_time_start) # Skyfield time
py_time_end = dt.datetime(year+1, 1, 1)
py_time_end = py_time_end.replace(tzinfo=dt.timezone(dt.timedelta(hours=timezone)))
t_end = ts.from_datetime(py_time_end) # Skyfield time

# List of sunrise and sunset times of the year
t_sunrise, y1 = almanac.find_risings(current_loc, sun, t_start, t_end)
t_sunset, y2 = almanac.find_settings(current_loc, sun, t_start, t_end)