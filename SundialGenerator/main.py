from skyfield import api
from skyfield import timelib
from skyfield.api import wgs84
from skyfield.api import load

import datetime as dt
import csv
import math

year = int(input('Year: '))
timezone = int(input('Timezone(eg. 8 for UTC+8): '))
lat = float(input('Latitude(+ for N, - for S): '))
lon = float(input('Longitude(+ for E, - for W): '))
h = int(input('Height(in pixels): '))

# Convert to timescale
ts = api.load.timescale()

planets = load('de421.bsp')
earth, sun = planets['earth'], planets['sun']
# Input location 2.182721, 102.270318
current_loc = earth + wgs84.latlon(lat, lon)

# Generates a list of coordinates of shadow end points
def coords_gen_daily(year, month, day, loc, timezone, h, inc):
    # Start and end of day
    # Python datetime
    py_start = dt.datetime(year, month, day)
    py_end = py_start + dt.timedelta(days=1)
    # Replacing the value of the timezone in tzinfo class of the object
    py_start = py_start.replace(tzinfo=dt.timezone(dt.timedelta(hours=timezone)))
    py_end = py_end.replace(tzinfo=dt.timezone(dt.timedelta(hours=timezone)))
    # Skyfield time
    ts_start = ts.from_datetime(py_start)
    ts_end = ts.from_datetime(py_end)

    coords = []

    py_temp = py_start
    # Accumulated minutes
    accmin = 0

    while accmin < 24*60:
        ts_temp = ts.from_datetime(py_temp)

        astrometric = loc.at(ts_temp).observe(sun)
        alt, az, d = astrometric.apparent().altaz()
        if alt.degrees > 0:
            r = h/math.tan(alt.degrees*math.pi/180)
            theta = (270-az.degrees)*math.pi/180
            x = r*math.cos(theta)
            y = r*math.sin(theta)
            # Convert to image coords
            x = x+1280/2
            y = -y+720/2
            if (x>0 and x<1280) and (y>0 and y<720):
                coord = (x, y)
                # Update list
                coords.append(coord)

        # increment
        py_temp += dt.timedelta(minutes = inc)
        accmin += inc
    
    return coords

# Analemma shadow at 12pm daily
def coords_gen_anma(year, hour, loc, timezone, h):
    # Start and end of day
    # Python datetime
    py_start = dt.datetime(year, 1, 1, hour)
    # Replacing the value of the timezone in tzinfo class of the object
    py_start = py_start.replace(tzinfo=dt.timezone(dt.timedelta(hours=timezone)))
    # Skyfield time
    ts_start = ts.from_datetime(py_start)

    coords = []

    py_temp = py_start
    # Accumulated days
    accday = 0

    while accday < 365:
        ts_temp = ts.from_datetime(py_temp)

        astrometric = loc.at(ts_temp).observe(sun)
        alt, az, d = astrometric.apparent().altaz()
        if alt.degrees > 0:
            r = h/math.tan(alt.degrees*math.pi/180)
            theta = (270-az.degrees)*math.pi/180
            x = r*math.cos(theta)
            y = r*math.sin(theta)
            # Convert to image coords
            x = x+1280/2
            y = -y+720/2
            # Update list
            coord = (x, y)
            coords.append(coord)

        # increment
        py_temp += dt.timedelta(days = 1)
        accday += 1
    
    return coords

# print(coords_gen_daily(year, 5, 1, current_loc, 8, 10, 30))



# Import image generation libraries
from PIL import Image, ImageDraw

# Generate line markers for every x minutes, define function
def marker_line(draw_im, year, month, day, loc, timezone, h, inc, marker_len, color):
    l = marker_len
    marks = coords_gen_daily(year, month, day, loc, timezone, h, inc)
    for i in marks:
        start = (i[0], i[1]+l/2)
        end = (i[0], i[1]-l/2)
        draw_im.line((start, end), color, 1)

# Generate circle markers for every x minutes, define function
def marker_circle(draw_im, year, month, day, loc, timezone, h, inc, marker_r, color):
    r = marker_r
    marks = coords_gen_daily(year, month, day, loc, timezone, h, inc)
    for i in marks:
        start = (i[0]-r/2, i[1]-r/2)
        end = (i[0]+r/2, i[1]+r/2)
        draw_im.ellipse((start, end), color)

# Draw cross for coord, size as in length/2
def cross(draw_im, coords, color, size):
    line1 = ((coords[0]-size, coords[1]-size), (coords[0]+size, coords[1]+size))
    line2 = ((coords[0]-size, coords[1]+size), (coords[0]+size, coords[1]-size))
    draw_im.line(line1, color, 1)
    draw_im.line(line2, color, 1)

# Create image
sundial = Image.new('RGB', (1280, 720), (255, 255, 255))
d_im = ImageDraw.Draw(sundial)
print('Generating sundial... |------------------| (0/18)')

# Shadow analemma for 11am
analemma_11 = coords_gen_anma(year, 11, current_loc, timezone, h)
# Check coords
proceed_print = True
for i in analemma_11:
    x = i[0]
    y = i[1]
    if not((x>0 and x<1280) and (y>0 and y<720)):
        proceed_print = False
        break
# Print curve if applies
if proceed_print:
    # Curve
    d_im.line(analemma_11, (200, 200, 200), 1, 'curve')

    # Print words
    summersol_11 = dt.datetime(year, 6, 21, 11)
    # Replacing the value of the timezone in tzinfo class of the object
    summersol_11 = summersol_11.replace(tzinfo=dt.timezone(dt.timedelta(hours=timezone)))
    # Skyfield time
    ts_summersol_11 = ts.from_datetime(summersol_11)
    astrometric = current_loc.at(ts_summersol_11).observe(sun)
    alt, az, d = astrometric.apparent().altaz()
    # Calculations
    r = h/math.tan(alt.degrees*math.pi/180)
    theta = (270-az.degrees)*math.pi/180
    x = r*math.cos(theta)
    y = r*math.sin(theta)
    # Convert to image coords
    x = x+1280/2
    y = -y+720/2
    # Print words
    d_im.text((x-10, y+5), '11am', (0, 0, 0))
print("\033[A\033[A")
print('Generating sundial... |#-----------------| (1/18)')

# Shadow analemma for 12pm
analemma_12 = coords_gen_anma(year, 12, current_loc, timezone, h)
# Check coords
proceed_print = True
for i in analemma_12:
    x = i[0]
    y = i[1]
    if not((x>0 and x<1280) and (y>0 and y<720)):
        proceed_print = False
        break
# Print curve if applies
if proceed_print:
    # Curve
    d_im.line(analemma_12, (150, 150, 150), 1, 'curve')

    # Print words
    summersol_12 = dt.datetime(year, 6, 21, 12)
    # Replacing the value of the timezone in tzinfo class of the object
    summersol_12 = summersol_12.replace(tzinfo=dt.timezone(dt.timedelta(hours=timezone)))
    # Skyfield time
    ts_summersol_12 = ts.from_datetime(summersol_12)
    astrometric = current_loc.at(ts_summersol_12).observe(sun)
    alt, az, d = astrometric.apparent().altaz()
    # Calculations
    r = h/math.tan(alt.degrees*math.pi/180)
    theta = (270-az.degrees)*math.pi/180
    x = r*math.cos(theta)
    y = r*math.sin(theta)
    # Convert to image coords
    x = x+1280/2
    y = -y+720/2
    # Print words
    d_im.text((x-5, y+5), '12pm', (0, 0, 0))
print("\033[A\033[A")
print('Generating sundial... |##----------------| (2/18)')


# Shadow analemma for 1pm
analemma_13 = coords_gen_anma(year, 13, current_loc, timezone, h)
# Check coords
proceed_print = True
for i in analemma_13:
    x = i[0]
    y = i[1]
    if not((x>0 and x<1280) and (y>0 and y<720)):
        proceed_print = False
        break
# Print curve if applies
if proceed_print:
    # Curve
    d_im.line(analemma_13, (200, 200, 200), 1, 'curve')

    # Print words
    summersol_13 = dt.datetime(year, 6, 21, 13)
    # Replacing the value of the timezone in tzinfo class of the object
    summersol_13 = summersol_13.replace(tzinfo=dt.timezone(dt.timedelta(hours=timezone)))
    # Skyfield time
    ts_summersol_13 = ts.from_datetime(summersol_13)
    astrometric = current_loc.at(ts_summersol_13).observe(sun)
    alt, az, d = astrometric.apparent().altaz()
    # Calculations
    r = h/math.tan(alt.degrees*math.pi/180)
    theta = (270-az.degrees)*math.pi/180
    x = r*math.cos(theta)
    y = r*math.sin(theta)
    # Convert to image coords
    x = x+1280/2
    y = -y+720/2
    # Print words
    d_im.text((x, y+5), '1pm', (0, 0, 0))
print("\033[A\033[A")
print('Generating sundial... |###---------------| (3/18)')

# Winter solistice
# Curve
d_im.line(coords_gen_daily(year, 12, 21, current_loc, timezone, h, 5), (50, 75, 164), 1, 'curve')
# Hourly
marker_circle(d_im, year, 12, 21, current_loc, timezone, h, 60, 3, (50, 75, 164))
print("\033[A\033[A")
print('Generating sundial... |####--------------| (4/18)')

# Summer solistice
# Curve
d_im.line(coords_gen_daily(year, 6, 21, current_loc, timezone, h, 5), (164, 129, 50), 1, 'curve')
# Hourly
marker_circle(d_im, year, 6, 21, current_loc, timezone, h, 60, 3, (164, 129, 50))
print("\033[A\033[A")
print('Generating sundial... |#####-------------| (5/18)')

# Monthly
for month in range(1, 13):
    day = 1
    color = (0, 0, 0)
    if month < 7:
        color = (241, 190, 74)
    else:
        color = (74, 134, 241)
    # Curve
    d_im.line(coords_gen_daily(year, month, day, current_loc, timezone, h, 5), color, 1, 'curve')
    # Hourly
    marker_circle(d_im, year, month, day, current_loc, timezone, h, 60, 3, color)

    print("\033[A\033[A")
    print('Generating sundial... |#####', end='')
    for i in range(month):
        print('#', end='')
    for i in range(13-month):
        print('-', end='')
    print('| (', end='')
    print(str(month+5), end='')
    print('/18)')



# Legend
# Bounding box
d_im.rectangle((0, 0, 250, 150), (255, 255, 255), (0, 0, 0), 2)
# Stick length
d_im.line(((10, 10), (10+h, 10)), (0, 0, 0), 2)
d_im.text((10, 18), 'Length of object', (0, 0, 0))
# How to read 1
for i in range(6):
    d_im.line((10, 40+i*15, 40, 40+i*15), (241, 190, 74), 1)
    d_im.ellipse((25-3/2, 40+i*15-3/2, 25+3/2, 40+i*15+3/2), (241, 190, 74))
d_im.line((10, 40+6*15, 40, 40+6*15), (164, 129, 50), 1)
d_im.ellipse((25-3/2, 40+6*15-3/2, 25+3/2, 40+6*15+3/2), (164, 129, 50))
first_half = ['Jan 1st', 'Feb 1st', 'Mar 1st', 'Apr 1st', 'May 1st', 'Jun 1st', 'Summer sol.']
for i in range(7):
    d_im.text((50, 35+i*15), first_half[i], (0, 0, 0))
# How to read 2
for i in range(1, 7):
    d_im.line((120+10, 40+i*15, 120+40, 40+i*15), (74, 134, 241), 1)
    d_im.ellipse((120+25-3/2, 40+i*15-3/2, 120+25+3/2, 40+i*15+3/2), (74, 134, 241))
d_im.line((120+10, 40, 120+40, 40), (50, 75, 164), 1)
d_im.ellipse((120+25-3/2, 40-3/2, 120+25+3/2, 40+3/2), (50, 75, 164))
second_half = ['Winter sol.', 'Dec 1st', 'Nov 1st', 'Oct 1st', 'Sep 1st', 'Aug 1st', 'Jul 1st']
for i in range(7):
    d_im.text((120+50, 35+i*15), second_half[i], (0, 0, 0))
# Compass
d_im.line((230, 130, 230, 100, 220, 120, 240, 120), (0, 0, 0), 3)
d_im.text((229, 87), 'N', (0, 0, 0))
print("\033[A\033[A")
print('Generating sundial... |##################| (18/18)')

# Location to put the stick
cross(d_im, (1280/2, 720/2), (0, 0, 0), 2)

sundial.save('sundial.png', bitmap_format='png')
print('Complete')