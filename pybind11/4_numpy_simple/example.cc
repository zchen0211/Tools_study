#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

using arr = py::array;
using arr_t = py::array_t<uint16_t, 0>;

template<typename... Ix> arr data(const arr& a, Ix... index) {
    return arr(a.nbytes() - a.offset_at(index...), (const uint8_t *) a.data(index...));
}

template<typename... Ix> arr data_t(const arr_t& a, Ix... index) {
    return arr(a.size() - a.index_at(index...), a.data(index...));
}

template<typename... Ix> arr& mutate_data(arr& a, Ix... index) {
    auto ptr = (uint8_t *) a.mutable_data(index...);
    for (ssize_t i = 0; i < a.nbytes() - a.offset_at(index...); i++)
        ptr[i] = (uint8_t) (ptr[i] * 2);
    return a;
}

template<typename... Ix> arr_t& mutate_data_t(arr_t& a, Ix... index) {
    auto ptr = a.mutable_data(index...);
    for (ssize_t i = 0; i < a.size() - a.index_at(index...); i++)
        ptr[i]++;
    return a;
}

template<typename... Ix> ssize_t index_at(const arr& a, Ix... idx) { return a.index_at(idx...); }
template<typename... Ix> ssize_t index_at_t(const arr_t& a, Ix... idx) { return a.index_at(idx...); }
template<typename... Ix> ssize_t offset_at(const arr& a, Ix... idx) { return a.offset_at(idx...); }
template<typename... Ix> ssize_t offset_at_t(const arr_t& a, Ix... idx) { return a.offset_at(idx...); }
template<typename... Ix> ssize_t at_t(const arr_t& a, Ix... idx) { return a.at(idx...); }
template<typename... Ix> arr_t& mutate_at_t(arr_t& a, Ix... idx) { a.mutable_at(idx...)++; return a; }

#define def_index_fn(name, type) \
    m.def(#name, [](type a) { return name(a); }); \
    m.def(#name, [](type a, int i) { return name(a, i); }); \
    m.def(#name, [](type a, int i, int j) { return name(a, i, j); }); \
    m.def(#name, [](type a, int i, int j, int k) { return name(a, i, j, k); });

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

  m.def("ndim", [](const py::array& a) { return a.ndim(); });
  m.def("shape", [](const py::array& a) { return py::array(a.ndim(), a.shape()); });

  // test_index_offset
  def_index_fn(index_at, const arr&);
  def_index_fn(index_at_t, const arr_t&);
  def_index_fn(offset_at, const arr&);
  def_index_fn(offset_at_t, const arr_t&);
  // test_data
  def_index_fn(data, const arr&);
  def_index_fn(data_t, const arr_t&);
  // test_mutate_data, test_mutate_readonly
  def_index_fn(mutate_data, arr&);
  def_index_fn(mutate_data_t, arr_t&);
  def_index_fn(at_t, const arr_t&);
  def_index_fn(mutate_at_t, arr_t&);

  // test make array
  m.def("make_f_array", [] { return py::array_t<float>({ 2, 2 }, { 4, 8 }); });
  m.def("make_c_array", [] { return py::array_t<float>({ 2, 2 }, { 8, 4 }); });

  return m.ptr();
} 
