cmake_minimum_required(VERSION 3.22)
project(cmake_template VERSION 0.0.1 LANGUAGES CXX)

set (CMAKE_CXX_FLAGS "-std=c++17")

list(APPEND CMAKE_PREFIX_PATH "/tmp/xtl-install")
list(APPEND CMAKE_PREFIX_PATH "/tmp/xtensor-install")
list(APPEND CMAKE_PREFIX_PATH "/tmp/xsimd-install")

add_subdirectory(extern/pybind11)

find_package(Python REQUIRED COMPONENTS Interpreter Development NumPy)

# If using `add_subdirectory` on `xtl`, `xtensor`, and `xsimd`, there will be error.
# Check https://github.com/xtensor-stack/xtensor-python/issues/293
find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)
find_package(xsimd REQUIRED)

# I cannot figure out how to install `xtensor-python` and then use `find_package` on it.
add_subdirectory(extern/xtensor-python)

add_subdirectory(src/mypackage)
add_subdirectory(examples)

include(GNUInstallDirs) # Defines the ${CMAKE_INSTALL_INCLUDEDIR} variable.
# Install the header files. Since header files are not listed as output artifacts, they have
# to be installed separately. 
install (
    DIRECTORY include/
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

pybind11_add_module(pybind11_template pybind11_template.cpp)

# Without this line, there will be error when importing pybind11_template
# >>> import pybind11_template
# Traceback (most recent call last):
#   File "<stdin>", line 1, in <module>
# ImportError: ~/venv/lib/python3.8/site-packages/pybind11_template.cpython-38-x86_64-linux-gnu.so: undefined symbol: _ZTI7Student
# target_link_libraries(pybind11_template PUBLIC student_static)
# It makes pybind11_template.cpp to be able to include `mypackage/Student.hpp` and `mypackage/rgb2gray.hpp`.
target_include_directories(pybind11_template PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/extern)
target_link_libraries (pybind11_template PUBLIC xtensor xtensor::optimize xtensor::use_xsimd pybind11::module xtensor-python Python::NumPy student_static rgb2gray_static)


# It must be called before adding `tests` subdirectory.
enable_testing()
add_subdirectory(tests)


# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(pybind11_template
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
