from PIL import Image

def get_gif_frame_durations(gif_path):
    """
    Get the frame durations of a GIF file.

    Parameters:
        gif_path (str): Path to the input GIF file.

    Returns:
        list: List of frame durations in milliseconds.
    """
    with Image.open(gif_path) as img:
        durations = []
        # Loop through each frame
        try:
            while True:
                durations.append(img.info['duration'])
                img.seek(img.tell() + 1)
        except EOFError:
            pass
    return durations

# Example usage:
gif_path = "no_bg_1064837.gif"  # Path to your GIF file
frame_durations = get_gif_frame_durations(gif_path)
print("Frame Durations (milliseconds):", frame_durations)
