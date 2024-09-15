#include <iostream>

class C
{
public:
    C(){}
    static const char c;
    static void f(){}
};

const char C::c = '+';
int main()
{
    C ob;
    C::f();

    return 0;
}
