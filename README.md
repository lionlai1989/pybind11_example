# Pybind11 Project Template

Welcome to a C++ project template designed for quickly starting a C++ project with Python binding.  

## Description

This template has the following features:
- Built with CMake for seamless integration
- [stb image library](https://github.com/nothings/stb), [xtensor](https://github.com/xtensor-stack/xtensor), and [Pybind11](https://github.com/pybind/pybind11) are git submodules so that users can clone this repository recursively without worrying about dependencies.

## Getting Started

### Dependencies

Before you start, please make sure you have the following dependencies installed:

* **CMake 3.22.0 or higher:** If you don't have CMake installed, or if you need to update it, you can follow the instructions [here](https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line). To use version 3.22, you can download it from https://cmake.org/files/v3.22/cmake-3.22.6.tar.gz.

* **stb image library:** This is a C library for loading and saving images. It's included as a git submodule, so you don't need to do anything extra.

* **Pybind11:** Pybind11 is also included as a git submodule, so you don't need to do anything extra.

* **xtensor-assosiated library:** xtensor is a numpy for C++ library. All
  required code is added as git submodules. Unlike `Pybind11` library, I
  can't figure out a way to install them by using `add_subdirectory` in `CMakeLists.txt`. Thus, users must first install `xtl`, `xtensor`, and `xsimd` under `/tmp` as following:
  * Isntall xtl:
  ```
  (cd extern/xtl && cmake -D CMAKE_INSTALL_PREFIX=/tmp/xtl-install && make install)
  ```
  * Install xtensor:
  ```
  (cd extern/xtensor && cmake -D CMAKE_INSTALL_PREFIX=/tmp/xtensor-install -DCMAKE_PREFIX_PATH=/tmp/xtl-install && make install)
  ```
  * Install xsimd:
  ```
  (cd extern/xsimd && cmake -D CMAKE_INSTALL_PREFIX=/tmp/xsimd-install && make install)
  ```

* **Development tools for Linux and VS Code:** To develop our project, we'll be using Linux and Visual Studio Code (VS Code). To have a smoother experience, you should install the following tools and extensions for VS Code:
  * `C/C++`
  * `C/C++ Extension`
  * `CMake`
  * `CMake Extension`
  * `llvm`
  * `lldb`
  * `ninja`
  * `python3-dev` (install this with apt install python3-dev)

### Installing
It's a C++ project which has Python binding. Thus, the installation process is primary for Python users. Please following the steps below to install this package:
* (Optional) Download this repository. 
  ```shell
  git clone --recursive https://github.com/lionlai1989/pybind11_example.git
  ```
  If you forgot to use the `--recursive` option when cloning, you can still clone the submodules by running the command `git submodule update --init --recursive`.

* Create a Python virtual environment `venv`, activate `venv`, and update pip:
  ```shell
  python3 -m venv venv && source venv/bin/activate && python3 -m pip install --upgrade pip
  ```

* Install from Github repository: Notice the name of the package is `pybind11_template` but not `pybind11_example`
  ```
  python3 -m pip install "pybind11_template @ git+ssh://git@github.com/lionlai1989/pybind11_example.git"
  ```

* (Optional) If the following error occurs:
  ```shell
  ~/venv/lib/python3.8/site-packages/pybind11/include/pybind11/detail/common.h:266:10: fatal error: Python.h: No such file or directory
  ```
  Please execute `sudo apt install python3-dev`. See [this](https://github.com/pybind/pybind11/issues/1728) for more information.

* Install in editable mode: `python3 -m pip install -e .`

### Verify the installation
If you've already cloned the repository, you can run the command `python3 test_pybind11.py` to execute the tests. If you don't clone the repository, you can download `test_pybind11.py` from [this location](https://github.com/lionlai1989/pybind11_example/blob/master/test_pybind11.py). Once you run the script, it will test `pybind11_template` and convert two images from RGB to grayscale: `./examples/files/ikura36_gray.png` and `./examples/files/louvre_gray.jpg`.
  <p align="left">
    <img src="./examples/files/louvre.jpg" width="300" title="Input RGB Image with JPG Format">
    <img src="./examples/files/louvre_gray.jpg" width="300" title="Output Grayscale Image with JPG Format">
  </p>
  <p align="left">
    <img src="./examples/files/ikura36.png" width="300" title="Input RGB Image with PNG Format">
    <img src="./examples/files/ikura36_gray.png" width="300" title="Output Grayscale Image with PNG Format">
  </p>

### Developing
* First remove the folder `build/temp.linux-x86_64-cpython-38/pybind11_eigen` which has the memory of configuration from pip install. This step just has to be run the first time.
* Use cmake to build the project:
```shell
cmake -Druntest=ON . -B build/temp.linux-x86_64-cpython-38/pybind11_eigen -DCMAKE_LIBRARY_OUTPUT_DIRECTORY=`pwd`/build/lib.linux-x86_64-cpython-38/ -DPYTHON_EXECUTABLE=`which python3` -DCMAKE_BUILD_TYPE=Release -DEXAMPLE_VERSION_INFO=0.0.1 -GNinja && cmake --build build/temp.linux-x86_64-cpython-38/pybind11_eigen
```
One thing to note here is that the ninja version used here is different from the ninja version used in pip install.
* Run tests. `(cd build/temp.linux-x86_64-cpython-38/pybind11_eigen; ctest -V)`
* Try libvips and CImg and terrasect and probably opencv.
tensorflow uses eigen::tensor though.

Use Clang Static Analyzer and clang-tidy and GoogleTest

## Contributing

Your feedback, comments, and questions about this project are welcome, as are any contributions you'd like to make. Please feel free to create an issue or a pull request in this repository. Together, let's improve this template and make life easier for C++ programmers.

## Authors

[@lionlai](https://github.com/lionlai1989)

## Version History

* 0.0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments
Explore the inspiration and references listed here to further expand your knowledge and sharpen your skills.

Pybind11:
* [pybind-cmake-example](https://github.com/pybind/cmake_example)

GoogleTest:
* [gtest-cmake-example](https://github.com/dmonopoly/gtest-cmake-example)
