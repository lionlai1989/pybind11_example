# C++ project template with Pybind11

It's a C++ project template to self-educate how to create a C++ library with cmake, Pybind11, and some useful C/C++ packages.

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
