// OK 4.3.6
#include <iostream>
#include <iomanip>

int main() {
    long double a, b, c, d, ans;
    std::cin >> a >> b >> c >> d;
    if (c != 0) {
        if (c >= d && a < d) {
            ans = a + b / c;
        } else if (c < d && a >= d) {
            ans = a - b / c;
        } else ans = 0;
    } else {
        std::cout << "ERROR";
        return 0;
    }

    std::cout << std::setprecision(20) << ans;

    return 0;
}
