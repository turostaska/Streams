#ifndef STREAM_STREAM_H
#define STREAM_STREAM_H

#include <memory>
#include <functional>

template <typename T>
class Stream {
private:
    struct StreamNode {
        std::shared_ptr<StreamNode> next;
        T data;
        StreamNode(T);
    };
    std::shared_ptr<StreamNode> first;
    std::shared_ptr<StreamNode> last;
    std::size_t size;
    std::function<T(int)> sequence;
    std::function<T(int)> predicate;
    int current_num;
    T get_next_element();
public:
    Stream( int = 1, std::function<T(int)> = [] (int n) { return n; },
            std::function<bool(T)> = [] (T) {return true;} );
    T& back();
    size_t get_size() const;
};




#endif //STREAM_STREAM_H
