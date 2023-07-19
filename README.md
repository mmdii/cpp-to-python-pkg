# cpp-to-python-pkg

This repository contains several methods to write C++ code and convert it into a Python package. The resulting Python package can be used in any Python project, allowing you to take advantage of the performance benefits of C++ without sacrificing the ease of use of Python.

- [Cython ↗](https://cython.org/)
- [pybind11 ↗](https://pybind11.readthedocs.io/en/stable/)
- [ctypes ↗](https://docs.python.org/3/library/ctypes.html)
- [Python-C-API ↗](https://docs.python.org/3/c-api/)
- [SWIG ↗](http://www.swig.org/)

These tools provide different levels of control and flexibility for integrating C/C++ code with Python, and may be preferred depending on the specific use case.

To ensure compatibility across multiple operating systems, we have tested each of these tools on Linux, macOS, and Windows. The following chart shows the compatibility of each tool with each operating system:

| Tool        | Linux | macOS | Windows |
| ----------- | ----- | ----- | ------- |
| Cython      | ✔️    | ✔️    | ✔️      |
| pybind11    | ✔️    | ✔️    | ✔️      |
| ctypes      | ✔️    | ✔️    | ✔️      |
| Python-C-API | ✔️    | ✔️    | ✔️      |
| SWIG        | ✔️    | ✔️    | ✔️      |

Note that some tools may require additional setup or configuration on certain operating systems. Please refer to the documentation for each tool for more information.

## Getting Started

To get started, simply clone this repository to your local machine:

```bash
git clone https://github.com/mmdii/cpp-to-python-pkg.git
```

The repository contains several folders, each of which contains a different method for creating a C++ library and converting it into a Python package. Each folder contains its own README file with instructions on how to build and use the package.

## Supported Platforms

This repository has been tested on the following platforms:

- Windows 10 with Visual Studio 2019
- Ubuntu 20.04 with GCC 9.3.0
- Debian 12 with GCC 9.3.0

It may work on other platforms as well, but this has not been tested.

## License

This project is licensed under the [MIT License](LICENSE).
