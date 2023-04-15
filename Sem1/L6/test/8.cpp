#include <iostream>
#include "../checkInput/checkInput.h"

void reverse(std::string &s) {
    int t = s.size();
    for (int i = t - 2; i >= 0; i--) {
        s += s[i];
    }
}

std::string toDoTask8(std::string& s, std::string& s1) {
    reverse(s);
    bool is = false;
    while (s.size() > 0) {
        if (s.find(s1) < s.size()) {
            is = true;
            break;
        }
        s.erase(s.size() / 2, 2);
    }
    return (is ? "YES" : "NO");
}
