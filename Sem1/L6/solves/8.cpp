#include <iostream>
#include "../checkInput/checkInput.h"

void reverse(std::string& s) {
    int t = (int)s.size();
    for (int i = t - 2; i >= 0; i--) {
        s += s[i];
    }
}

void toDoTask8() {
    long long t = 0;
    t = checkInput(t);
    while(t--) {
        std::string s, s1;
        std::cin >> s >> s1;
        reverse(s);
        bool is = false;
        while((int)s.size() > 0) {
            if(s.find(s1) < s.size()) {
                is = true;
                break;
            }
            s.erase(s.size() / 2, 2);
        }
        std::cout << (is ? "YES" : "NO") << "\n";
    }
}