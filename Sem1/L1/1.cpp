#include <iostream>

int main() {

    long double x, a, b, c;
    std::cin >> x;

    a = 23 * x * x; // 23x^2                                                                // 2
    b = x * (a + 32); // x * (23x^2 + 32) = 23x^3 + 32x                                     // 2
    c = 3 * a + 8; // 3 * 23x^2 + 8 = 69x^2 + 8;                                            // 2

    std::cout << b + c << "\n"; // 23x^3 + 32x + 69x^2 + 8 =  23x^3 + 69x^2 + 32x + 8       // 1
    std::cout << c - b << "\n"; // 69x^2 + 8 - 23x^3 - 32x = -23x^3 + 69x^2 - 32x + 8       // 1
                                                                                            //=8
    return 0;
}

