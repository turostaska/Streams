#include <memory>
#include <functional>

template <typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
struct StreamElement {
    T data;
    std::function< std::unique_ptr<StreamElement<T>> () > next;
    StreamElement(T);
    StreamElement(T, std::function< std::unique_ptr<StreamElement<T>> () >);

    static std::unique_ptr<StreamElement<T>> make_int_stream(T from, T to);
    static std::unique_ptr<StreamElement<T>> make_infinite_stream(T from);
};




