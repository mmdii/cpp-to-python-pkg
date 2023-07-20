import primes

import time

start_time = time.time()

# Create a vector of integers
# vec = primes.IntVector([1, 2, 3, 4, 5])

hi = primes.find_primes(10000)

for h in hi:
    print(h)

# # Iterate over the vector
# for x in vec:
#     print(x)


end_time = time.time()

time_taken = end_time - start_time

print("Time taken:", time_taken, "seconds")
