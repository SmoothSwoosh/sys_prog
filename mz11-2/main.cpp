#include <iostream>
#include <vector>
#include <set>
#include <string>

int main() {
    std::vector<std::string> rules;
    std::string rule;

    std::set<char> st;
    st.insert('S');
    while (getline(std::cin, rule)) {
        rules.push_back(rule);
    }

    int cnt = 1;
    while (cnt > 0) {
        cnt = 0;
        for (auto rule : rules) {
            if (st.find(rule[0]) != st.end()) {
                for (size_t i = 2; i < rule.size(); ++i) {
                    if (st.find(rule[i]) == st.end()) {
                        ++cnt;
                        st.insert(rule[i]);
                    }
                }
            }
        }
    }

    for (auto rule : rules) {
        bool flag = true;
        for (size_t i = 0; i < rule.size(); ++i) {
            if (rule[i] != ' ') {
                if (st.find(rule[i]) == st.end()) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            std::cout << rule << std::endl;
        }
    }

    return 0;
}
