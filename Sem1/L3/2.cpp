#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setprecision(10);

    long double d = 0.5 + 1.0 / 3.0, sum = 0;
    long double temp2 = 2, temp3 = 3;

    do {
        sum += d;
        temp2 *= 2;
        temp3 *= 3;
        d = 1.0 / temp2 + 1.0 / temp3;
    } while (d >= 1e-3);

    std::cout << sum;

    return 0;
}
