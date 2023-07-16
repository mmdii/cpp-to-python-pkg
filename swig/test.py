import primes

# Create a vector of integers
vec = primes.IntVector([1, 2, 3, 4, 5])

# Append a new element to the vector
vec.append(6)

# Print the vector
print(vec)

# Access an element of the vector
print(vec[2])

# Iterate over the vector
for x in vec:
    print(x)