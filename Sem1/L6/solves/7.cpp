#include <iostream>

int toDoTask7() {
    std::string s;
    std::cin >> s;
    auto t = (long long)s.size();
    for (int i = 0; i < t / 2; ++i) {
        if (s[i] != s[t - i - 1]) {
            std::cout << t;
            return 0;
        }
    }
    for (int i = 0; i < t; ++i) {
        if (s[i] != s[0]) {
            std::cout << t - 1;
            return 0;
        }
    }
    std::cout << -1;
}