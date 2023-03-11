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

struct Car {
  int num_window;
  int num_tire;
  std::array<uint8_t, 7> maintenance_per_week;
};
