add_subdirectory(image)

add_library(rgb2gray_static STATIC)
target_sources(rgb2gray_static PUBLIC rgb2gray.cpp)

target_link_libraries(rgb2gray_static myimage)

target_include_directories(rgb2gray_static PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

target_include_directories(
    rgb2gray_static PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

target_compile_features(rgb2gray_static PRIVATE cxx_std_17)
