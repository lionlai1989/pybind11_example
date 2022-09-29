#include <Eigen/Dense>
#include <string>
#include <unsupported/Eigen/CXX11/Tensor>

class Student {
private:
  std::string name;

public:
  Student(std::string);
  virtual void display();
};
