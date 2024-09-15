#include <iostream>

enum
{
    BOUND = 4
};

void output_format(char c, unsigned long long cnt)
{
    std::cout << std::hex << '#' << c << cnt << '#';
}

void output_same(char c, unsigned long long cnt)
{
    for (unsigned i = 0; i < cnt; ++i) {
        std::cout << c;
    }
}

int main()
{
    char c, last_c;
    unsigned long long cnt = 0;
    while (std::cin.get(c) && !std::cin.eof()) {
        if (cnt == 0 || last_c == c) {
            ++cnt;
        } else {
            if (cnt > BOUND || last_c == '#') {
                output_format(last_c, cnt);
            } else {
                output_same(last_c, cnt);
            }
            cnt = 1;
        }
        last_c = c;
    }

    if (cnt != 0) {
        if (cnt > BOUND || last_c == '#') {
            output_format(last_c, cnt);
        } else {
            output_same(last_c, cnt);
        }
    }

    return 0;
}
