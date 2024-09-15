#include <iostream>
#include <cstdlib>

struct Item
{
    Item *next;
    long long value;
};

class Arena
{
    Item *ptr{};
    bool *states{};
    size_t capacity = 0;
public:
    explicit Arena(size_t size)
    {
        ptr = new Item [size / sizeof(Item)];
        states = new bool [size / sizeof(Item)];
        capacity = size / sizeof(Item);
        for (size_t i = 0; i < capacity; ++i) {
            states[i] = false;
        }
    }

    Arena(const Arena &other) = delete;

    Arena &operator=(const Arena &other) = delete;

    Item *get()
    {
        for (size_t i = 0; i < capacity; ++i) {
            if (states[i] == false) {
                states[i] = true;
                return &ptr[i];
            }
        }
        return nullptr;
    }

    void put(Item *elem)
    {
        states[elem - ptr] = false;
    }

    ~Arena()
    {
        delete [] ptr;
        delete [] states;
    }
};

int main()
{
    Arena shrek(5);

    return 0;
}
