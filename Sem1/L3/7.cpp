#include <iostream>
#include <iomanip>
#include <cmath>

long double PI = 3.14159;
long double PI2 = 6.2832;
long double E = 2.71828182845904;

long double MyAbs(long double f) {
    return (f < 0 ? -f : f);
}

long double MyPow10(long long x) {
    long double ans = 1;
    for (long long i = 1; i <= x; i++) {
        ans *= 10;
    }
    return ans;
}

long long MyLog10(long double x) {
    long long ans = 0;
    while (x >= 10) {
        x /= 10;
        ans++;
    }
    return ans;
}

long double MySin(long double x) {
    if (x > 2 * PI) {
        while (x > 2 * PI) {
            long double pi = PI;
            while (x > 2 * pi) {
                pi *= 10;
            }
            pi /= 10;
            x -= 2 * pi;
        }
    }

    x = x - (long long) (x / (2 * PI)) * 2 * PI;
    x = x - (long long) (x / (2 * PI)) * 2 * PI;
    long double sum = 0, q = x;
    long long N = 100000, i;

    for (i = 1; i <= N; i += 2) {
        sum += q;
        q = -1 * q * x * x / (i + 1) / (i + 2);
    }

    return sum;
}

long double MyCos(long double x) {
    if (x > 2 * PI) {
        while (x > 2 * PI) {
            long double pi = PI;
            while (x > 2 * pi) {
                pi *= 10;
            }
            pi /= 10;
            x -= 2 * pi;
        }
    }

    bool was = false;
    if ((x < 0 ? -x : x) < 1e-9 && (x < 0 ? -x : x) > 1e-30) {
        x += (x < 0 ? -PI2 / 2 : PI2 / 2);
        was = true;
    }

    x = x - (long long) (x / (2 * PI)) * (2 * PI);
    if (x > PI) x = -x;

    long double sum = 0, q = 1;
    long long N = 10000, i;
    for (i = 0; i <= N; i += 2) {
        sum += q;
        q = -1 * q * x * x / (i + 1) / (i + 2);
    }

    // if(x < 1e9) sum = 1 - x;
    if (was) sum *= -1;
    return sum;
}

long double MyLn(long double x) {
    if (x == 1) return 0;

    long long a = 0;
    long double e = E;

    while (x >= 1) {
        x /= e;
        a++;
    }

    while (x < 0.00001) {
        a--;
        x *= e;
    }

    long double sum = 0, q = x - 1;
    long long N = 1e6, i;
    for (i = 1; i <= N; i++) {
        sum += (q / i);
        q = -1 * q * (x - 1);
    }

    return a + sum;
}

int main() {
    long double x;
    std::cin >> x;

    if (MyAbs(x) > 1e13 || MyAbs(x) < 1e-6) {
        std::cout << "Number is so BIG or little. Pls send |x| = {1e-5..1e13}\nBut I can send wrong answer:\n";
    }

    std::cout << std::setprecision(15);
    long double c = MyLn(MyAbs(x));
    long double a = MySin(x), b = MyCos(x);
    std::cout << a << "\n" << b << "\n" << c << "\n";

    std::cout << std::min(a, std::min(b, c));

}