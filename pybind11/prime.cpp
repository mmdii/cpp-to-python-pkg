#include <pybind11/pybind11.h>

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

PYBIND11_MODULE(prime, m)
{
    m.doc() = "A simple module for checking prime numbers";
    m.def("is_prime", &is_prime, "Check if a number is prime");
}