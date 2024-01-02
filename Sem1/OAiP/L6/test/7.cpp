#include <iostream>

long long toDoTask7(std::string& s) {
    auto t = (long long)s.size();
    for (int i = 0; i < t / 2; ++i) {
        if (s[i] != s[t - i - 1]) {
            return t;
        }
    }
    for (int i = 0; i < t; ++i) {
        if (s[i] != s[0]) {
            return t - 1;
        }
    }
    return -1;
}