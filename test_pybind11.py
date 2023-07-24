import pybind11_template
import numpy as np
from PIL import Image

if __name__ == "__main__":
    s = pybind11_template.get_student("Aaron")
    s.display()

    a = np.array([0, 1, 2])
    print(pybind11_template.sum_of_sines(a))
    print(pybind11_template.sum_of_cosines(a))

    b = np.array([[0, 1, 2], [3, 4, 5]])
    print(pybind11_template.sum_of_sines(b))
    print(pybind11_template.sum_of_cosines(b))

    c = np.array([[[0, 1, 2], [3, 4, 5], [6, 7, 8]]])
    print(pybind11_template.sum_of_sines(c))
    print(pybind11_template.sum_of_cosines(c))
    
    pybind11_template.image_rgb2gray("./examples/files/ikura36.png", "./examples/files/ikura36_gray.png")

    
    with Image.open("./examples/files/louvre.jpg") as im:
        # pixels: (height, width, channel)
        pixels = np.asarray(im)
        print(f"The shape of pixels: {pixels.shape}")

        # Convert uint8 to 0-1.
        pixels = pixels / 255.0
        
        # pixel_rgb2gray takes (channel, height, width)
        gray = pybind11_template.pixel_rgb2gray(np.moveaxis(pixels, -1, 0))
        print(f"The shape of gray: {gray.shape}")

        # Convert 0-1 to uint8. Use np.floor to avoid overflow.
        gray = np.floor(255*gray).astype(np.uint8)

        gray = np.moveaxis(gray, 0, -1)
        print(f"The shape of gray: {gray.shape}")
        # NOTE: If image is grayscale, pillow only accepts 2D array but not 3D.
        out_im = Image.fromarray(gray[:, :, 0])
        out_im.save("./examples/files/louvre_gray.jpg")
