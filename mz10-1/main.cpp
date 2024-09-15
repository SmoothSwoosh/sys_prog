#include <iostream>

int main()
{
    std::string str;

    while (std::cin >> str) {
        int ans = 1;
        bool betta_prev = false;

        for (auto elem : str) {
            if (elem != '1' && elem != '2' && elem != '3' && elem != '4') {
                ans = 0;
                break;
            }

            if (elem == '1' || elem == '2') {
                betta_prev = true;
            }

            if (elem == '3' || elem == '4') {
                if (betta_prev) {
                    ans = 0;
                    break;
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
