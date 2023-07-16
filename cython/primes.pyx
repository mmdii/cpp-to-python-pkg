# cython: language_level=3

cdef int is_prime(int n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

cpdef list find_primes(int n):
    cdef list primes = []
    for i in range(2, n+1):
        if is_prime(i):
            primes.append(i)
    return primes