#include "linked_list.cpp"
#include "stream.cpp"

int main() {
    auto prime = [] (int x) {
        bool is_prime = true;
        for (int i = 2; i*i <= x; ++i ) {
            if (x % i == 0) {
                is_prime = false;
                break;
            }
        }
        return is_prime;
    };

//    Stream<int> prime_stream{ 2, [] (int i) {return i;}, prime };
//    for (int i = 0; i < 999999; i++)
//        prime_stream.get_next();
//    std::cout << "The 1,000,000th prime number is " << *prime_stream.get_next() << std::endl;

    LinkedList<int> list;
    list.push_back(0);
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(0);
    list.push_back(3);
    list.push_back(4);
    list.push_back(0);
    list.push_back(5);
    list.push_back(0);
    list.push_back(0);
    list.push_back(0);

    std::cout << "first: " << list.front() << std::endl;
    std::cout << "last: "  << list.back() << std::endl;
    list.remove(0);
    std::cout << list << std::endl;
    list.keep_if([] (int n) { return n != 0; });
    std::cout << list << std::endl;
    list.remove(list.back());
    std::cout << list << std::endl;
}
