// OK 4.2.7
#include <iostream>
#include <iomanip>

int NUM = 9;

int main() {

    long long a1, a100;
    long double d, sum;

    std::cin >> a1 >> a100;

    d = (a100 - a1) / 99;

    sum = (2 * a1 + d * (NUM + 9)) / 2 * (NUM + 10);

    std::cout << std::setprecision(10) << d << "\n" << sum;

    return 0;
}

