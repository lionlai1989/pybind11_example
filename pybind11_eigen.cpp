#include <iostream>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

Eigen::Matrix<float, 3, 3> crossMatrix(Eigen::Matrix<float, 3, 1> v) {
  Eigen::Matrix<float, 3, 3> m;
  m << 0, -v[2], v[1], v[2], 0, -v[0], -v[1], v[0], 0;
  return m;
}

PYBIND11_MODULE(pybind11_eigen, m) { m.def("crossMatrix", &crossMatrix); }
