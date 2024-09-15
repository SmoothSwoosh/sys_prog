#include <iostream>

class A
{
    int number;
    bool invoked = false;

    public:
        A()
        {
            std::cin >> A::number;
        }

        A(const A &cl)
        {
            invoked = true;
            std::cin >> A::number;
            A::number = A::number + cl.number;
        }

        ~A()
        {
            if (invoked) {
                std::cout << A::number << std::endl;
            }
        }
};

int main()
{
    A a, b(a);

    return 0;
}
