#include <iostream>
#include "linked_list.cpp"
#include "stream.cpp"

auto prime = [] (unsigned x) {
    if (x < 2)
        return false;

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

std::unique_ptr<StreamElement<int>> read_integers_from_stdin() {
    int n;
    if (std::cin >> n)
        return std::make_unique<StreamElement<int>>(n, read_integers_from_stdin);
    return nullptr;
}

std::unique_ptr<StreamElement<unsigned>> make_prime_stream(unsigned from = 2) {
    while (!prime(from))
        from++;

    return std::make_unique<StreamElement<unsigned>>(from, [=] () {
        return make_prime_stream(from+1);
    } );
}

int main() {
    auto from_1 = StreamElement<int>::make_infinite_stream(1);
    auto it = StreamElement<int>::filter(from_1, prime);
    for (int i = 0; i < 999; ++i) {

        it = it->next();
    }
    std::cout << "Az 1000. prím szűrés alapján: " << it->data << std::endl;

    auto from_2 = StreamElement<unsigned>::make_infinite_stream(2);
    auto eratosthenes = StreamElement<unsigned>::make_eratosthenes( from_2 );

    for (int i = 0; i < 15; ++i) {
        std::cout << "Az " << i+1 << ". prím szita alapján: " << eratosthenes->data << std::endl;
        eratosthenes = eratosthenes->next();
    }

}
