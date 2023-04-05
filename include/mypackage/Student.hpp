#include <string>

class Student {
private:
  std::string name;

public:
  Student(std::string);
  const std::string get_name() const;
  virtual void display();
};
