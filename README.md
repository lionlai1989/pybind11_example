# Pybind11 Project Template

Welcome to the C++ project template designed for self-education! Our aim is to
help you create a C++ library using some of the most useful C/C++ packages,
Pybind11, and cmake. It's important to note that this project is focused on C++
development rather than Python, so don't be surprised if the development flow
feels a bit different from Python development. With this template, you can get
hands-on experience building a C++ library while exploring the benefits of cmake
and Pybind11. So, let's dive in and start learning!

## Description

As a beginner myself, I found that many of the Pybind11 tutorials online were either too simplistic to be practical for real-world projects or far too complicated to grasp as a newcomer. Of course, simple projects are great for learning the basics, but often, I found myself spending hours cobbling together multiple tutorials to create a state in which I could really start programming in C++. This template is my humble attempt to bridge that gap - an intermediate level resource to help myself and others learn how to create a C++ project with Python binding. My hope is that, in the future, when I need to start a C++ project with Python binding, I can simply use this template to quickly and easily handle the building environment, allowing me to focus on the actual code. So, let's dive in and learn together!

## Getting Started
This template has the following features:
- Built with CMake for seamless integration
- Submodules for [stb image library](https://github.com/nothings/stb), [xtensor](https://github.com/xtensor-stack/xtensor), and [Pybind11](https://github.com/pybind/pybind11).

### Dependencies

* Install vscode and c/c++ extension. Run cmake extension tool on vscode so vscode can figure out the libraries dependencies.
* Install llvm, lldb, ninja.
* (Optional) apt install python3-dev
* Download eigen header files eigen-3.4.0 and put to /usr/local/include/eigen-3.4.0
* if got error:
```
/home/lai/pybind11_example/venv/lib/python3.8/site-packages/pybind11/include/pybind11/detail/common.h:266:10: fatal error: Python.h: No such file or directory
```
Run `sudo apt install python3-dev` will install python3.8 on ubuntu20.04.

### Installing
* Download repo: `git clone --recursive https://github.com/lionlai1989/pybind11_example.git`. If `--recursive` is not used when cloning, then `git submodule update --init` can be run to clone the submodule.
* Create, activate venv and update pip: `python3 -m venv venv && source venv/bin/activate && python3 -m pip install --upgrade pip`
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
* Run `python3` in the virtual environment. currently, i need to go to `build` folder to run the code below.
```
import pybind11_eigen
import numpy as np
a = np.array([1,2,3])
b = pybind11_eigen.crossMatrix(a)
```

### Developing
* First remove the folder `build/temp.linux-x86_64-cpython-38/pybind11_eigen` which has the memory of configuration from pip install. This step just has to be run the first time.
* Use cmake to build the project:
```shell
cmake -Druntest=ON . -B build/temp.linux-x86_64-cpython-38/pybind11_eigen -DCMAKE_LIBRARY_OUTPUT_DIRECTORY=`pwd`/build/lib.linux-x86_64-cpython-38/ -DPYTHON_EXECUTABLE=`which python3` -DCMAKE_BUILD_TYPE=Release -DEXAMPLE_VERSION_INFO=0.0.1 -GNinja && cmake --build build/temp.linux-x86_64-cpython-38/pybind11_eigen
```
One thing to note here is that the ninja version used here is different from the ninja version used in pip install.
* Run tests. `(cd build/temp.linux-x86_64-cpython-38/pybind11_eigen; ctest -V)`

## Help

Any advise for common problems or issues.
```
command to run if program contains helper info
```

## Authors

Contributors names and contact info
Zion Lai
[@DomPizzie](https://twitter.com/dompizzie)

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
* [gtest-cmake-example](https://github.com/dmonopoly/gtest-cmake-example)

Try libvips and CImg and terrasect and probably opencv.
tensorflow uses eigen::tensor though.

Use Clang Static Analyzer and clang-tidy and GoogleTest
