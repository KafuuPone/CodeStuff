import sys

from PyQt5.QtCore import Qt, QRect, QTimer, QCoreApplication
from PyQt5.QtGui import QMovie
from PyQt5.QtWidgets import QMainWindow, QApplication, QLabel

# relative to top left
# x, y = 1520, 713 # No resized coords
x, y = 1570, 739 # Resized gif coords

class MainWindow(QMainWindow):
    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)
        self.resize(500, 500)

        self.setAttribute(Qt.WA_TranslucentBackground, True)  # Set translucent background
        self.setAttribute(Qt.WA_NoSystemBackground, True)  # Remove system background
        self.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool)  # Set flags

        self.MovieLabel = QLabel(self)
        self.MovieLabel.setGeometry(QRect(0, 0, 500, 500))  # Set label geometry
        self.movie = QMovie("no_bg_1064837_resized.gif")  # Assuming gifFile is defined elsewhere
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