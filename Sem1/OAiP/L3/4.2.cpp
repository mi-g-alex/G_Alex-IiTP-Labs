#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    long long sum = 0;
    if(n >= 2)
        sum = (2 + (n - n % 2)) / 2 * (n / 2);

    std::cout << sum;
    return 0;
}
