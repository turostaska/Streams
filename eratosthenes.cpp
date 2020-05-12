#include "eratosthenes.h"

Eratosthenes::Eratosthenes() : last{ StreamElement<unsigned>::make_infinite_stream(2) } {}

unsigned Eratosthenes::next() {
    unsigned head = last->data;
    last = StreamElement<unsigned>::filter(last, [=] (unsigned n) { return n == head || n % head != 0; });
    last = last->next();
    return head;
}



