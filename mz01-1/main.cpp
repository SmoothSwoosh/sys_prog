#include <iostream>

class Sum
{
    int a, b;

    public:
        explicit Sum(int a, int b)
        {
            Sum::a = a;
            Sum::b = b;
        }

        explicit Sum(Sum a, int b)
        {
            Sum::a = a.get();
            Sum::b = b;
        }

        int get() const
        {
            return a + b;
        }
};

int main()
{
    std::cout << Sum(Sum(Sum(1, 2), 3), 78).get() << std::endl;

    return 0;
}
