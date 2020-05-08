#include "stream.h"

template<typename T>
StreamElement<T>::StreamElement(T data) : data{data}, next{nullptr} {}

template<typename T>
StreamElement<T>::StreamElement(T data, std::function<std::unique_ptr<StreamElement<T>> ()> fun)
    : data{data}, next{fun} {}

template<typename T>
std::unique_ptr<StreamElement<T>> Stream<T>::begin() {
    return first->next();
}

template<typename T>
Stream<T>::Stream(std::function< std::unique_ptr<StreamElement<T>> () > fun) {
    first = std::make_unique<StreamElement<T>>( T{}, fun );
}
