#include <Eigen/Dense>
#include <string>
#include <unsupported/Eigen/CXX11/Tensor>

class Student {
private:
  std::string name;

public:
  Student(std::string);
  const std::string get_name() const;
  virtual void display();
};
