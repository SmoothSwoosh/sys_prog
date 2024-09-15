#include <iostream>

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    char c, last_c = 'a';
    bool part_of_number = false;

    while (std::cin.get(c) && !std::cin.eof()) {
        if (part_of_number) {
            if (!is_digit(c)) {
                part_of_number = false;
            }
            std::cout << c;
        } else {
            if (is_digit(c)) {
                if (c != '0') {
                    part_of_number = true;
                    std::cout << c;
                }
            } else {
                if (last_c == '0') {
                    std::cout << '0';
                }
                std::cout << c;
            }
        }
        last_c = c;
    }

    if (last_c == '0' && !part_of_number) {
        std::cout << '0';
    }

    return 0;
}
