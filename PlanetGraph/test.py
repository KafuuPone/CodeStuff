from skyfield import api
from skyfield import timelib
from skyfield import positionlib
from skyfield import almanac
from skyfield.api import wgs84
from skyfield.api import load

import datetime as dt

year = 2021
month = 12
day = 25
lat, lon = 121.52, 25.10

ts = api.load.timescale()

planets = load('de421.bsp')
earth, sun, mars = planets['earth'], planets['sun'], planets['mars barycenter']
current_loc = earth + wgs84.latlon(lat, lon)

py_time = dt.datetime(year, month, day)
py_time = py_time.replace(tzinfo=dt.timezone(dt.timedelta(hours=0)))
t = ts.from_datetime(py_time)
astrometric = current_loc.at(t).observe(mars)
ra, dec, distance = astrometric.radec(epoch=t)
alt, az, d = astrometric.apparent().altaz()
print(alt)
print(az)
print(ra)
print(dec)
print(distance)