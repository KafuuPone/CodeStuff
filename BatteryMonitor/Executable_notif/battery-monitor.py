import psutil
import os, sys
from windows_toasts import WindowsToaster, Toast, wrappers
import time

# import pystray
# from pystray import MenuItem as item
# from PIL import Image

# To include image file in executable
def resource_path(relative_path):
    try:
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)

def check_battery():
    battery = psutil.sensors_battery()
    percent = battery.percent
    return percent

def is_charging():
    battery = psutil.sensors_battery()
    return battery.power_plugged

# Basic variables
toaster = WindowsToaster('Battery Monitor') # toaster setup
toast_image = wrappers.ToastImage(resource_path("icon.ico")) # image object
toast_icon = wrappers.ToastDisplayImage(toast_image, position=wrappers.ToastImagePosition.AppLogo) # icon setup and position

# notification
def main_function():
    # icon.visible = True # show icon

    while True:
        percent = check_battery()

        battery_toast = Toast()
        battery_toast.AddImage(toast_icon)
        if percent<=30 and not is_charging():
            battery_toast.text_fields = [f"Low Battery! ({percent}%)", "Please plug in your charger!"]
            toaster.show_toast(battery_toast)
        elif percent>=90 and is_charging():
            battery_toast.text_fields = [f"Battery full! ({percent}%)", "Please unplug your charger!"]
            toaster.show_toast(battery_toast)
        
        time.sleep(60) # check interval

main_function()

# # exit program
# def exit(icon):
#     icon.stop()
#     os._exit(0)
#     # time.sleep(1)
#     # sys.exit()

# image = Image.open(resource_path("icon.ico"))
# menu = (item('Exit', exit),)
# icon = pystray.Icon("Battery Monitor", image, "Battery Monitor", menu)
# icon.run(main_function)

'''
To start the program run the following command in CMD (in the folder where the file is located): pythonw YOUR-FILE.pyw

Now the process will run continuously in the background. To stop the process, you must run the command:

TASKKILL /F /IM pythonw.exe
'''

# pyinstaller --hidden-import winrt.windows.foundation.collections --onefile --windowed --icon=icon.ico --add-data "icon.ico:." battery-monitor.py