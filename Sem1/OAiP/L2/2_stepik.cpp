// OK 4.3.3
#include <iostream>

int main() {
    long double x, y, z;

    std::cin >> x >> y >> z;

    std::cout << ((x + y > z && x + z > y && y + z > x) ? "YES" : "NO");

    return 0;
}