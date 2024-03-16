import numpy as np
import matplotlib.pyplot as plt
import os
from datetime import datetime
import pandas as pd

current_dir = os.getcwd() # current directory
current_date = str(datetime.now().date())
if (input('Plot data for today? (y/n) ')).lower() != 'y':
    current_date = input('Year: ') + '-' + f"{int(input('Month: ')):02}" + '-' + f"{int(input('Day: ')):02}"

filepath = f'{current_dir}\\BatteryLog\\{current_date}.npy'

if os.path.exists(filepath):
    rawdata = np.load(filepath)
    data = {'Time': rawdata['time'], 'Battery': rawdata['percent']}
    df = pd.DataFrame(data)
    ax = df.plot(x='Time', y='Battery', marker='o', linestyle='-', markersize=3,legend=False)
    ax.set_xlabel('Time (HH:MM)')
    ax.set_ylabel('Battery (%)')
    ax.set_title(current_date)
    plt.show()
else:
    print('Data unavailable')