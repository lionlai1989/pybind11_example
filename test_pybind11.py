
from build import pybind11_eigen
import numpy as np
from PIL import Image

if __name__ == "__main__":
    a = np.array([[[1,2,3], [4,5,6]],[[7,8,9], [0,1,2]]])
    print(a, a.shape)
    print(pybind11_eigen.eigenTensor(a))

    ret = pybind11_eigen.crossMatrix(np.array([1,2,3]))
    print(ret)
    
    with Image.open("handsomeboy.jpg") as img:
        pixels = np.asarray(img)
        #img.show()
    print(pixels.shape)

    # Use C++ to process pixels.
    # processed_pixels = pybind11_eigen.image2digit(pixels)

    processed_img = Image.fromarray(pixels)
    processed_img.show()
