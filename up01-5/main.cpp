#include <iostream>

enum
{
    END_OF_LINE = 16,
    OCTETS_IN_NUM = 4,
    HEX_BIT = 16
};

unsigned int hex_to_decimal(std::string &hex)
{
    unsigned int container[2];
    for (int i = 0; i < 2; ++i) {
        container[i] = (hex[i] >= 'a' && hex[i] <= 'f') ? hex[i] - 'a' + 10 : hex[i] - '0';
    }
    return (container[0] * HEX_BIT + container[1]);
}

int main()
{
    std::string buf;
    unsigned int counter = 0, number = 0;
    while (std::cin >> buf) {
        if (counter != 0) {
            number = number * HEX_BIT * HEX_BIT + hex_to_decimal(buf);

            if (counter % OCTETS_IN_NUM == 0) {
                std::cout << number << std::endl;
                number = 0;
            }

            if (counter == END_OF_LINE) {
                counter = -1;
            }
        }
        ++counter;
    }

    return 0;
}
