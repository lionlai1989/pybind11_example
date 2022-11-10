include_directories("/usr/local/include/eigen-3.4.0")

# Can manually add the sources using the set command as follows:
# set(SOURCES "./my_eigen.cpp" "./Student.cpp")
# However, the file(GLOB...) allows for wildcard additions:
# file(GLOB SOURCES "./*.cpp")

# # Generate the shared library from the sources
# add_library(srclib SHARED ${SOURCES})

add_library(myeigen STATIC
            my_eigen.hpp
            my_eigen.cpp
)

add_library(student STATIC
            Student.hpp
            Student.cpp
)

# set_target_properties(myeigen PROPERTIES LINKER_LANGUAGE CXX)
# set_target_properties(student PROPERTIES LINKER_LANGUAGE CXX)
