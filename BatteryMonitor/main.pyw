'''
To start the program run the following command in CMD (in the folder where the file is located): pythonw YOUR-FILE.pyw

Now the process will run continuously in the background. To stop the process, you must run the command:

TASKKILL /F /IM pythonw.exe
'''

import psutil
import os
from notifypy import Notify
import time

current_dir = os.getcwd()

def check_battery():
    battery = psutil.sensors_battery()
    percent = battery.percent
    return percent

def is_charging():
    battery = psutil.sensors_battery()
    return battery.power_plugged

def send_notif(percent):
    notif = Notify(
        default_application_name="",
        default_notification_icon=f'{current_dir}\\icon.ico'
    )
    if percent <= 30:
        notif.title = "Low Battery!"
        notif.message = f"{percent}% charged, please plug in your charger!"
        notif.send()
    elif percent >= 90:
        notif.title = "Battery full!"
        notif.message = f"{percent}% charged, please unplug your charger!"
        notif.send()

def main():
    while True:
        percent = check_battery()
        if percent<=30 and not is_charging():
            send_notif(percent)
        elif percent>=90 and is_charging():
            send_notif(percent)
        time.sleep(60)

main()