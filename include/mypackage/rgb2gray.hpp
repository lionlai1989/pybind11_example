#ifndef RGB2GRAY_HPP
#define RGB2GRAY_HPP

#include <iostream>

// NOTE: It needs to be included so the compiler can understand `xt::xarray`.
#include <xtensor/xarray.hpp>

namespace mypackage {
bool image_rgb2gray(std::string input, std::string output);
xt::xarray<double> pixel_rgb2gray(const xt::xarray<double> &pixels);

} // namespace mypackage

#endif
