#include <iostream>
#include <vector>

template <typename Container, typename UnaryPredicate>
Container myfilter(const Container &obj, UnaryPredicate foo) {
    Container cp;

    for (auto it = obj.begin(); it != obj.end(); ++it) {
        if (foo(*it)) {
            cp.insert(cp.end(), *it);
        }
    }

    return cp;
}

int main() {
    std::vector<int> shrek{1, 2, 30, 45, 23, 4, 7, 5};
    auto foo = [](int t) {
        return t < 5;
    };

    std::vector<int> ans = myfilter(shrek, foo);
    for (auto elem : ans) {
        std::cout << elem << std::endl;
    }

    return 0;
}
