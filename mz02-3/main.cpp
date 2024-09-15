#include <iostream>

class C
{
public:
    int x;

    C(){}

    C(const C*){}

    C(double a): x(a) {}

    C(int a, int b) {
        x = a + b;
    }

    operator int () const {
        return x;
    }

    C &operator++() {
        ++x;
        return *this;
    }
};

int operator*(const C& v1, C *v2)
{
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        ans += v1.x * v2[i].x;
    }

    return ans;
}

C func1(const C &v1, int v2)
{
    return C(v2 + v1, ~v1);
}

void func2(const C *p1, double p2)
{
    C v1 = p2;
    C v2[2][2];
    C v3 = func1(func1(func1(&p1[3], p2), ~p1[2]), ++v1 * v2[1]);
}

int main()
{

    return 0;
}
