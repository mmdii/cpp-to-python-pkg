# How to Use Ctypes Build a Python Extension Module to Find Prime Numbers

## Step 1 : Create a file called `primes.cpp`

now write the code in it . This code defines two functions, is_prime and find_primes, using the extern "C" syntax to ensure that the functions have C linkage.

## Step 2 : Build the C++ extension module. Run the following commands

Next, build the shared library for the C++ code. On Windows, you can use the Visual C++ compiler and the following commands

- windows :

    ```bash
    cl /c /EHsc primes.cpp /I"<path_to_python_include>"
    link /dll /out:primes.dll primes.obj /LIBPATH:"<path_to_python_libraries>"
    ```

- Linux (in this case Debian 12):

    ```bash
    g++ -shared -fPIC primes.cpp -o primes.so -I"<path_to_python_include>"
    ```

## Step 3 : load the shared library

Now, you can load the shared library in Python using ctypes. Here's an example script that calls the find_primes function

This script ```test.py``` loads the shared library using ctypes.CDLL, defines the argument and return types for the is_prime and find_primes functions using the argtypes and restype attributes, calls the find_primes function, and converts the result to a Python list. The output should be a list of prime numbers up to 100.
