import sys

from PyQt5.QtCore import Qt, QRect, QTimer, QCoreApplication
from PyQt5.QtGui import QMovie, QPixmap
from PyQt5.QtWidgets import QMainWindow, QApplication, QLabel

from win32api import GetMonitorInfo, MonitorFromPoint
import ctypes

# Calculating position - assuming windows 10, taskbar bottom, standard height
# relative to top left
monitor_info = GetMonitorInfo(MonitorFromPoint((0,0)))
monitor_area, work_area = monitor_info.get("Monitor"), monitor_info.get("Work")
scale_factor = ctypes.windll.shcore.GetScaleFactorForDevice(0) / 100
# unscaled variables
monitor_width, monitor_height = monitor_area[2], monitor_area[3]
work_width, work_height = work_area[2], work_area[3]
# scaled variables
scaled_work_height = int(scale_factor*work_height) # height of monitor - taskbar
scaled_monitor_width = int(scale_factor*monitor_width)
scaled_taskbar_height = int(scale_factor*(monitor_height-work_height))
x = int(scaled_monitor_width-5.5*scaled_taskbar_height-72) # accounted for different monitors
if x+322 > scaled_monitor_width: # in case the speech bubble leaves the screen
    x = scaled_monitor_width-322
y = scaled_work_height-118 # -118: y-offset of topleft of gif relative to taskbar

class MainWindow(QMainWindow):
    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)
        pixmap = QPixmap("no_bg_1064837_resized.gif") # used to get gif dimension

        self.resize(pixmap.width(), pixmap.height())

        self.setAttribute(Qt.WA_TranslucentBackground, True)  # Set translucent background
        self.setAttribute(Qt.WA_NoSystemBackground, True)  # Remove system background
        self.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool)  # Set flags

        self.movie = QMovie("no_bg_1064837_resized.gif")  # Assuming gifFile is defined elsewhere
        self.MovieLabel = QLabel(self)
        self.MovieLabel.setGeometry(QRect(0, 0, pixmap.width(), pixmap.height()))  # Set label geometry
        self.MovieLabel.setMovie(self.movie)
        self.movie.start()

        # Set up a timer to check if the GIF animation has finished
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.checkGifStatus)
        self.timer.start(1)  # Check every 1ms

        # Move window to calculated position
        self.move(x, y)

    def checkGifStatus(self):
        # If the GIF animation has reached its last frame
        if self.movie.currentFrameNumber() == self.movie.frameCount() - 1:
            sys.exit()

app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec_())