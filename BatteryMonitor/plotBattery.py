import numpy as np
import matplotlib.pyplot as plt
import os
from datetime import datetime

current_dir = os.getcwd() # current directory
current_date = input('Year: ') + '-' + f"{int(input('Month: ')):02}" + '-' + f"{int(input('Day: ')):02}"

filepath = f'{current_dir}\\BatteryLog\\{current_date}.npy'

if os.path.exists(filepath):
    data = np.load(filepath)

    plt.scatter(data['time'], data['percent'], marker='o')
    plt.title(current_date)
    plt.xlabel('Time (HH:MM)')
    plt.ylabel('Battery (%)')
    plt.show()
else:
    print('Data unavailable')