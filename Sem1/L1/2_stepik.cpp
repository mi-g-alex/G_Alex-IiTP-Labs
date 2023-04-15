// OK 4.1.10
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double h;
    std::cin >> h;

    double t = sqrt(2 * h / 9.8);

    std::cout << std::setprecision(9) << t;
    return 0;
}