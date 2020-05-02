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

    Stream<int> prime_stream{ 2, [] (int i) {return i;}, prime };
    while (prime_stream.get_size() < 99999)
        prime_stream.back();
    std::cout << "The 1000th prime number is " << prime_stream.back() << std::endl;
}
