#include <iostream>
#include <map>

enum
{
    MODULO = 4294967161
};

int main()
{
    unsigned long long R, C, V;

    std::map<unsigned long long, std::map<unsigned long long, unsigned long long> > matrix;

    //reading first matrix
    while (std::cin >> R) {
        std::cin >> C >> V;
        if (V == MODULO) {
            break;
        }
        matrix[R][C] += V;
        matrix[R][C] %= MODULO;
    }

    //reading second matrix
    while (std::cin >> R) {
        std::cin >> C >> V;
        matrix[R][C] += V;
        matrix[R][C] %= MODULO;
    }

    for (auto row_it = matrix.begin(); row_it != matrix.end(); ++row_it) {
        for (auto col_it = row_it->second.begin(); col_it != row_it->second.end(); ++col_it) {
            if (col_it->second != 0) {
                std::cout << row_it->first << ' ' << col_it->first << ' ' << col_it->second << std::endl;
            }
        }
    }

    return 0;
}
