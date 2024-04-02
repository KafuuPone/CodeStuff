# from screeninfo import get_monitors
# for m in get_monitors():
#     print(str(m))

# from win32api import GetMonitorInfo, MonitorFromPoint
# import ctypes

# # multiply a sequence of numbers
# def multiply(int_sequence, float_value):
#     result = [round(num * float_value) for num in int_sequence]
#     return tuple(result)

# monitor_info = GetMonitorInfo(MonitorFromPoint((0,0)))
# monitor_area = monitor_info.get("Monitor")
# work_area = monitor_info.get("Work")
# print(monitor_area, work_area)

# scale_factor = ctypes.windll.shcore.GetScaleFactorForDevice(0) / 100
# # Real area in pixels
# scaled_monitor_area = multiply(monitor_area, scale_factor)
# scaled_work_area = multiply(work_area, scale_factor)

# print(scaled_monitor_area, scaled_work_area)

#-----#

import sys, os, time

from PyQt5.QtCore import Qt, QTimer, QPropertyAnimation
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QMainWindow, QApplication, QLabel

# display speech bubble
x_offset, y_offset = 100, 912

app = QApplication(sys.argv)

window = QMainWindow()
window.setAttribute(Qt.WA_TranslucentBackground, True)  # Set translucent background
window.setAttribute(Qt.WA_NoSystemBackground, True)  # Remove system background
window.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool)  # Set flags

label = QLabel(window)
pixmap = QPixmap("./NewPrototype/bg_removed_resized/frame_20.png")
label.setPixmap(pixmap)
label.setGeometry(0, 0, pixmap.width(), pixmap.height())

window.label = label

window.resize(pixmap.width(), pixmap.height())
window.move(x_offset, y_offset)

window.show()

loop = True
while loop:
    if input() == 'end':
        loop = False
        sys.exit()
    
sys.exit(app.exec_())