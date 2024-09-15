#include <iostream>
#include <list>

//deleting element at index-position
void delete_number(std::list<unsigned int> &lst, size_t index)
{
    if (index > lst.size()) {
        return;
    }
    std::list<unsigned int>::iterator it = lst.begin();
    advance(it, index - 1);
    lst.erase(it);
}

//inserting element(value) before index-position
void insert_number(std::list<unsigned int> &lst, size_t index, unsigned int value)
{
    std::list<unsigned int>::iterator it = lst.begin();
    advance(it, index - 1);
    if (index > lst.size()) {
        it = lst.end();
    }
    lst.insert(it, value);
}

int main()
{
    int number;
    unsigned int value;
    std::list<unsigned int> lst;

    while ((std::cin >> value) && (value != 0)) {
        lst.push_back(value);
    }

    while (std::cin >> number) {
        if (number < 0) {
            delete_number(lst, -number);
        } else {
            std::cin >> value;
            insert_number(lst, number, value);
        }
    }

    for (auto elem : lst) {
        std::cout << elem << std::endl;
    }

    return 0;
}
