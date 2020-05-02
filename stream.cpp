#include "stream.h"

template<typename T>
Stream<T>::Stream(int start, std::function<T(int)> seq, std::function<bool(T)> pred) :
    sequence{seq}, predicate{pred}, current_num{start}, first{nullptr}, last{nullptr}, size{0} {}

template<typename T>
T& Stream<T>::back() {
    auto node = std::make_shared<StreamNode>( get_next_element() );
    if (!last) {
        first = node;
        last = node;
    } else {
        last->next = node;
        last = last->next;
    }
    size++;
    return last->data;
}

template<typename T>
T Stream<T>::get_next_element() {
    while(1) {
        if ( predicate( sequence(current_num++) ) )
            return sequence(current_num-1);
    }
}

template<typename T>
size_t Stream<T>::get_size() const {
    return size;
}

template<typename T>
Stream<T>::StreamNode::StreamNode(T data) : data{data}, next{nullptr} {}
