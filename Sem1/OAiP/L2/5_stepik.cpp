// OK 4.3.5
#include <iostream>
#include <iomanip>


long double abs_a(long double f) {
    return (f < 0 ? -f : f);
}

//итерационная формула герона
long double sqrt_a(long double num)   {

    long double x = 1;

    while(abs_a(x * x - num) >= 1E-16) {
        x = ((num / x) + x) / 2;
    }

    return x;
}

int main() {

    long double k, x, y, r1, r2, r3, r4, ans;
    std::cin >> k >> x >> y;
    if (k < 0) {
        x *= -1;
        y *= -1;
        k *= -1;
    }
    if ((x > k || x < 0) && ((y <= k) && (y >= 0))) {
        r1 = abs_a(x);
        r2 = abs_a(k - x);
        ans = (r1 > r2 ? r2 : r1);
    }

    if ((x <= k && x >= 0) && ((y > k) || (y < 0))) {
        r1 = abs_a(y);
        r2 = abs_a(k - y);
        ans = (r1 > r2 ? r2 : r1);
    }

    if ((x <= k && x >= 0) && ((y <= k) && (y >= 0))) {
        r1 = abs_a(y);
        r2 = abs_a(k - y);
        r3 = abs_a(x);
        r4 = abs_a(k - x);
        ans = (r1 > r2 ? r2 : r1);
        ans = (ans > r3 ? r3 : ans);
        ans = (ans > r4 ? r4 : ans);
    }

    if ((x > k || x < 0) && ((y > k) || (y < 0))) {
        r1 = sqrt_a(x * x + y * y);
        r2 = sqrt_a(x * x + (k - y) * (k - y));
        r3 = sqrt_a((k - x) * (k - x) + (k - y) * (k - y));
        r4 = sqrt_a((k - x) * (k - x) + y * y);
        ans = (r1 > r2 ? r2 : r1);
        ans = (ans > r3 ? r3 : ans);
        ans = (ans > r4 ? r4 : ans);
    }
    if(ans == 0) std::cout << 0;
    else std::cout << std::setprecision(22) << ans;
}