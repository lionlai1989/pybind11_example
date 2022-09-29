#include "Student.h"
#include "my_eigen.h"
#include <Eigen/Dense>
#include <iostream>
int main(int argc, char *argv[]) {
  Student s("Joe");
  s.display();

  Eigen::Matrix<float, 3, 1> v{1, 2, 3};
  std::cout << v << std::endl;
  auto ret = crossMatrix(v);
  std::cout << ret << std::endl;
  return 0;
}
