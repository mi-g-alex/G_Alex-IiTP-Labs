#include <iostream>
#include <cmath>

long double abs_a(long double f) {
    return (f < 0 ? -f : f);
}

int main() {
    int i;
    long double fx, a, x, z, y, b;
    std::cout << "S elect fx:\n\n1) 2x\n2) x^3\n3) x / 3\n";
    std::cin >> i;
    std::cout << "Wait a, b, z input\n";
    std::cin >> a >> b >> z;

    if (z <= 0) x = z * z / 2;
    else x = std::sqrt(z);

    switch (i) {
        case 1:
            fx = 2 * x;
            break;
        case 2:
            fx = x * x * x;
            break;
        case 3:
            fx = x / 3;
            break;
        default:
            std::cout << "Input error";
            return 0;
    }

    y = b * fx / std::cos(x) + a * std::exp(abs_a(std::tan(x / 2)));

    std::cout << y;

    return 0;
}
