# How to Use pybind11 to Build a Python Extension Module to Find Prime Numbers

## Step 1 : Install the necessary dependencies

On Debian 12, you can install the python3-dev and pybind11-dev packages using apt-get:

```bash
sudo apt-get update
sudo apt-get install python3-dev pybind11-dev
```

On Windows, you'll need to install Visual Studio (or the Visual Studio Build Tools) and the pybind11 library. You can install the pybind11 library using pip:

```cmd
pip install pybind11
```

## Step 2 : Write you cpp code

in this case boolean function to tell the number is prime or not

## Step 3 : Build the C++ code into a Python module

On Debian 12, you can use the following command to build the module:

```bash
g++ -O3 -Wall -shared -std=c++11 -fPIC -I/usr/include/python3.11 `python3 -m pybind11 --includes` prime.cpp -o prime`python3-config --extension-suffix`
```

On Windows, you can use the following command to build the module:
jboss-cli

```bash
cl /O2 /Wall /LD /MD /I"path\to\Python\include" /I"path\to\pybind11\include" prime.cpp /link /LIBPATH:"path\to\Python\libs" /OUT:prime.pyd
```

Note that you'll need to replace path\to\Python and path\to\pybind11 with the actual paths to your Python and pybind11 installations, respectively.

## Step 4: run in python

create python file then run created library

```python
import prime

print(prime.is_prime(7))  # True
print(prime.is_prime(12))  # False
```

## Step 5 : Generate Python Package To Install With pip3 or pip both on windows and linux

To package a Pybind11 module along with a pre-built shared library, you can create a setup.py file that specifies the package metadata and how to include the shared library in the package.

In this example, we include our Pybind11 module ```primes.cpp``` as an extension module. We specify the shared library prime as a dependency using the libraries option, and include the current directory (".") as a search path for the library using the library_dirs option.

We also include the shared library file ```prime.cpython-311-x86_64-linux-gnu.so``` as a data file using the data_files option. This will include the file in the package when it is built.

Once you have created your setup.py file, you can build the package by running the following command in the directory where the setup.py file is located:

```bash
python3 setup.py sdist bdist_wheel
```

This will create a source distribution (sdist) and a binary distribution (bdist_wheel) of your package in the dist/ directory.

You can then install the package using pip3 or pip by running:

```bash
pip3 install primes-1.0.0.tar.gz
```

This will install the package along with the Pybind11 extension module and the shared library, and make it available for use in your Python code. Note that the shared library file must be compatible with the system architecture and Python version of the user's system in order to work correctly.
