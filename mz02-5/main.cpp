#include <iostream>

class BinaryNumber
{
    std::string bin_rep;
public:
    BinaryNumber(const std::string &s) {
        bin_rep = s;
    }
    operator std::string () const {
        return bin_rep;
    }
    const BinaryNumber &operator++() {
        int remainder = 1;
        for (int i = bin_rep.size() - 1; i >= 0; --i) {
            int digit = (bin_rep[i] - '0' + remainder);
            remainder = digit / 2;
            bin_rep[i] = (digit % 2) + '0';
        }

        if (remainder != 0) {
            bin_rep = '1' + bin_rep;
        }

        return *this;
    }
};

int main()
{
    BinaryNumber bn("1");
    for (int i = 0; i < 16; i++) {
        ++bn;
        std::string a = bn;
        std::cout << i + 1 << ' ' << a;
        std::cout << std::endl;
    }

    return 0;
}
