#include <iostream>
#include <cmath>

int main() {
    long double R, P, Q;

    std::cout << "R, P, Q (RAD)\n";
    std::cin >> R >> P >> Q;
    std::cout << (P * std::sin(Q) >= 2.0 * R ? "YES" : "NO");
    return 0;
}
