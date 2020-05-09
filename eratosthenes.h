#include <vector>
#include "stream.cpp"

class Eratosthenes {
private:
    std::vector< std::function< bool(unsigned) > > predicates;
    std::unique_ptr< StreamElement<unsigned> > last;
    static bool is_divisible_by(unsigned what, unsigned by);
public:
    Eratosthenes();
    unsigned next();
};
