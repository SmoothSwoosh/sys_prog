#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <functional>

namespace numbers
{
    class complex;
    complex operator*(const complex &a, const complex &b);
    complex operator/(const complex &a, const complex &b);

    class complex
    {
        double x, y;
    public:
        complex(double x = 0.0, double y = 0.0): x(x), y(y) {}

        complex(const complex &other)
        {
            x = other.x;
            y = other.y;
        }

        explicit complex(std::string str)
        {
            sscanf(str.c_str(), "(%lf,%lf", &x, &y);
        }

        double re() const
        {
            return x;
        }

        double im() const
        {
            return y;
        }

        double abs2() const
        {
            return x * x + y * y;
        }

        double abs() const
        {
            return sqrt(x * x + y * y);
        }

        std::string to_string() const
        {
            size_t sz = 4096;
            char buffer[sz];
            snprintf(buffer, sz, "(%.10g,%.10g)", x, y);
            return buffer;
        }

        complex operator-() const
        {
            return complex(-x, -y);
        }

        complex operator~() const
        {
            return complex(x, -y);
        }

        const complex &operator+=(const complex &other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        const complex &operator-=(const complex &other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        const complex &operator*=(const complex &other)
        {
            complex tmp = *this * other;
            *this = tmp;
            return *this;
        }

        const complex &operator/=(const complex &other)
        {
            complex tmp = *this / other;
            *this = tmp;
            return *this;
        }
    };

    class complex_stack
    {
        complex *ptr{};
        size_t sz = 0;
    public:
        complex_stack() = default;

        complex_stack(const complex_stack &other)
        {
            ptr = new complex [other.size()];
            sz = other.size();
            for (size_t i = 0; i < other.size(); ++i) {
                *(ptr + i) = other[i];
            }
        }

        complex_stack(complex *ptr, size_t sz)
        {
            this->ptr = ptr;
            this->sz = sz;
        }

        ~complex_stack()
        {
            if (ptr != nullptr) {
                delete [] ptr;
            }
        }

        size_t size() const
        {
            return sz;
        }

        const complex &operator[](int index) const
        {
            return ptr[index];
        }

        complex operator+() const
        {
            return ptr[sz - 1];
        }

        complex *address() const
        {
            return ptr;
        }

        complex_stack &operator=(const complex_stack &other)
        {
            if (this == &other) {
                return *this;
            }

            if (ptr != nullptr) {
                delete [] ptr;
            }

            ptr = new complex [other.size()];
            sz = other.size();
            for (size_t i = 0; i < other.size(); ++i) {
                *(ptr + i) = other[i];
            }

            return *this;
        }

        complex_stack operator~() const
        {
            complex_stack new_stack(new complex [sz - 1], sz - 1);

            complex *addr = new_stack.address();
            for (size_t i = 0; i < sz - 1; ++i) {
                *(addr + i) = ptr[i];
            }

            return new_stack;
        }
    };

    complex_stack operator<<(const complex_stack &other, const complex &number)
    {
        complex_stack new_stack(new complex [other.size() + 1], other.size() + 1);

        size_t i = 0;
        complex *addr = new_stack.address();
        for (; i < other.size(); ++i) {
            *(addr + i) = other[i];
        }
        *(addr + i) = number;

        return new_stack;
    }

    complex operator+(const complex &a, const complex &b)
    {
        return complex(a.re() + b.re(), a.im() + b.im());
    }

    complex operator-(const complex &a, const complex &b)
    {
        return complex(a.re() - b.re(), a.im() - b.im());
    }

    complex operator*(const complex &a, const complex &b)
    {
        double re_a = a.re();
        double re_b = b.re();
        double im_a = a.im();
        double im_b = b.im();

        return complex(re_a * re_b - im_a * im_b, re_a * im_b + re_b * im_a);
    }

    complex operator/(const complex &a, const complex &b)
    {
        complex tmp = a * ~b;
        return complex(tmp.re() / b.abs2(), tmp.im() / b.abs2());
    }

    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        std::map<std::string, std::function<void(complex_stack &)>> dict;
        complex_stack st;

        dict["z"] = [z](complex_stack &st) {
            st = st << z;
        };

        dict["+"] = [z](complex_stack &st) {
            complex b = +st;
            st = ~st;
            complex a = +st;
            st = ~st;
            st = st << (a + b);
        };

        dict["-"] = [z](complex_stack &st) {
            complex b = +st;
            st = ~st;
            complex a = +st;
            st = ~st;
            st = st << (a - b);
        };

        dict["*"] = [z](complex_stack &st) {
            complex b = +st;
            st = ~st;
            complex a = +st;
            st = ~st;
            st = st << (a * b);
        };

        dict["/"] = [z](complex_stack &st) {
            complex b = +st;
            st = ~st;
            complex a = +st;
            st = ~st;
            st = st << (a / b);
        };

        dict["!"] = [z](complex_stack &st) {
            st = st << (+st);
        };

        dict[";"] = [z](complex_stack &st) {
            st = ~st;
        };

        dict["~"] = [z](complex_stack &st) {
            complex top = +st;
            st = ~st;
            st = st << (~top);
        };

        dict["#"] = [z](complex_stack &st) {
            complex top = +st;
            st = ~st;
            st = st << (-top);
        };

        for (auto command : args) {
            if (command[0] == '(') {
                st = st << (complex(command));
            } else {
                dict[command](st);
            }
        }

        return +st;
    }
}

numbers::complex calculate_line_integral
(const numbers::complex &c, double r, int n, const std::vector<std::string> &args)
{
    double h = 2 * M_PI / n;
    numbers::complex integral;

    for (int i = 0; i < n; ++i) {
        double t = (2 * i * h + h) / 2;
        numbers::complex point(r * cos(t), r * sin(t));
        numbers::complex derivative(-r * sin(t), r * cos(t));
        integral += eval(args, point + c) * h * derivative;
    }

    return integral;
}

int main(int argc, char *argv[])
{
    numbers::complex c(argv[1]);
    double r = strtod(argv[2], NULL);
    int n = strtol(argv[3], NULL, 10);

    std::vector<std::string> args;
    for (int i = 4; i < argc; ++i) {
        args.push_back(std::string(argv[i]));
    }

    numbers::complex answer = calculate_line_integral(c, r, n, args);
    std::cout << answer.to_string() << std::endl;

    return 0;
}
