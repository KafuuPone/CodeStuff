'''
To start the program run the following command in CMD (in the folder where the file is located): pythonw YOUR-FILE.pyw

Now the process will run continuously in the background. To stop the process, you must run the command:

TASKKILL /F /IM pythonw.exe
'''

import psutil
import os
from windows_toasts import WindowsToaster, InteractableWindowsToaster, Toast, wrappers
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

def send_notif(percent):
    batteryToast = Toast()
    batteryToast.AddImage(icon)
    if percent <= 30:
        batteryToast.text_fields = ["Low Battery!", f"{percent}% charged, please plug in your charger!"]
    elif percent >= 90:
        batteryToast.text_fields = ["Battery full!", f"{percent}% charged, please unplug your charger!"]
    toaster.show_toast(batteryToast)

def main():
    while True:
        percent = check_battery()
        if percent<=30 and not is_charging():
            send_notif(percent)
        elif percent>=90 and is_charging():
            send_notif(percent)
        time.sleep(60) # check interval

main()