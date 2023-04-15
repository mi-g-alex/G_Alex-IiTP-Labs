#include <iostream>
#include <string>
#include "../checkInput/checkInput.h"

unsigned long long binPow(unsigned long long n, unsigned long long m, bool q) {
    unsigned long long k = 26;
    unsigned long long ans = 1;
    while(n) {
        if(n & 1) {
            ans = (ans * k) % m;
        }
        n >>= 1;
        k = (k * k) % m;
    }
    if(!q)
        return (ans * 2) % m;
    else return ans % m;
}

bool check(std::string s1, std::string s2, unsigned long long n) {
    for (unsigned long long  i = 0; i < n; ++i) {
        if(s1[s1.size() - n + i] != s2[i]) return false;
    }

    return true;
}

void toDoTask5() {
    long long k;
    k = checkInput(k);

    while(k--) {
        long long n, m;
        n = checkInput(n);
        m = checkInput(m);

        std::string s1, s2;
        std::cin >> s1 >> s2;

        auto tmp = (long long)(n - s1.size() - s2.size());
        if(tmp > 0) {
            std::cout << binPow(tmp, m, s1 == s2) << "\n";
        }
        else if(tmp == 0) std::cout << 1 << "\n";
        else {
            tmp = -tmp;
            std::cout << (check(s1, s2, tmp) || check(s2, s1, tmp) ? 1 : 0) << "\n";
        }
    }
}