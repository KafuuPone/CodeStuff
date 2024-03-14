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
        prev_percent = check_battery()
        time.sleep(60)
        curr_percent = check_battery()
        if curr_percent<=30 and prev_percent>30:
            send_notif(curr_percent)
        elif curr_percent>=90 and prev_percent<90:
            send_notif(curr_percent)
        elif curr_percent==100:
            send_notif(curr_percent)

main()