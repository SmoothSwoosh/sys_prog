#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>

template <typename Index, typename Element>
Element myremove(Index first_index, Index last_index, Element first_element, Element last_element) {
    //creating a vector-copy of indices from range [first_index, last_index)
    std::vector<typename std::iterator_traits<Index>::value_type> cp;
    cp.assign(first_index, last_index);

    //sorting it
    sort(cp.begin(), cp.end());

    //taking only unique values and getting rid of others
    auto last = std::unique(cp.begin(), cp.end());
    cp.erase(last, cp.end());

    //making a set to keep all unique indices
    std::set<typename std::iterator_traits<Index>::value_type> st;
    for (auto elem : cp) {
        st.insert(elem);
    }

    //swapping deleting elements to the back of the range
    size_t offset = 0;
    for (size_t i = 0; i < static_cast<size_t>(last_element - first_element); ++i) {
        if (st.find(i) == st.end()) {
            std::iter_swap(first_element + offset, first_element + i);
            ++offset;
        }
    }

    return first_element + offset;
}

int main()
{
    std::vector<int> indexes{0, 2, 6, 80};
    std::vector<double> dels{1, 2, 3, 4, 5, 6, 7};
    auto shrek = myremove(indexes.begin(), indexes.end(), dels.begin(), dels.end());
    for (int i = 0; i < 3; ++i) {
        std::cout << *shrek << std::endl;
        ++shrek;
    }

    return 0;
}
