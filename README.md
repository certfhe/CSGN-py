# certfhe-py
python bindings for certfhe library

# Description
certfhe-py is a python wrapper over the library certFHE, realized using pybind11, a library used to map c++ classes to python classes

# Documentation
Full documentation about python bindings is available from the author, on [readthedocs](https://pybind11.readthedocs.io/en/latest/classes.html#overloaded-methods)

There are multiple methods on realizing the binding, the most important of them is nicely explained by [this guy](https://realpython.com/python-bindings-overview/#pybind11)

Besides pybind11, the tricks are done by CMake building system, pretty much available everywhere. The is no more magic in CMake once you master it, but for that you need to read [the documentation](https://cmake.org/cmake/help/v3.15/)

# Externals
Both certfhe and pybind11 are included as git submodules inside **externals** directory and you should ensure that you have the update versions of them, before compiling

* pybind11 is the libray that did the trick on exporting certfhe classes to python, also available on github
* certfhe library is also available on github

# Building


# Testing



