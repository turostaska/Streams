#include "stream.h"

template<typename T>
Stream<T>::Stream(int start, std::function<T(int)> seq, std::function<bool(T)> pred) :
    sequence{seq}, predicate{pred}, current_num{start} {}

template<typename T>
std::shared_ptr<T> Stream<T>::get_next() {
    auto element = std::make_shared<T>( get_next_element() );
    return element;
}

template<typename T>
T Stream<T>::get_next_element() {
    while(1) {
        if ( predicate( sequence(current_num++) ) )
            return sequence(current_num-1);
    }
}
