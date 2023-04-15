// OK
#include <iostream>
#include <cmath>

long long t[10][10];

int main() {
    for (int i = 0; i < 10; i++) t[i][0] = i;

    for (int i = 0; i < 10; i++)
        for (int j = 1; j < 10; j++)
            t[i][j] = t[i][j - 1] * i;

    long long num;
    std::cin >> num;

    for (int res = 1; res < num; res++) {

        long long a = res;
        long long lng = log10l(a) + 1;
        long long sum = 0;
        while (a > 0) {
            sum += t[a % 10][lng - 1];
            a /= 10;
        }
        if (res == sum) std::cout << res << "\n";
    }
}
