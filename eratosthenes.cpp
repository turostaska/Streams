#include "eratosthenes.h"

Eratosthenes::Eratosthenes() {}

unsigned Eratosthenes::get_nth_prime(size_t n) {
    start:
    while (primes.size() < n) {
        int to_try = 0;//stream.get_next();
        for (unsigned i = 0; i < primes.size() && primes[i]*primes[i] <= to_try; ++i) {
            if (to_try % primes[i] == 0)
                goto start;
        }
        primes.push_back(to_try);
    }
    return primes[n-1];
}
