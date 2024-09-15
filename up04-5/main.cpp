#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

const std::string SPACES = " \n\r\f\t\v";

int main()
{
    std::string str;
    std::getline(std::cin, str);

    //remove trailing spaces
    str = str.substr(0, str.find_last_not_of(SPACES) + 1);

    std::vector <int> suffix_array(str.size());

    for (size_t i = 0; i < suffix_array.size(); ++i) {
        suffix_array[i] = i;
    }

    auto cmp = [str](const int &a, const int &b) {
        return strcmp(&str[a], &str[b]) < 0;
    };

    sort(suffix_array.begin(), suffix_array.end(), cmp);

    for (auto number: suffix_array) {
        std::cout << number << std::endl;
    }

    return 0;
}
