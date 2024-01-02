#include <iostream>

int main() {
    long double x, y;
    bool isXMax;
    std::cout << "x, y";
    std::cin >> x >> y;
    isXMax = (x > y);
    std::cout << (isXMax ? x : y);
    return 0;
}
