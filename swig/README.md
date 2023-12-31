# How to Use SWIG Build a Python Extension Module to Find Prime Numbers

## Step 1 : Create a file called `primes.i`

This file tells SWIG to generate a Python module called `primes` that includes the functions defined in `primes.h`.

## Step 2 : Create a file called `primes.h`

This file defines a function called `find_primes` that takes an integer `n` and returns a vector of prime numbers up to `n`.

## Step 3 : Create a file called `primes.cpp`

This file implements the `find_primes` function using the sieve of Eratosthenes algorithm.

## Step 4 : Generate the wrapper code using SWIG. Run the following command in the terminal

   ```bash
   swig -c++ -python primes.i
   ```

This generates a file called `primes_wrap.cxx` that contains the wrapper code for the `find_primes` function.

## Step 5 : Build the C++ extension module. Run the following commands

   ```bash
   g++ -c -fPIC primes.cpp primes_wrap.cxx -I/usr/include/python3.9
   g++ -shared primes.o primes_wrap.o -o _primes.so
   ```

   This compiles the `primes.cpp` and `primes_wrap.cxx` files, and links them into a shared object file called `_primes.so`.

## Step 6 : Use the C++ extension module in Python. To do this, simply import the `primes` module in your Python code

   ```python
   import primes

   primes_list = primes.find_primes(100)
   print(primes_list)
   ```

   This should print out a list of prime numbers up to 100.

## Installing SWIG on Linux and Windows

Installing SWIG on Debian:

1. Open a terminal window.

2. Run the following command to update the package list:

   ```bash
   sudo apt-get update
   ```

3. Run the following command to install SWIG:

   ```bash
   sudo apt-get install swig
   `````

4. Verify that SWIG is installed by running the following command:

   ```bash
   swig -version
   ```

This should print the version number of SWIG.

Installing SWIG on Windows:

1. Download the SWIG installer from the SWIG website (<http://www.swig.org/download.html>).

2. Double-click the installer file to launch the installation wizard.

3. Follow the prompts in the installation wizard to install SWIG.

4. Once the installation is complete, open a command prompt and verify that SWIG is installed by running the following command:

   ```bash
   swig -version
   ```

   This should print the version number of SWIG.

That's it! You should now have SWIG installed on your Debian or Windows system.

## how you can build the C++ extension module on Windows

- Install the following software on your Windows machine:
  - Microsoft Visual C++ Compiler for Python 2.7/3.4/3.5/3.6 (can be downloaded from [https://www.microsoft.com/en-us/download/details.aspx?id=44266) ↗](https://www.microsoft.com/en-us/download/details.aspx?id=44266))
  - Python Development Libraries (can be installed using pip, e.g. `pip install python-dev-tools`)
  - Setuptools (can be installed using pip, e.g. `pip install setuptools`)

- Create a file called `primes.i` :

   This file tells SWIG to generate a Python module called `primes` that includes the functions defined in `primes.h`.

- Create a file called `primes.h`:

   This file defines a function called `find_primes` that takes an integer `n` and returns a vector of prime numbers up to `n`.

- Create a file called `primes.cpp` :
   This file implements the `find_primes` function using the sieve of Eratosthenes algorithm.

- Generate the wrapper code using SWIG. Open a command prompt and navigate to the directory containing the `primes.i` file. Then run the following command:

   ```cmd
   swig -c++ -python primes.i
   ```

   This generates a file called `primes_wrap.cxx` that contains the wrapper code for the `find_primes` function.

6. Build the C++ extension module. Run the following commands in the command prompt:

   ```cmd
   cl /c /EHsc primes.cpp primes_wrap.cxx /I"C:\Python36\include"
   link /DLL /OUT:primes.pyd primes.obj primes_wrap.obj /LIBPATH:"C:\Python36\libs"
   ```

   These commands compile the `primes.cpp` and `primes_wrap.cxx` files, and link them into a shared library called `primes.pyd`. Note that you may need to adjust the path to the Python include and library directories depending on your installation location.

- Use the C++ extension module in Python. To do this, simply import the `primes` module in your Python code:

   ```python
   import primes

   primes_list = primes.find_primes(100)
   print(primes_list)
   ```

   This should print out a list of prime numbers up to 100.

## Step 7 : Generate Python Package To Install With pip3 or pip both on windows and linux

To package a SWIG module along with a pre-built shared library, you can create a setup.py file that specifies the package metadata and how to include the shared library in the package.

In this example, we include our SWIG module primes.i as an extension module. The Extension object specifies the sources files primes_wrap.cxx and primes.cpp as well as the shared library prime as a dependency using the libraries option, and include the current directory (".") as a search path for the library using the library_dirs option. We also include the SWIG options -c++ and -py3 to generate a C++ wrapper for Python 3.

We also include the shared library file _primes.so as a data file using the data_files option. This will include the file in the package when it is built.

Once you have created your setup.py file, you can build the package by running the following command in the directory where the setup.py file is located:

```bash
python3 setup.py sdist bdist_wheel
```

This will create a source distribution (sdist) and a binary distribution (bdist_wheel) of your package in the dist/ directory.

You can then install the package using pip3 or pip by running:

```bash
pip3 install primes-1.0.0.tar.gz
```

This will install the package along with the SWIG module and the shared library, and make it available for use in your Python code. Note that the shared library file must be compatible with the system architecture and Python version of the user's system in order to work correctly.
