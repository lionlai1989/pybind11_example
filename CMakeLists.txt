cmake_minimum_required(VERSION 3.20...3.25)
project(pybind11_eigen VERSION 0.0.1)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(runtest "Build all tests." OFF) # Makes boolean 'test' available.

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# This disables the use of compiler-specific extensions. For example, by
# default, CMake passes -std=gnu++14 to GCC on Linux. We want to build with
# -std=c++14 to prevent use of non-portable compiler extensions, which is what
# the disabling of this option does. 
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall --std=c++17 -O3 -fPIC")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_subdirectory(src)

include_directories("/usr/local/include/eigen-3.4.0")

add_subdirectory(./extern/pybind11)
pybind11_add_module(pybind11_eigen pybind11_eigen.cpp)
target_link_libraries(pybind11_eigen PRIVATE srclib)
target_include_directories(pybind11_eigen PRIVATE  ${CMAKE_SOURCE_DIR})


# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(pybind11_eigen PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

################################
# Testing
################################
if (runtest)
    include(FetchContent)
    FetchContent_Declare(
      googletest
      # Specify the commit you depend on and update it regularly.
      URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    add_executable(
      hello_test
      ./tests/hello_test.cpp
    )
    target_link_libraries(
      hello_test
      GTest::gtest_main
      srclib
    )
    target_include_directories(hello_test PRIVATE ${CMAKE_SOURCE_DIR})

    include(GoogleTest)
    gtest_discover_tests(hello_test)
endif()
