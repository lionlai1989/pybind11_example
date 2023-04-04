// #include <src/my_eigen.hpp> // <---------- this needs to be commented out.
#include <iostream>
#include <pybind11/eigen.h> // It must be used here. It doesn't work with <Eigen/Dense>.
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
//#include <unsupported/Eigen/CXX11/Tensor>
// #include <src/Student.hpp>

namespace py = pybind11;

// Eigen::Matrix<float, 3, 3> crossMatrix(Eigen::Matrix<float, 3, 1> v) {
//   Eigen::Matrix<float, 3, 3> m;
//   m << 0, -v[2], v[1], v[2], 0, -v[0], -v[1], v[0], 0;
//   return m;
// }

// Eigen::Matrix<float, 3, 3> wrapper_crossMatrix(Eigen::Matrix<float, 3, 1> v)
// {
//   auto m = crossMatrix(v);
//   return m;
// }

// std::vector<Car> buy_car() {
//   std::vector<Car> vector_cars;
//   Car c;
//   c.num_window = 6;
//   c.num_tire = 4;
//   c.maintenance_per_week = {1, 2, 3, 4, 5, 6, 7};
//   vector_cars.emplace_back(c);
//   return vector_cars;
// }

PYBIND11_MODULE(pybind11_template, m) {
  // the following line doesn't work. if applied, there will be import error.
  // python3 -m pip install -e . doesn't work.
  m.def("crossMatrix", &wrapper_crossMatrix);

  // m.def("buy_car", &buy_car);

  // py::class_<Student>(m, "Student")
  //       .def(py::init<const std::string &>())
  //       .def("display", &Student::display)
  //       .def("get_name", &Student::get_name);

  // py::class_<Car>(m, "Car")
  //     .def(py::init<>()) // <-- bind the default constructor
  //     .def_readwrite("num_window", &Car::num_window)
  //     .def_readwrite("num_tire", &Car::num_tire)
  //     .def_readwrite("maintenance_per_week", &Car::maintenance_per_week);
}
