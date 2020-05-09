#include "stream.h"

template <typename T, typename std::enable_if_t< std::is_integral_v<T> >* IS_INT>
StreamElement<T, IS_INT>::StreamElement(T data) : data{data}, next{nullptr} {}

template <typename T, typename std::enable_if_t< std::is_integral_v<T> >* IS_INT>
StreamElement<T, IS_INT>::StreamElement(T data, std::function<std::unique_ptr<StreamElement<T>> ()> fun)
    : data{data}, next{fun} {}

template <typename T, typename std::enable_if_t< std::is_integral_v<T> >* IS_INT>
std::unique_ptr<StreamElement<T>> StreamElement<T, IS_INT>::make_int_stream(T from, T to) {
    if (from <= to)
        return std::make_unique<StreamElement<T>>(from, [=] () {
            return make_int_stream(from+1, to);
        } );
    return nullptr;
}

template <typename T, typename std::enable_if_t< std::is_integral_v<T> >* IS_INT>
std::unique_ptr<StreamElement<T>> StreamElement<T, IS_INT>::make_infinite_stream(T from) {
    return std::make_unique<StreamElement<T>>(from, [=] () {
        return make_infinite_stream(from+1);
    } );
}



