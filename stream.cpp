#include "stream.h"

template <typename T>
StreamElement<T>::StreamElement(T data) : data{data}, next{nullptr} {}

template <typename T>
StreamElement<T>::StreamElement(T data, std::function<std::unique_ptr<StreamElement<T>> ()> fun)
    : data{data}, next{fun} {}

template <typename T>
std::unique_ptr<StreamElement<T>> StreamElement<T>::make_int_stream(T from, T to) {
    if (from <= to)
        return std::make_unique<StreamElement<T>>(from, [=] () {
            return make_int_stream(from+1, to);
        } );
    return nullptr;
}

template <typename T>
std::unique_ptr<StreamElement<T>> StreamElement<T>::make_infinite_stream(T from) {
    return std::make_unique<StreamElement<T>>(from, [=] () {
        return make_infinite_stream(from+1);
    } );
}

template<typename T>
std::unique_ptr<StreamElement<T>> StreamElement<T>::filter(const std::unique_ptr<StreamElement<T>> & str, std::function<bool(T)> pred) {
    if (str->next() == nullptr)
        return std::make_unique<StreamElement<T>>(str->data, [] () {return nullptr; });

    if (pred(str->data)) {
        return std::make_unique<StreamElement<T>>(str->data, [next{str->next}, pred] () {
            return StreamElement<T>::filter(next(), pred);
        });
    }
    return StreamElement<T>::filter(str->next(), pred);
}



