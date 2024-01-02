#include <iostream>
#include <string>
#include "../checkInput/checkInput.h"

long long binPow(unsigned long long n, unsigned long long m, bool q) {
    long long k = 26;
    long long ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * k) % m;
        }
        n >>= 1;
        k = (k * k) % m;
    }
    if (!q)
        return (ans * 2) % m;
    else return ans % m;
}

bool check(std::string s1, std::string s2, unsigned long long n) {
    for (unsigned long long i = 0; i < n; ++i) {
        if (s1[s1.size() - n + i] != s2[i]) return false;
    }

    return true;
}

long long toDoTask5(long long n, long long m, std::string s1, std::string s2) {
    auto tmp = (long long) (n - s1.size() - s2.size());
    if (tmp > 0) {
        return binPow(tmp, m, s1 == s2);
    } else if (tmp == 0) return 1;
    else {
        tmp = -tmp;
        return (check(s1, s2, tmp) || check(s2, s1, tmp) ? 1 : 0);
    }
}
