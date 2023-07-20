import ctypes

# Load the shared library
primes_lib = ctypes.CDLL("primes.so")

# Define the argument and return types for the is_prime function
primes_lib.is_prime.argtypes = [ctypes.c_int]
primes_lib.is_prime.restype = ctypes.c_bool

# Define the argument and return types for the find_primes function
primes_lib.find_primes.argtypes = [ctypes.c_int]
primes_lib.find_primes.restype = ctypes.POINTER(ctypes.c_int)

# Call the find_primes function
n = 100
primes = primes_lib.find_primes(n)

# Convert the result to a Python list
primes_list = [primes[i] for i in range(primes_lib.find_primes(n).contents.value)]

# Print the result
print(primes_list)