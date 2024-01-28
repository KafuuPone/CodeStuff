from skyfield import api
from skyfield import timelib
from skyfield import almanac
from skyfield.api import wgs84
from skyfield.api import load

import datetime as dt
import numpy as np
import matplotlib.pyplot as plt

year = int(input('Year: '))
timezone = int(input('Timezone(eg. 8 for UTC+8): '))
lat = float(input('Latitude(+ for N, - for S): '))
lon = float(input('Longitude(+ for E, - for W): '))
# lat, lon = 2.182721, 102.270318

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

# User chooses which to view
choice = input("Input 0 for sunrise, 1 for sunset: ")
time_list = []
if choice == '0':
    time_list = t_sunrise
elif choice == '1':
    time_list = t_sunset

# Gets list of coords on the horizon for sunrise and sunset time
altaz = []
for t in time_list:
    astrometric = current_loc.at(t).observe(planet)
    alt, az, d = astrometric.apparent().altaz()
    altaz.append([alt.degrees, az.degrees])
altaz = np.array(altaz)

# Plot the altitude and azimuth
plt.figure(figsize=(8, 6))
plt.plot(altaz[:, 1], altaz[:, 0], color='#81332C') 
plt.xlabel('Azimuth')
plt.ylabel('Altitude')
plt.grid(True)

# Calculating y_max
y_max = (max(altaz[:, 0])//10+1)*10

x_limit = [0, 360]
y_limit = [0, y_max]
plt.xlim(x_limit[0], x_limit[1])
plt.ylim(y_limit[0], y_limit[1])

# Set the coordinate grid spacing to 30 units
plt.xticks(np.arange(x_limit[0], x_limit[1]+0.1, 30))  # Set x-axis ticks with spacing of 0.1
plt.yticks(np.arange(y_limit[0], y_limit[1]+0.1, 10))  # Set y-axis ticks with spacing of 0.1

# Customize the appearance of the grid
plt.grid(True, linestyle='--', alpha=0.5)  # Add dashed grid lines with transparency

plt.show()