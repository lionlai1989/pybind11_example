
#include <mypackage/image/image_xtensor.hpp>
#include <mypackage/rgb2gray.hpp>
#include <string>

namespace mypackage {
bool image_rgb2gray(std::string input, std::string output) {
  mypackage::image::ImageXTensor in_img{input};
  auto out_img = mypackage::image::rgb_to_grayscale_xtensor(in_img);
  out_img.save(output);
  return 0;
}

xt::xarray<double> pixel_rgb2gray(const xt::xarray<double> &pixels) {
  return mypackage::image::rgb_to_grayscale_xtensor(pixels);
}

} // namespace mypackage
