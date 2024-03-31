from PIL import Image, ImageSequence

def split_gif(input_path, output_path):
    with Image.open(input_path) as img:
        frames = [frame.copy() for frame in ImageSequence.Iterator(img)]

    for i, frame in enumerate(frames):
        frame.save(f"{output_path}/frame_{i}.png", "PNG")

# Example usage
input_gif_path = "1064837.gif"
output_frames_path = "output_frames"
split_gif(input_gif_path, output_frames_path)