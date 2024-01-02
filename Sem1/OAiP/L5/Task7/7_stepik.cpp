#include <iostream>

int main() {
    unsigned long long k, n, t;
    std::cin >> k >> n >> t;
    unsigned long long j = 1;

    while(j) {
        unsigned long long tmp = 1;
        for (unsigned long long i = 1; i <= t; ++i) {
            tmp *= 10;
        }
        t = tmp;

        n %= t;
        k %= t;
        unsigned long long ak = k;
        unsigned long long ans = 1;

        while(n) {
            if(n & 1) {
                ans = (ans * ak) % t;
            }
            n >>= 1;
            ak = (ak * ak) % t;
        }
        std::cout << "\nCase #" << j << ": " << ans;
        std::cin >> k >> n >> t;
        if (n == k && k == t && t == 0) return 0;
        j++;
    }
}