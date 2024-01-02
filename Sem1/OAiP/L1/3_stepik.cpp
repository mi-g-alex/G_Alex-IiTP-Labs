// OK 4.1.11
#include <iostream>
#include <iomanip>

int main() {

    long double s, a, v0, t1, t;

    std::cin >> a >> t >> v0;

    if (a != 0) t1 = v0 / a; // время торможения

    s = v0 * t + a * t * t / 2; // путь по дефолту

    if (a != 0 && t1 < 0 && -t1 < t) {
        s = v0 * -t1 + a * t1 * t1 / 2 - a * (t + t1) * (t + t1) / 2;
    }

    if (s < 0) s *= -1;

    std::cout << std::setprecision(20) << s;

    return 0;
}

