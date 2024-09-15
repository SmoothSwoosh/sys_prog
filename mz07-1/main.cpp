#include <iostream>
#include <vector>

template <typename Container>
typename Container::value_type process(const Container &collection) {
    typename Container::value_type accumulator{};

    size_t cnt = 0;
    size_t parity = 0;
    for (auto it = collection.rbegin(); it != collection.rend() && cnt < 3; ++it) {
        if (parity % 2 == 0) {
            accumulator += *it;
            ++cnt;
        }
        ++parity;
    }

    return accumulator;
}

int main() {
    std::vector<int> shrek{1, 2, 3, 4, 5, 6, 7, 8, 9};

    int ac = process(shrek);

    std::cout << ac;

    return 0;
}
