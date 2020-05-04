#include "stream.h"

template<typename T>
Stream<T>::Stream(int start, std::function<T(int)> seq, std::function<bool(T)> pred) :
    sequence{seq}, predicate{pred}, current_num{start} {}

template<typename T>
T Stream<T>::get_next() {
    return get_next_element();
}

template<typename T>
T Stream<T>::get_next_element() {
    while(1) {
        if ( predicate( sequence(current_num++) ) )
            return sequence(current_num-1);
    }
}
