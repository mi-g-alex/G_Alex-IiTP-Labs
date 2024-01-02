#include <iostream>
#include <string>


int main() {
    std::string s;
    std::cin >> s;
    if (s.find('.') != s.rfind('.')) {
        std::cerr << "Error\n";
        main();
    }

    for (long long i = 0; i < s.size(); i++) { // O(n)
        if (s[i] != '0' && s[i] != '1' && s[i] != '.') {
            std::cerr << "Error\n";
            main();
        }
    }

    if (s.find('.') >= s.size()) {
        std::cout << s;
        return 0;
    }

    if (s.find('.') == 0) {
        std::cout << (std::string &) s[s.find('.') + 1];
        return 0;
    }


    auto k = (long long) s.find('.');
    long long i;
    if (s[k + 1] == '1') {
        for (i = k - 1; i > 0; --i) {     // O(n^2)
            if (s[i] == '0') {
                s[i] = '1';
                for (long long j = i + 1; j < k; j++) {
                    s[j] = '0';
                }
                s.erase(k);
                break;
            }
        }
    }
    if (i == 0) {
        s.insert(1, "1");
        for (i = 2; i <= k; i++) s[i] = '0';   // O(n)
        s.erase(k + 1);
    }

    std::cout << s;

}