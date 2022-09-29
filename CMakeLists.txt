cmake_minimum_required(VERSION 3.16.3)
project(cmake_example VERSION 0.0.1)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


# Bring the headers, such as Student.h into the project
include_directories(include)
include_directories("/usr/local/include/eigen-3.4.0")

# Can manually add the sources using the set command as follows:
# set(SOURCES src/mainapp.cpp src/Student.cpp)
# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(run_mainapp ${SOURCES})
add_library(testStudent STATIC ${SOURCES})

add_subdirectory("./extern/pybind11")
pybind11_add_module(pybind11_eigen ./pybind11_eigen.cpp)

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
  testStudent
)

include(GoogleTest)
gtest_discover_tests(hello_test)
