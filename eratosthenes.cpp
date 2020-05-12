#include "eratosthenes.h"

Eratosthenes::Eratosthenes() : last{ StreamElement<unsigned>::make_infinite_stream(2) } {}

bool Eratosthenes::is_divisible_by(unsigned what, unsigned by) {
    return what % by == 0;
}

