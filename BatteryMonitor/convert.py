from PIL import Image

def png_to_ico(input_path, output_path):
    # Open the PNG image
    img = Image.open(input_path)
    
    # Convert RGBA images to RGB
    if img.mode == "RGBA":
        img = img.convert("RGB")
    
    # Save as ICO format
    img.save(output_path, format="ICO", quality=100)

# Example usage
png_to_ico('icon.png', 'icon.ico')