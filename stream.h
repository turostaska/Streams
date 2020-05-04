#include <memory>
#include <functional>

template <typename T>
class Stream {
private:
    std::function<T(int)> sequence;
    std::function<T(int)> predicate;
    int current_num;
    T get_next_element();
public:
    Stream( int = 1, std::function<T(int)> = [] (int n) { return n; },
            std::function<bool(T)> = [] (T) {return true;} );
    std::shared_ptr<T> get_next();
};
