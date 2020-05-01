#include "linked_list.cpp"

int main() {
    LinkedList<int> list{};
    for (int i = 2; i < 100; ++i)
        list.push_back(i);

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
    std::cout << list;
    list.keep_if(prime);
    std::cout << list;

}
