#include <iostream>

class Holder
{
    int value = 0;

public:
    Holder()
    {
        std::cin >> value;
    }

    ~Holder()
    {
        std::cout << value << std::endl;
    }

    void swap(Holder &other)
    {
        int tmp = value;
        value = other.value;
        other.value = tmp;
    }
};

int main()
{
    int count;
    std::cin >> count;

    Holder *ptr = new Holder[count];
    for (int i = 0; i < count / 2; ++i) {
        ptr[i].swap(ptr[count - 1 - i]);
    }

    delete [] ptr;

    return 0;
}
