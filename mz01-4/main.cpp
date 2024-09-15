#include <iostream>
#include <iomanip>
#include <cmath>

enum
{
    ACCURACY = 10
};

int main()
{
    double sum_square = 0., sum = 0., number;
    long long cnt = 0;

    while (std::cin >> number) {
        sum += number;
        sum_square += number * number;
        cnt++;
    }

    std::cout << std::setprecision(ACCURACY) << sum / cnt << std::endl;
    std::cout << std::setprecision(ACCURACY) << std::sqrt(sum_square / cnt - (sum / cnt) * (sum / cnt)) << std::endl;

    return 0;
}
