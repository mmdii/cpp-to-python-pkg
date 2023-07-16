# How to Use Cython to Build a Python Extension Module to Find Prime Numbers

## Step 1 : install cython

- Linux :

```bash
apt install cython3
```

- Linux :

```bash
pip3 install cython
```

- windows :

```bash
pip install cython
```

## Step 2 : Write the Cython code

Once you have installed Cython, you can start writing your code. In this example, we will write a program to find all prime numbers up to a given number. We will write the code in a file called ```primes.pyx```, which is the ```Cython``` file format.

## Step 3 :  Build the Cython code

To build the Cython code, you need to run the following command in the terminal:

```bash
cython primes.pyx --embed
```

This command will generate a ```C``` file called ```primes.c```.

## Step 4 : Generate a shared library

Now that you have generated the ```C file```, you need to compile it into a shared library that you can use in your Python code. To do this, run the following command in the terminal:

```bash
gcc -shared -pthread -fPIC -fwrapv -O2 -Wall -fno-strict-aliasing -I/usr/include/python3.11 -o primes.so primes.c

```

Note that you need to replace /usr/include/python3.11 with the path to the Python header files on your system. This path may be different depending on your Python version and installation.

## Step 5 : Use the shared library in your Python code

Now that you have generated the shared library, you can use it in your Python code. To do this, simply import the primes module in your Python code:

```python
import primes

primes_list = primes.find_primes(100)
print(primes_list)
```

This should print out a list of prime numbers up to 100.
