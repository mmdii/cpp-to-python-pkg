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
