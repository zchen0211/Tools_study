#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> add_arrays(py::array_t<double> i, py::array_t<double> j)
{
  py::buffer_info info_i = i.request();
  py::buffer_info info_j = j.request();

  if ((info_i.ndim != 1) || (info_j.ndim != 1))
    throw std::runtime_error("Number of dimensions must be one");

  if (info_i.shape[0] != info_j.shape[0])
    throw std::runtime_error("Input shapes must be equal");

  std::vector<double> ret(info_i.shape[0]);
  for (unsigned int idx = 0; idx < info_i.shape[0]; idx++)
    ret[idx] = ((double*)info_i.ptr)[idx] + ((double*)info_j.ptr)[idx];

  std::vector<size_t> strides = {sizeof(double)};
  std::vector<size_t> shape = {info_i.shape[0]};
  size_t ndim = 1;

  /* return py::array(py::buffer_info(ret.data(), sizeof(double),
                   py::format_descriptor<double>::value(),
                   ndim, info_i.shape, strides)); */
  return py::array(info_i.shape[0], ret.data());
}                  


PYBIND11_PLUGIN(example)
{
  py::module m("example", "Testing pybind11 with numpy arrays");

  m.def("add_arrays", &add_arrays, "Adding two numpy arrays");

  return m.ptr();
} 
