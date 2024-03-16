import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import os
from datetime import datetime

current_dir = os.getcwd() # current directory
current_date = str(datetime.now().date())
if (input('Plot data for today? (y/n) ')).lower() != 'y':
    current_date = input('Year: ') + '-' + f"{int(input('Month: ')):02}" + '-' + f"{int(input('Day: ')):02}"

filepath = f'{current_dir}\\BatteryLog\\{current_date}.npy'

if os.path.exists(filepath):
    data = np.load(filepath, allow_pickle=True)
    dates = mdates.date2num(data[0])
    battery = data[1]
    # display modes
    fmt, linewidth = '.-', 0.5
    if (input('View marker? (y/n) ')).lower()!='y':
        fmt, linewidth = '-', 1
    disp_mode = (fmt, linewidth)
    plt.plot_date(dates, battery, fmt=disp_mode[0], linewidth=disp_mode[1], markersize=3)
    plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%H:%M'))
    plt.xlabel('Time (HH:MM)')
    plt.ylabel('Battery (%)')
    plt.title(current_date)
    plt.ylim(0, 100)
    plt.show()
else:
    print('Data unavailable')