#include <iostream>
#include <cmath>

int dist(int x1, int y1, int x2, int y2, int n, int m)
{
    int r_x1 = abs(x1 - x2);
    if (x1 > x2) {
        std::swap(x1, x2);
    }
    int r_x2 = abs(x1 + n - x2) % n;
    int r_x = std::min(r_x1, r_x2);

    int r_y1 = abs(y1 - y2);
    if (y1 > y2) {
        std::swap(y1, y2);
    }
    int r_y2 = abs(y1 + m - y2) % m;
    int r_y = std::min(r_y1, r_y2);

    return r_x + r_y;
}

int main()
{
    int m, n, x1, x2, y1, y2;
    std::cin >> m >> n;
    std::swap(m, n);

    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        ++x1, ++y1, ++x2, ++y2;
        std::cout << dist(x1, y1, x2, y2, n, m) << std::endl;
    }

    return 0;
}
