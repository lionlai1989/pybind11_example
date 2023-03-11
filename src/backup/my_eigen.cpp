#include <src/my_eigen.hpp>

Eigen::Matrix<float, 3, 3> crossMatrix(Eigen::Matrix<float, 3, 1> v) {
  Eigen::Matrix<float, 3, 3> m;
  m << 0, -v[2], v[1], v[2], 0, -v[0], -v[1], v[0], 0;
  return m;
}
