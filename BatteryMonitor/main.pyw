'''
To start the program run the following command in CMD (in the folder where the file is located): pythonw YOUR-FILE.pyw

Now the process will run continuously in the background. To stop the process, you must run the command:

TASKKILL /F /IM pythonw.exe
'''

import psutil
import os
from windows_toasts import WindowsToaster, Toast, wrappers
import time

# Basic variables
current_dir = os.getcwd() # current directory
toaster = WindowsToaster('Battery Monitor') # toaster setup
image = wrappers.ToastImage(f"{current_dir}\\icon.ico") # image object
icon = wrappers.ToastDisplayImage(image, position=wrappers.ToastImagePosition.AppLogo) # icon setup and position

def check_battery():
    battery = psutil.sensors_battery()
    percent = battery.percent
    return percent

def is_charging():
    battery = psutil.sensors_battery()
    return battery.power_plugged

def main():
    battery_toast = Toast()
    battery_toast.AddImage(icon)
    while True:
        percent = check_battery()
        if percent<=30 and not is_charging():
            battery_toast.text_fields = [f"Low Battery! ({percent}%)", "Please plug in your charger!"]
            toaster.show_toast(battery_toast)
        elif percent>=90 and is_charging():
            battery_toast.text_fields = [f"Battery full! ({percent}%)", "Please unplug your charger!"]
            toaster.show_toast(battery_toast)
        time.sleep(60) # check interval

main()