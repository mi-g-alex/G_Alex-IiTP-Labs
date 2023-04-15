// OK 4.2.6
#include <iostream>
#include <iomanip>

int NUM = 9;

int main() {

    double b1;
    std::cin >> b1;

    double q;
    q = 1.0 / (NUM + 1);

    double s = b1 / (1 - q);
    std::cout << std::setprecision(8) << s;
    return 0;
}

