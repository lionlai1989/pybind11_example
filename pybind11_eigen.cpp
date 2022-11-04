// #include "my_eigen.h" <---------- this needs to be commented out.
#include <iostream>
#include <pybind11/eigen.h> // It must be used here. It doesn't work with
//<Eigen/Dense>.
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <unsupported/Eigen/CXX11/Tensor>

namespace py = pybind11;

// Eigen::Matrix<float, 3, 3> wrapper_crossMatrix(Eigen::Matrix<float, 3, 1> v)
// {
//   // Eigen::Matrix<float, 3, 3> m;
//   // m << 0, -v[2], v[1], v[2], 0, -v[0], -v[1], v[0], 0;
//   auto m = crossMatrix(v);
//   return m;
// }

// // return 3 dimensional ndarray with reversed order of input ndarray
// template<class T>
// py::array_t<T> eigenTensor(py::array_t<T> inArray) {

//     // request a buffer descriptor from Python
//     py::buffer_info buffer_info = inArray.request();

//     // extract data an shape of input array
//     T *data = static_cast<T *>(buffer_info.ptr);
//     std::vector<ssize_t> shape = buffer_info.shape;

//     // wrap ndarray in Eigen::Map:
//     // the second template argument is the rank of the tensor and has to be
//     known at compile time Eigen::TensorMap<Eigen::Tensor<T, 3>>
//     in_tensor(data, shape[0], shape[1], shape[2]);

//     // build result tensor with reverse ordering
//     Eigen::Tensor<T, 3> out_tensor(2, 2, 2);
//     for (int i=0; i < shape[0]; i++) {
//         for (int j=0; j < shape[1]; j++) {
//             for (int k=0; k < shape[2]; k++) {
//                 out_tensor(k, j, i) = in_tensor(i, j, k);
//             }
//         }

//     }

//     // return numpy array wrapping eigen tensor's pointer
//     return py::array_t<T>(shape, // shape
//                           {shape[0] * shape[1] * sizeof(T), shape[1] *
//                           sizeof(T), sizeof(T)},  // strides
//                           out_tensor.data());  // data pointer
// }

struct Car {
  int num_window;
  int num_tire;
  std::array<uint8_t, 7> maintenance_per_week;
};

std::vector<Car> buy_car() {
  std::vector<Car> vector_cars;
  Car c;
  c.num_window = 6;
  c.num_tire = 4;
  c.maintenance_per_week = {1, 2, 3, 4, 5, 6, 7};
  vector_cars.emplace_back(c);
  return vector_cars;
}

PYBIND11_MODULE(pybind11_eigen, m) {
  // m.def("crossMatrix", &wrapper_crossMatrix);
  // m.def("eigenTensor", &eigenTensor<double>, py::return_value_policy::move,
  //       py::arg("inArray"));
  m.def("buy_car", &buy_car);
  py::class_<Car>(m, "Car")
      .def(py::init<>()) // <-- bind the default constructor
      .def_readwrite("num_window", &Car::num_window)
      .def_readwrite("num_tire", &Car::num_tire)
      .def_readwrite("maintenance_per_week", &Car::maintenance_per_week);
}
