
from build import pybind11_eigen
import numpy as np


if __name__ == "__main__":

    ret = pybind11_eigen.crossMatrix(np.array([1,2,3]))
    print(ret)
