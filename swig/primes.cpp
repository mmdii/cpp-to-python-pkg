#include "primes.h"

std::vector<int> find_primes(int n) {
    std::vector<int> primes;
    std::vector<bool> is_prime(n+1, true);

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i*2; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

void delete_vector_int(std::vector<int> *v) {
    delete v;
}