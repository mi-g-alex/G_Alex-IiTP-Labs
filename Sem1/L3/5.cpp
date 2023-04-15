#include <iostream>
#include <cmath>
#include <iomanip>

long double S(long double x) {
    long long N = 100000;
    long double sum = 1;
    long double t = 1;
    for (long long i = 1; i <= N; i++) {
        t *= (x / 2);
        t /= i;
        t /= ((i - 1) * (i - 1) + 1);
        t *= (i * i + 1);
        sum += t;
    }
    return sum;
}

long double Y(long double x) {
    long double t = x * x / 4 + x / 2 + 1;
    long double e = M_E;
    e = std::pow(e, (x / 2));
    t *= e;
    return t;

}

int main() {
    long double x;
    std::cout << "x = {0.1..1}\n";
    std::cin >> x;

    if (x < 0.1 || x > 10) {
        std::cout << "WTF U DOING.";
        return 0;
    }

    std::cout << std::setprecision(15);
    std::cout << S(x) << "\n" << Y(x) << "\n";
}
