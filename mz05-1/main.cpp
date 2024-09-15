#include <iostream>
#include <algorithm>
#include <vector>

void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> cp = v1;

    std::sort(cp.begin(), cp.end());
    auto last = std::unique(cp.begin(), cp.end());
    cp.erase(last, cp.end());

    int removed_cnt = 0;
    for (auto elem : cp) {
        if ((elem - removed_cnt >= 0) && (elem - removed_cnt < static_cast<int>(v2.size()))) {
            v2.erase(v2.begin() + elem - removed_cnt);
            ++removed_cnt;
        }
    }
}

int main()
{
    std::vector<int> v1{0, 21, 0, 1, 3, 20};
    std::vector<int> v2{1, 2, 3, 4, 5};
    process(v1, v2);

    for (auto x : v2) std::cout << x << std::endl;

    return 0;
}
