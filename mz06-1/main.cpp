#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    unsigned int number;
    std::vector<unsigned int> seq;

    while (std::cin >> number) {
        seq.push_back(number);
    }

    auto cmp = [](unsigned int a, unsigned int b) {
        return __builtin_popcount(a) < __builtin_popcount(b);
    };

    stable_sort(seq.begin(), seq.end(), cmp);

    for (auto elem : seq) {
        std::cout << elem << std::endl;
    }

    return 0;
}
