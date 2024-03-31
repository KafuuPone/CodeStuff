from PIL import Image
import os

# Set the target width and height
target_width = 120
target_height = 155

# Folder containing the images
folder_path = "C:/Users/howqi/Documents/CodeStuff/BatteryMonitor/NewPrototype/bg_removed_resized"

# Loop through all files in the folder
for filename in os.listdir(folder_path):
    # Check if the file is an image
    if filename.endswith(".jpg") or filename.endswith(".png") or filename.endswith(".jpeg"):
        # Open the image
        image_path = os.path.join(folder_path, filename)
        img = Image.open(image_path)
        
        # Resize the image
        img_resized = img.resize((target_width, target_height))
        
        # Save the resized image, overwriting the original file
        img_resized.save(image_path)
