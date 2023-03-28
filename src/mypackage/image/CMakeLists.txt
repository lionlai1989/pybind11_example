# Define stb library. Every cpp files need to link to this library.
add_library(stb_library STATIC)
target_sources(stb_library PUBLIC define_stb_image.cpp)
target_include_directories(stb_library PUBLIC ${CMAKE_SOURCE_DIR}/extern)

add_library(image_xtensor STATIC)

target_link_libraries (image_xtensor xtensor xtensor::optimize xtensor::use_xsimd stb_library)

target_sources(image_xtensor PUBLIC image_xtensor.cpp)
target_include_directories(image_xtensor PUBLIC ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/extern)

target_compile_features(image_xtensor PRIVATE cxx_std_17)
# NOTE: Using -Werror is not good if underlying libraries have warnings.
target_compile_options(image_xtensor PRIVATE -Wall -Wextra -Wpedantic)

