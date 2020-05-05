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
    auto seq = [] (int n) { return n; };
    Stream<int> stream{2, seq, prime};
    for (int i = 1; i < 1000; ++i) stream.get_next();

    std::cout << "Stream: The 1000th prime is "<< stream.get_next() << std::endl;
}

void eratosthenes() {
    Eratosthenes e{};
    std::cout << "Eratosthenes: The 1000th prime is "<< e.get_nth_prime(1000) << std::endl;
};

int main() {
    get_prime_with_list();
    get_prime_with_stream();
    eratosthenes();
}
