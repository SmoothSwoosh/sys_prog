#include <iostream>
#include <string>
#include <stack>

bool is_sign(char character) {
    return character == '+' || character == '-'
            || character == '*' || character == '/';
}

int main() {
    std::stack<std::string> st;

    char character;
    while (std::cin.get(character) && !std::cin.eof()) {
        if (std::isspace(character)) {
            continue;
        }
        if (!is_sign(character)) {
            st.push(std::string(1, character));
        } else {
            std::string b = st.top();
            st.pop();
            std::string a = st.top();
            st.pop();

            char buf[4096];
            sprintf(buf, "(%s%c%s)", a.c_str(), character, b.c_str());

            st.push(std::string(buf));
        }
    }

    std::cout << st.top() << std::endl;

    return 0;
}
