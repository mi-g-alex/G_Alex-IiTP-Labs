#include <iostream>

long long F(long long a) {
    if(a % 10) return a % 10;
    if(a == 0) return 0;
    return F(a / 10);
}

int main() {
    long long p, q;
    std::cin >> p >> q;
    while(true) {
        long long sum = 0;
        for (long long i = p; i <= q; ++i) {
           sum += F(i);
        }
        std::cout << sum << "\n";
        std::cin >> p >> q;
        if(p < 0 && q < 0) return 0;
    }
}