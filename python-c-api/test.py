import primes


import time

start_time = time.time()

primes_list = primes.find_primes(10000)
print(primes_list)


end_time = time.time()

time_taken = end_time - start_time

print("Time taken:", time_taken, "seconds")
