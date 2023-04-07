#include <iostream>
#include <mypackage/Student.hpp>
#include <mypackage/rgb2gray.hpp>

#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <xtensor/xarray.hpp>
#include <xtensor/xmath.hpp>

#define FORCE_IMPORT_ARRAY

#include <xtensor-python/pyarray.hpp>
#include <xtensor-python/pyvectorize.hpp>

namespace py = pybind11;

template <class T> double sum_of_sines(T &m) {
  auto sines = xt::sin(m); // sines does not actually hold values.
  return std::accumulate(sines.begin(), sines.end(), 0.0);
}

// In the Python API this a reference to a temporary variable
double sum_of_cosines(const xt::xarray<double> &m) {
  auto cosines = xt::cos(m); // cosines does not actually hold values.
  return std::accumulate(cosines.begin(), cosines.end(), 0.0);
}

Student get_student(std::string s) { return Student{s}; }

bool wrap_image_rgb2gray(std::string input, std::string output) {
  mypackage::image_rgb2gray(input, output);
  return 0;
}

xt::xarray<double> wrap_pixel_rgb2gray(const xt::xarray<double> &m) {
  return mypackage::pixel_rgb2gray(m);
}

PYBIND11_MODULE(pybind11_template, m) {
  xt::import_numpy();
  m.doc() = "Test module for xtensor python bindings";

  m.def("sum_of_sines", sum_of_sines<xt::pyarray<double>>,
        "Sum the sines of the input values");
  m.def("sum_of_cosines", sum_of_cosines,
        "Sum the cosines of the input values");

  m.def("image_rgb2gray", &wrap_image_rgb2gray);
  m.def("pixel_rgb2gray", &wrap_pixel_rgb2gray);

  m.def("get_student", &get_student);
  py::class_<Student>(m, "Student")
      .def(py::init<const std::string &>())
      .def("display", &Student::display)
      .def("get_name", &Student::get_name);
}
