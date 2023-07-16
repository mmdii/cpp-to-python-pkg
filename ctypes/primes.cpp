#include <vector>
#include <cmath>

extern "C" {
    bool is_prime(int n) {
        if (n <= 1) {
            return false;
        }

        for (int i = 2; i <= std::sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    std::vector<int> find_primes(int n) {
        std::vector<int> primes;

        for (int i = 2; i <= n; ++i) {
            if (is_prime(i)) {
                primes.push_back(i);
            }
        }

        return primes;
    }
}