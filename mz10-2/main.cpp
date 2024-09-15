#include <iostream>
#include <string>

int get_answer(bool valid, int prev_zeros, int prev_ones, int zeros, int ones) {
    int ans;
    if (!valid) {
        ans = 0;
    } else if (prev_zeros == -1 && (ones != 0 && zeros != 0)) {
        ans = 1;
    } else if (ones == 0 || zeros == 0) {
        ans = 0;
    } else {
        if (prev_ones == ones && prev_zeros == zeros) {
            ans = 1;
        } else {
            ans = 0;
        }
    }

    return ans;
}

int main()
{
    char character, last_character = '\n';
    int prev_zeros = -1, prev_ones = -1;
    int zeros = 0, ones = 0;
    bool valid = true;

    while (std::cin.get(character) && !std::cin.eof()) {
        if (std::isspace(character)) {
            if (!isspace(last_character)) {
                std::cout << get_answer(valid, prev_zeros, prev_ones, zeros, ones) << std::endl;
                ones = 0, zeros = 0, prev_ones = -1, prev_zeros = -1;
                valid = true;
            }
            last_character = character;
            continue;
        }

        if (character == '0') {
            if (ones > 0) {
                if (prev_zeros == -1) {
                    prev_zeros = zeros;
                    prev_ones = ones;
                } else {
                    if (ones != prev_ones || zeros != prev_zeros) {
                        valid = false;
                    }
                }
                zeros = 0, ones = 0;
            }
            ++zeros;
        } else if (character == '1') {
            ++ones;
        } else {
            valid = false;
        }

        last_character = character;
    }

    if (!std::isspace(last_character)) {
        std::cout << get_answer(valid, prev_zeros, prev_ones, zeros, ones) << std::endl;
    }

    return 0;
}
