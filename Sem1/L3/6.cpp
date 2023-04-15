#include <iostream>
#include <cmath>

int main() {
    long double d = INFINITY, ans = 0, steps;

    std::cin >> steps;

    if(steps < 1 || steps - (long long)(steps) != 0)

    for (long double i = 0; i <= 2; i += 2.0 / steps) {
        long double t = log10(cosh(i)) - tanh(i) + 0.5;
        if (std::abs(t) < std::abs(d)) {
            d = t;
            ans = i;
        }
    }

    std::cout << ans << " " << d;
    return 0;
}
