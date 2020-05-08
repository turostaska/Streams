#include <vector>
#include "stream.cpp"

class Eratosthenes {
private:
    std::vector<unsigned> primes;
    //Stream<unsigned> stream;
public:
    Eratosthenes();
    unsigned get_nth_prime(size_t);

};
