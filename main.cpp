#include <iostream>
#include "linked_list.cpp"
#include "eratosthenes.h"

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

void get_prime_with_list() {
    LinkedList<int> list;
    for (int i = 2; i < 10000; i++)
        list.push_back(i);

    list.keep_if(prime);

    auto it = list.begin();
    for (int i = 1; i < 1000; ++i) ++it;
    std::cout << "LinkedList: The 1000th prime is "<< *it << std::endl;

}

void get_prime_with_stream() {
//    auto seq = [] (int n) { return n; };
//    Stream<int> stream{2, seq, prime};
//    for (int i = 1; i < 1000; ++i) stream.get_next();
//
//    std::cout << "Stream: The 1000th prime is "<< stream.get_next() << std::endl;
}

std::unique_ptr<StreamElement<int>> read_integers_from_stdin() {
    int n;
    if (std::cin >> n)
        return std::make_unique<StreamElement<int>>(n, read_integers_from_stdin);
    return nullptr;
}

std::unique_ptr<StreamElement<int>> integers_from_a_to_b(int a, int b) {
    if (a <= b) {
        auto b_bound = std::bind(integers_from_a_to_b, std::placeholders::_2, b);
        auto a_bound = std::bind(b_bound, std::placeholders::_1, a+1);
        return std::make_unique<StreamElement<int>>(a+1, a_bound);
    }
    return nullptr;
}

int main() {
    int n = 0;
    std::function< std::unique_ptr<StreamElement<int>> () > from_1_to_1000 = [&] () -> std::unique_ptr<StreamElement<int>> {
        n += 1;
        if (n <= 1000)
            return std::make_unique<StreamElement<int>>(n, from_1_to_1000);
        return nullptr;
    };

    Stream<int> stream{ integers_from_a_to_b };

    for (auto it = stream.begin(); it != nullptr; it = it->next(1, 1000))
        std::cout << it->data << " ";
    std::cout << std::endl;
    for (auto it = stream.begin(); it != nullptr; it = it->next())
        std::cout << it->data << " ";

}
