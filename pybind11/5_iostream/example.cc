#include <pybind11/iostream.h>
#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void noisy_function(std::string msg, bool flush) {
    std::cout << msg;
    if (flush)
        std::cout << std::flush;
}

void noisy_funct_dual(std::string msg, std::string emsg) {
    std::cout << msg;
    std::cerr << emsg;
}

PYBIND11_PLUGIN(example) {
    py::module m("example", "pybind11 example plugin");

    add_ostream_redirect(m);
    m.def("captured_output_default", [](std::string msg) {
        py::scoped_ostream_redirect redir;
        std::cout << msg << std::flush;
    });

    m.def("captured_output", [](std::string msg) {
        py::scoped_ostream_redirect redir(std::cout, py::module::import("sys").attr("stdout"));
        std::cout << msg << std::flush;
    });

    m.def("guard_output", &noisy_function,
            py::call_guard<py::scoped_ostream_redirect>(),
            py::arg("msg"), py::arg("flush")=true);

    m.def("captured_err", [](std::string msg) {
        py::scoped_ostream_redirect redir(std::cerr, py::module::import("sys").attr("stderr"));
        std::cerr << msg << std::flush;
    });

    m.def("noisy_function", &noisy_function, py::arg("msg"), py::arg("flush") = true);

    m.def("dual_guard", &noisy_funct_dual,
            py::call_guard<py::scoped_ostream_redirect, py::scoped_estream_redirect>(),
            py::arg("msg"), py::arg("emsg"));

    m.def("raw_output", [](std::string msg) {
        std::cout << msg << std::flush;
    });

    m.def("raw_err", [](std::string msg) {
        std::cerr << msg << std::flush;
    });

    m.def("captured_dual", [](std::string msg, std::string emsg) {
        py::scoped_ostream_redirect redirout(std::cout, py::module::import("sys").attr("stdout"));
        py::scoped_ostream_redirect redirerr(std::cerr, py::module::import("sys").attr("stderr"));
        std::cout << msg << std::flush;
        std::cerr << emsg << std::flush;
    });
}
