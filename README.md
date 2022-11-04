# My Awesome Pybind11 CMake Eigen Example

An example project to self-learn pybind11, cmake, and some useful C/C++ packages.

## Description

An in-depth paragraph about your project and overview of use.

## Getting Started

### Dependencies

* Install vscode, c/c++ extension, and cmake tool.
* Install llvm, lldb, ninja.
* (Optional) apt install python3-dev
* Download eigen header files eigen-3.4.0 and put to /usr/local/include/eigen-3.4.0

### Installing
* Download repo: `git clone --recursive https://github.com/lionlai1989/pybind11_example.git`
* Create and activate venv: `python3 -m venv venv_pybind11_example && source venv_pybind11_example/bin/activate`
* Upgrade pip and setuptools: `python3 -m pip install --upgrade pip setuptools`
* Install: `python3 -m pip install .`
* Install in editable mode: `python3 -m pip install -e .`
* Install from github repo: `python3 -m pip install "pybind11_eigen @ git+https://github.com/lionlai1989/pybind11_example.git"` or `python3 -m pip install "pybind11_eigen @ git+ssh://git@github.com/lionlai1989/pybind11_example.git"`. Notice the name of the package is `pybind11_eigen` but not `pybind11_example`. 

### Executing program

* Run the `test_pybind11.py` to show the C++ library can be imported as a python package.  
```
$ python3 test_pybind11.py 
4
[1, 2, 3, 4, 5, 6, 7]
```

## Help

Any advise for common problems or issues.
```
command to run if program contains helper info
```

## Authors

Contributors names and contact info

ex. Dominique Pizzie  
ex. [@DomPizzie](https://twitter.com/dompizzie)

## Version History

* 0.2
    * Various bug fixes and optimizations
    * See [commit change]() or See [release history]()
* 0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
* [pybind-cmake-example](https://github.com/pybind/cmake_example)\

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

2. run
c++ -O3 -Wall -shared -std=c++11 -I /usr/local/include/eigen-3.4.0 -fPIC $(python3-config --includes) -Iextern/pybind11/include example.cpp -o example$(python3-config --extension-suffix)

Try libvips and CImg and terrasect and probably opencv.
tensorflow uses eigen::tensor though.


Run cmake extension tool on vscode.

Use Clang Static Analyzer and clang-tidy and GoogleTest

from build import pybind11_eigen
import numpy as np
pybind11_eigen.crossMatrix(np.array([1,2,3]))
