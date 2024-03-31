from PIL import Image, ImageFont

def get_percent():
    with open("./speech_bubble/percent", "r") as file:
        return file.read()

# function to generate image from text
def save_section(text, font_filepath, font_size=14):
    color = (0, 0, 0, 255)

    font = ImageFont.truetype(font_filepath, size=font_size)
    mask_image = font.getmask(text, "L")
    img = Image.new("RGBA", mask_image.size)
    img.im.paste(color, (0, 0) + mask_image.size, mask_image)
    return img

# generate speech bubble, saves to "speech_bubble.png"
def bubble_gen():
    text_top1, text_top2, text_top3, middle_image, text_bottom = None, None, None, None, None
    if int(get_percent())<=30:
        text_top1 = save_section('Low battery with ', "./speech_bubble/CCMeanwhile-Regular.ttf")
        text_top2 = save_section(f'{get_percent()}%', "./speech_bubble/CCMeanwhile-BoldItalic.ttf", 17)
        text_top3 = save_section(',', "./speech_bubble/CCMeanwhile-Regular.ttf")
        middle_image = save_section('remember to plug in', "./speech_bubble/CCMeanwhile-Regular.ttf")
        bottom_image = save_section('your charger!', "./speech_bubble/CCMeanwhile-Regular.ttf")
    elif int(get_percent())>=90:
        text_top1 = save_section('Battery full with ', "./speech_bubble/CCMeanwhile-Regular.ttf")
        text_top2 = save_section(f'{get_percent()}%', "./speech_bubble/CCMeanwhile-BoldItalic.ttf", 17)
        text_top3 = save_section(',', "./speech_bubble/CCMeanwhile-Regular.ttf")
        middle_image = save_section('remember to unplug', "./speech_bubble/CCMeanwhile-Regular.ttf")
        bottom_image = save_section('your charger!', "./speech_bubble/CCMeanwhile-Regular.ttf")

    # merge top images side by side bottom aligned
    # Calculate dimensions for the resulting image
    total_width = text_top1.width + text_top2.width + text_top3.width
    max_height = max(text_top1.height, text_top2.height, text_top3.height)
    # Create a new image with RGBA mode
    top_image = Image.new("RGBA", (total_width, max_height), (0, 0, 0, 0))
    # Paste the images side by side
    x = 0
    for img in [text_top1, text_top2, text_top3]:
        y = max_height - img.height
        top_image.paste(img, (x, y))
        x += img.width

    # merge top and bottom center aligned
    gap = 2
    # Calculate dimensions for the resulting image
    max_width = max(top_image.width, middle_image.width, bottom_image.width)
    total_height = top_image.height + middle_image.height + bottom_image.height + 2*gap
    # Create a new image with RGBA mode
    final_image = Image.new("RGBA", (max_width, total_height), (0, 0, 0, 0))
    # Paste the images centered with gap between them
    y = 0
    for img in [top_image, middle_image, bottom_image]:
        x = (max_width - img.width) // 2
        final_image.paste(img, (x, y))
        y += img.height + gap
    # The resulting image
    text_image = final_image

    # Merge text image on top of speech bubble
    bubble_image = Image.open("./speech_bubble/bubble.png")
    x_offset, y_offset = (bubble_image.width - text_image.width)//2, 26
    bubble_image.paste(text_image, (x_offset, y_offset), text_image)
    bubble_image.save("./speech_bubble/speech_bubble.png")

# main execution
    
import sys, os, time

from PyQt5.QtCore import Qt, QTimer, QPropertyAnimation
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QMainWindow, QApplication, QLabel

# generate speech bubble image
bubble_gen()

# display speech bubble
x_offset, y_offset = 1650, 870

app = QApplication(sys.argv)

window = QMainWindow()
window.setAttribute(Qt.WA_TranslucentBackground, True)  # Set translucent background
window.setAttribute(Qt.WA_NoSystemBackground, True)  # Remove system background
window.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.Tool)  # Set flags

label = QLabel(window)
pixmap = QPixmap("./speech_bubble/speech_bubble.png")
label.setPixmap(pixmap)
label.setGeometry(0, 0, pixmap.width(), pixmap.height())

window.label = label

window.resize(pixmap.width(), pixmap.height())
window.move(x_offset, y_offset)


# Fade-in animation
fadeInAnimation = QPropertyAnimation(window, b"windowOpacity")
fadeInAnimation.setDuration(300)  # 1 second fade-in duration
fadeInAnimation.setStartValue(0.0)
fadeInAnimation.setEndValue(1.0)
# Fade-out animation
fadeOutAnimation = QPropertyAnimation(window, b"windowOpacity")
fadeOutAnimation.setDuration(300)  # 1 second fade-out duration
fadeOutAnimation.setStartValue(1.0)
fadeOutAnimation.setEndValue(0.0)
# Connect the fade-out animation to close the application
fadeOutAnimation.finished.connect(app.quit)
# Start the fade-in animation
fadeInAnimation.start()
# Start the fade-out animation
QTimer.singleShot(6000, fadeOutAnimation.start)

# Wait for 0.8s
time.sleep(0.8)
window.show()

# delete image generated
os.remove("./speech_bubble/speech_bubble.png")
sys.exit(app.exec_())