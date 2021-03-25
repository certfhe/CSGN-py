// pybind11_wrapper.cpp
#include <pybind11/pybind11.h>
#include "certFHE.h"

namespace py = pybind11;

using namespace certFHE;

PYBIND11_MODULE(certfhepy, m)
{
    py::class_<Context>(m, "Context")
        .def(py::init<const uint64_t, const uint64_t>())
        .def(py::init<Context &>())
        .def("operator=", &Context::operator=)
        .def("getN", &Context::getN)
        .def("getD", &Context::getD)
        .def("getS", &Context::getS)
        .def("getDefaultN", &Context::getDefaultN)
        .def("setN", &Context::setN)
        .def("setD", &Context::setD);

    py::class_<Permutation>(m, "Permutation")
        .def(py::init<>())
        .def(py::init<const uint64_t *, const uint64_t>())
        .def(py::init<Context &>())
        .def(py::init<const uint64_t>())
        .def(py::init<const Permutation &>())
        .def("operator=", &Permutation::operator=)
        .def("operator+", &Permutation::operator+)
        .def("operator+=", &Permutation::operator+=)
        .def("getLength", &Permutation::getLength)
        .def("getPermutation", &Permutation::getPermutation)
        .def("getInverse", &Permutation::getInverse);

    py::class_<Ciphertext>(m, "Ciphertext")
        .def(py::init<>())
        .def(py::init<const uint64_t *, const uint64_t *, const uint64_t, const Context &>())
        .def(py::init<Ciphertext &>())
        .def("operator+", &Ciphertext::operator+)
        .def("operator+=", &Ciphertext::operator+=)
        .def("operator*", &Ciphertext::operator*)
        .def("operator*=", &Ciphertext::operator*=)
        .def("setValues", &Ciphertext::setValues)
        .def("setBitlen", &Ciphertext::setBitlen)
        .def("setContext", &Ciphertext::setContext)
        .def("getLen", &Ciphertext::getLen)
        .def("getContext", &Ciphertext::getContext)
        .def("getValues", &Ciphertext::getValues)
        .def("getBitlen", &Ciphertext::getBitlen)
        .def("applyPermutation_inplace", &Ciphertext::applyPermutation_inplace)
        .def("applyPermutation", &Ciphertext::applyPermutation)
        .def("size", &Ciphertext::size);

    py::class_<Plaintext>(m, "Plaintext")
        .def(py::init<>())
        .def(py::init<const int>())
        .def("getValue", &Plaintext::getValue)
        .def("setValue", &Plaintext::setValue);

    py::class_<SecretKey>(m, "SecretKey")
        .def(py::init<const Context &>())
        .def(py::init<const SecretKey &>())
        .def("operator=", &SecretKey::operator=)
        .def("encrypt", static_cast<Ciphertext (SecretKey::*)(Plaintext &)>(&SecretKey::encrypt))
        .def("decrypt", static_cast<Plaintext (SecretKey::*)(Ciphertext &)>(&SecretKey::decrypt))
        .def("applyPermutation_inplace", &SecretKey::applyPermutation_inplace)
        .def("applyPermutation", &SecretKey::applyPermutation)
        .def("getLength", &SecretKey::getLength)
        .def("getKey", &SecretKey::getKey)
        .def("setKey", &SecretKey::setKey)
        .def("size", &SecretKey::size);
}
