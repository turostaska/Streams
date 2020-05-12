#include <vector>
#include "stream.cpp"

class Eratosthenes {
private:
    std::unique_ptr< StreamElement<unsigned> > last;
public:
    Eratosthenes();
    unsigned next();
};
