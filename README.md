# My Awesome Pybind11 CMake Eigen Example

An example project to self-learn pybind11, cmake, and some useful C/C++ packages.

## Description

An in-depth paragraph about your project and overview of use.

## Getting Started

### Dependencies

* Install vscode and c/c++ extension. Run cmake extension tool on vscode so vscode can figure out the libraries dependencies.
* Install llvm, lldb, ninja.
* (Optional) apt install python3-dev
* Download eigen header files eigen-3.4.0 and put to /usr/local/include/eigen-3.4.0

### Installing
* Download repo: `git clone --recursive https://github.com/lionlai1989/pybind11_example.git`. If `--recursive` is not used when cloning, then `git submodule update --init` can be run to clone the submodule.
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

### Developing
* Use cmake to build the project. `cmake -Druntest=ON -S . -B build -G Ninja && ninja -C build`
* Run tests. `(cd build; ctest -V)`

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


Try libvips and CImg and terrasect and probably opencv.
tensorflow uses eigen::tensor though.

Use Clang Static Analyzer and clang-tidy and GoogleTest
