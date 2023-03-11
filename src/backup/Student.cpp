#include <src/Student.hpp>
#include <iostream>
using namespace std;

Student::Student(string name) : name(name) {}

void Student::display() {
  cout << "Greeting!!! A student with name " << this->name << endl;
}

const std::string Student::get_name() const { return this->name; }
