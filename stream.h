#include <memory>
#include <functional>

template <typename T>
struct StreamElement {
    T data;
    std::function< std::unique_ptr<StreamElement<T>> () > next;
    StreamElement(T);
    StreamElement(T, std::function< std::unique_ptr<StreamElement<T>> () >);
};

template <typename T>
class Stream {
private:
    std::unique_ptr<StreamElement<T>> first;
public:
    Stream(std::function< std::unique_ptr<StreamElement<T>> () >);
    std::unique_ptr<StreamElement<T>> begin();

};




