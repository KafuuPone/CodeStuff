import os
from PIL import Image

def pngs_to_gif(png_dir, output_path, duration=200):
    """
    Convert PNG files with names in the format "frame_number.png" in a directory to a GIF file.

    Parameters:
        png_dir (str): Path to the directory containing PNG files.
        output_path (str): Path to save the output GIF file.
        duration (int): Display duration (in milliseconds) for each frame.

    Returns:
        None
    """
    image_paths = []
    for filename in sorted(os.listdir(png_dir)):
        if filename.endswith(".png"):
            image_paths.append(os.path.join(png_dir, filename))

    images = []
    for path in image_paths:
        images.append(Image.open(path))

    # Save as GIF
    images[0].save(output_path,
                   save_all=True,
                   append_images=images[1:],
                   duration=duration,
                   loop=0)

# Example usage:
png_directory = "bg_removed_frames"  # Directory containing PNG files
output_path = "output.gif"  # Output GIF path
pngs_to_gif(png_directory, output_path)
