#include <iostream>
#include <vector>
#include <algorithm>

std::string start(long long x) {

    std::vector<long long> a;
    while (x) {
        a.push_back(x % 3);
        x /= 3;
    }
    for (long long i = 0; i < a.size() - 1; i++) {
        if (a[i] <= 0) {
            a[i] += 3;
            a[i + 1]--;
            if (a[i + 1] == 0 && i == a.size() - 2) a.erase(a.end() - 1);
        }
    }
    std::reverse(a.begin(), a.end());

    std::string s;
    for (auto i: a) {
        s.push_back(i + '0');
    }
    return s;
}