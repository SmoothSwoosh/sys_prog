#include <iostream>

class C
{
    int x = 0;
public:
    C() = default;

    C(int x) {
        this->x = 2 * x;
    }

    int get() const
    {
        return x;
    }
};

C operator+(const C &v1, const C &v2)
{
    int tmp = v1.get() + v2.get();
    return C{tmp};
}

int main()
{
    C c1(7), c2 = 5, c3(c1 + c2);
    std::cout << c1.get() << ' ' << c2.get() << ' ' << c3.get() << std::endl;

    return 0;
}
