#include <Python.h> // Include the Python C API header file.

// Define a function to find prime numbers.
static PyObject *find_primes(PyObject *self, PyObject *args)
{
    int n;
    if (!PyArg_ParseTuple(args, "i", &n))
    {
        return NULL;
    }

    // Create a new empty list to store the prime numbers.
    PyObject *primes = PyList_New(0);
    if (!primes)
    {
        return NULL;
    }

    // Loop through all numbers up to n and check if they're prime.
    for (int i = 2; i <= n; i++)
    {
        int is_prime = 1;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
        {
            // If i is prime, add it to the list of prime numbers.
            PyObject *prime = PyLong_FromLong(i);
            if (!prime)
            {
                Py_DECREF(primes);
                return NULL;
            }
            if (PyList_Append(primes, prime) == -1)
            {
                Py_DECREF(primes);
                Py_DECREF(prime);
                return NULL;
            }
            Py_DECREF(prime);
        }
    }

    // Return the list of prime numbers.
    return primes;
}

// Define a list of functions and their metadata.
static PyMethodDef methods[] = {
    {"find_primes", find_primes, METH_VARARGS, "Find prime numbers up to a given number"},
    {NULL, NULL, 0, NULL}};

// Define a module initialization function.
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "primes",
    NULL,
    -1,
    methods};

// Define the module initialization function using the PyMODINIT_FUNC macro.
PyMODINIT_FUNC PyInit_primes(void)
{
    return PyModule_Create(&moduledef);
}