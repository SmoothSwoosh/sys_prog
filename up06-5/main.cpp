#include <iostream>
#include <map>

enum
{
    MODULO = 4294967161
};

int main()
{
    unsigned long long R, C, V;
    std::map<unsigned int, std::map<unsigned int, unsigned long long> > first_matrix, second_matrix, ans;

    //reading first matrix
    while (std::cin >> R) {
        std::cin >> C >> V;
        if (V == MODULO) {
            break;
        }
        first_matrix[R][C] = V;
    }

    //reading second matrix
    while (std::cin >> R) {
        std::cin >> C >> V;
        second_matrix[R][C] = V;
    }

    //ans[p][k] += first[p][i] * second[i][k]
    for (auto first_it = first_matrix.begin(); first_it != first_matrix.end(); ++first_it) {
        auto inner_map = first_it->second; //inner map of first matrix
        for (auto second_it = inner_map.begin(); second_it != inner_map.end(); ++second_it) {
            auto internal_map = second_matrix[second_it->first]; //internal map of second matrix
            for (auto third_it = internal_map.begin(); third_it != internal_map.end(); ++third_it) {
                unsigned long long first_operand = second_it->second; //first[p][i]
                unsigned long long second_operand = third_it->second; //second[i][k]
                ans[first_it->first][third_it->first] += (first_operand * second_operand) % MODULO;
                ans[first_it->first][third_it->first] %= MODULO;
            }
        }
    }

    //printing answer
    for (auto column = ans.begin(); column != ans.end(); ++column) {
        auto row_tracker = column->second;
        for (auto row = row_tracker.begin(); row != row_tracker.end(); ++row) {
            if (row->second != 0) {
                std::cout << column->first << ' ' << row->first << ' ' << row->second << std::endl;
            }
        }
    }

    return 0;
}
