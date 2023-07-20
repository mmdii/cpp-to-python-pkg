import prime
import time


start_time = time.time()

print(prime.is_prime(7))  # True
print(prime.is_prime(12))  # False

end_time = time.time()

time_taken = end_time - start_time

print("Time taken:", time_taken, "seconds")
