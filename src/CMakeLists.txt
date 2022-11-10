include_directories("/usr/local/include/eigen-3.4.0")

# Can manually add the sources using the set command as follows:
# set(SOURCES "./my_eigen.cpp" "./Student.cpp")
# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "./*.cpp" "./*.hpp")

# Generate the shared library from the sources
add_library(srclib SHARED ${SOURCES})
