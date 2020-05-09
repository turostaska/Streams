#include "eratosthenes.h"

Eratosthenes::Eratosthenes() : last{ StreamElement<unsigned>::make_infinite_stream(2) } {}

unsigned Eratosthenes::next() {
        start:
        unsigned next_num = last->data;
        for (auto divisible : predicates) {
            if (divisible(next_num)) {
                last = last->next();
                goto start;
            }
        }

        predicates.push_back( [=] (unsigned n) {
            return is_divisible_by(n, next_num);
        } );

        return next_num;
}

bool Eratosthenes::is_divisible_by(unsigned what, unsigned by) {
    return what % by == 0;
}

