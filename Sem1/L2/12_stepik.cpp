// OK 4.3.7
#include <iostream>

int main() {
    long double a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) std::cout << "Incorrect input";
    else {
        if ((a <= x && b <= y)
            || (a <= y && b <= x)
            || (b <= x && c <= y)
            || (b <= y && c <= x)
            || (a <= x && c <= y)
            || (c <= x && a <= y)) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
    }
}
