// pybind11_wrapper.cpp
#include <pybind11/pybind11.h>
#include <Context.h>

#include <pybind11/pybind11.h>

namespace py = pybind11;

using namespace certFHE;

PYBIND11_MODULE(certfhepy, m)
{
    py::class_<Context>(m, "Context")
        .def(py::init<const uint64_t, const uint64_t>())
        .def("getN", &Context::getN)
        .def("getD", &Context::getD)
        .def("getS", &Context::getS)
        .def("getDefaultN", &Context::getDefaultN)
        .def("setN", &Context::setN)
        .def("setD", &Context::setD);
}
