#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i=1, int j=2) {
    return i + j;
}

// Use plugin to return object
PYBIND11_PLUGIN(example) {
    py::module m("example", "pybind11 example plugin");
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers",
          py::arg("i")=1, py::arg("j")=2);

    // shorthand
    using namespace pybind11::literals;
    m.def("add2", &add, "i"_a=1, "j"_a=2);

    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") = "World"; // world;
    return m.ptr();
}
