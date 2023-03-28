add_executable(test_image_xtensor test_image_xtensor.cpp)

target_link_libraries(
  test_image_xtensor
  GTest::gtest_main
  image_xtensor
)

target_include_directories(test_image_xtensor PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_compile_features(test_image_xtensor PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(test_image_xtensor)
