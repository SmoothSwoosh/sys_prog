#include <iostream>
#include <vector>
#include <functional>

template <typename Iter, typename Action>
void myapply(Iter first, Iter last, Action action) {
    while (first != last) {
        action(*first); //making some stuff
        ++first;
    }
}

template <typename Pointer, typename Action>
void myapply(Pointer *first, Pointer *last, Action action) {
    for (size_t i = 0; i < static_cast<size_t>(last - first); ++i) {
        action(first[i]);
    }
}

template <typename Iter, typename Predicate>
auto myfilter2(Iter first, Iter last, Predicate foo) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<Iter>::value_type>> links;

    while (first != last) {
        if (foo(*first)) {
            //if the element satisfies the condition of foo
            //push it into the vector
            links.push_back(std::ref(*first));
        }
        ++first;
    }

    return links;
}

template <typename Pointer, typename Predicate>
auto myfilter2(Pointer *first, Pointer *last, Predicate foo) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<Pointer *>::value_type>> links;

    for (size_t i = 0; i < static_cast<size_t>(last - first); ++i) {
        if (foo(first[i])) {
            links.push_back(std::ref(first[i]));
        }
    }

    return links;
}

int main()
{
    std::vector<double> v1{-1, 0, 1, 2, 3, 4, 5};
    auto f = [](double &a) {
        a *= 5;
    };

    auto predicate = [](double &a) {
        return a > 0;
    };

    std::vector<std::reference_wrapper<double>> links;
    links = myfilter2(v1.begin(), v1.end(), predicate);

    myapply(links.begin(), links.end(), f);

    for (auto elem : v1) {
        std::cout << elem << std::endl;
    }

    std::cout << "SECOND TEST\n";

    double a[10] = { 0 };
    for (int i = 0; i < 10; ++i) {
        a[i] = i + 1;
    }

    std::vector<std::reference_wrapper<double>> links2;
    links2 = myfilter2(a, a + 10, predicate);

    myapply(links2.begin(), links2.end(), f);

    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}
