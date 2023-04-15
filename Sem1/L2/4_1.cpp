#include <iostream>

int main() {
    long double x, y;
    std::cout << "x, y\n";
    std::cin >> x >> y;
    std::cout << (x > y ? x : y);
    return 0;
}
