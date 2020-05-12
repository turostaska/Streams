#include <memory>
#include <functional>

template <typename T>
struct StreamElement {
    T data;
    std::function< std::unique_ptr<StreamElement<T>> () > next;
    StreamElement(T);
    StreamElement(T, std::function< std::unique_ptr<StreamElement<T>> () >);

    static std::unique_ptr<StreamElement<T>> make_int_stream(T from, T to);
    static std::unique_ptr<StreamElement<T>> make_infinite_stream(T from);
    static std::unique_ptr<StreamElement<T>> filter(const std::unique_ptr< StreamElement<T> > & str, std::function<bool(T)> pred);
    static std::unique_ptr<StreamElement<unsigned>> make_eratosthenes(const std::unique_ptr<StreamElement<unsigned>> &);
};




