#ifndef PRIMES_H
#define PRIMES_H

#include <vector>

std::vector<int> find_primes(int n);

#endif

#ifdef __cplusplus
extern "C" {
#endif

void delete_vector_int(std::vector<int> *v);

#ifdef __cplusplus
}
#endif