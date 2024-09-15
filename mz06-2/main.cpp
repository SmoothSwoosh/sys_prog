#include <iostream>
#include <map>

int main()
{
    std::string name;
    double mark;
    std::map<std::string, std::pair<double, int> > dict;

    while (std::cin >> name) {
        std::cin >> mark;
        dict[name].first += mark;
        ++dict[name].second;
    }

    for (auto it = dict.begin(); it != dict.end(); ++it) {
        auto average = it->second;
        std::cout << it->first << ' ' << average.first / average.second << std::endl;
    }

    return 0;
}
