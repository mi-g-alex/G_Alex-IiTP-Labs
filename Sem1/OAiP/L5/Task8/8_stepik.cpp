#include <iostream>

long long sumOfOdd(long long n) {
    return (n + 1) * (n + 1) / 4;
}

int main() {
    long long k;
    std::cin >> k;
    while (k--) {
        long long n;
        std::cin >> n;

        long long sum = 0;
        while (n > 0) {
            if(n % 2 == 0) sum += sumOfOdd(n - 1);
            else sum += sumOfOdd(n);
            n /= 2;
        }
        std::cout << sum << "\n";
    }
}