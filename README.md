
git submodule update --init

install llvm, lldb, ninja

vscdoe install c/c++ extension, cmake tool.

apt install python3-dev, lldb

git add pybind11 as git submodule 
git submodule add -b stable git@github.com:pybind/pybind11.git extern/pybind11
git submodule update --init
Required python packages:
numpy
Pillow

RUN:
mkdir -p build && cd build && cmake -G Ninja .. && ninja
cmake -S . -B build -G Ninja && ninja -C build && (cd build; ctest -V)
cmake -G Ninja .. && ninja

Run
c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3-config --includes) -Iextern/pybind11/include example.cpp -o example$(python3-config --extension-suffix)
to create share library (.so)

### include eigen path
1. Download eigen header files eigen-3.4.0 and put to /usr/local/include/eigen-3.4.0
2. run
c++ -O3 -Wall -shared -std=c++11 -I /usr/local/include/eigen-3.4.0 -fPIC $(python3-config --includes) -Iextern/pybind11/include example.cpp -o example$(python3-config --extension-suffix)

Try libvips and CImg and terrasect and probably opencv.
tensorflow uses eigen::tensor though.


Run cmake extension tool on vscode.

Use Clang Static Analyzer and clang-tidy and GoogleTest

from build import pybind11_eigen
import numpy as np
pybind11_eigen.crossMatrix(np.array([1,2,3]))


to install this from private github account with pip:
`python3 -m pip install git+ssh://git@github.com/lionlai1989/pybind11_example.git`
