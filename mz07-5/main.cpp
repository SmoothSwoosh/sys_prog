#include <iostream>
#include <vector>

template <typename Iter, typename Comparator>
void selection_sort(Iter first, Iter last, Comparator foo) {
    for (; first != last; ++first) {
        auto min_iter = first;
        auto it = first;
        ++it;

        for (; it != last; ++it) {
            if (foo(*it, *min_iter)) {
                min_iter = it;
            }
        }

        if (min_iter != first) {
            std::iter_swap(min_iter, first);
        }
    }
}

template <typename Iter>
void selection_sort(Iter first, Iter last) {
    selection_sort(first, last, std::less<typename std::iterator_traits<Iter>::value_type>());
}

int main() {

    std::vector<int> vec{1, 3, 2, 6, -1, -4, 5};
    auto shrek = [](int a, int b) {
        return a > b;
    };
    selection_sort(vec.begin(), vec.end(), shrek);
    for (auto elem : vec) {
        std::cout << elem << std::endl;
    }

    return 0;
}
