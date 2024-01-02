#include <iostream>

bool input(std::string &s) {
    std::cin >> s;
    if (s.size() == 1) {
        std::cerr << "Error\n";
        return false;
    }
    if (s.find('.') != s.rfind('.')) {
        std::cerr << "Error\n";
        return false;
    }

    for (long long i = 0; i < s.size(); i++) { // O(n)
        if (s[i] != '0' && s[i] != '1' && s[i] != '.') {
            std::cerr << "Error\n";
            return false;
        }
    }
    if (s.find('.') >= s.size() || s.find('.') < 0) {
        return true;
    }

    if (s.find('.') == 0 || s.find('.') == 1) {
        s = s[s.find('.') + 1];
        return true;
    }


    auto k = (long long) s.find('.');
    long long i;
    if (s[k + 1] == '1') {
        for (i = k - 1; i > 0; --i) { // O(n^2)
            if (s[i] == '0') {
                s[i] = '1';
                for (long long j = i + 1; j < k; j++) {
                    s[j] = '0';
                }
                s.erase(k);
                return true;
            }
        }
    }
    if (i == 0) {
        s.insert(1, "1");
        for (i = 2; i <= k; i++) s[i] = '0'; // O(n)
        s.erase(k + 1);
    }
    return true;

}

void convert(std::string &s) {
    for (long long i = 1; i < s.size(); i++) { // O(n)
        s[i] = (s[i] - '0' ? '0' : '1');
    }

    if (s[s.size() - 1] == '1') {
        for (long long i = (long long) s.size() - 1; i >= 0; i--) { // O(n)
            if (s[i] == '1') {
                s[i]--;
            } else {
                s[i]++;
                break;
            }
        }
    } else {
        s[s.size() - 1]++;
    }
}

void sum(std::string &s1, std::string &s2) {
    if (s1.size() > s2.size()) {
        s2.insert(1, s1.size() - s2.size(), s2[0]);
    } else {
        s1.insert(1, s2.size() - s1.size(), s1[0]);
    }
    /*s1.insert(0, 1, '0');
    s2.insert(0, 1, '0');*/
    //std::cout << "\n" << s1 << "\n" << s2 << "\n";

    for (long long j = (long long) s2.size() - 1; j >= 0; j--) { // O(n^2)
        if (s2[j] == '1') {
            if (s1[j] == '1') {
                for (long long i = j; i >= 0; i--) {
                    if (s1[i] == '1') {
                        s1[i]--;
                    } else {
                        s1[i]++;
                        break;
                    }
                }
            } else {
                s1[j]++;
            }
        }
    }
   while(s1[0] == s1[1] && s1.size() > 2) { // O(n)
       s1.erase(1, 1);
   }
}

void convertAgain(std::string &s1) {
    for(long long i = 1; i < s1.size(); i++) { // O(n)
        s1[i] = ((s1[i] - '0') ? '0' : '1');
    }

    if (s1[s1.size() - 1] == '1') {
        for (long long i = (long long) s1.size() - 1; i >= 0; i--) { // O(n)
            if (s1[i] == '1') {
                s1[i]--;
            } else {
                s1[i]++;
                break;
            }
        }
    } else {
        s1[s1.size() - 1]++;
    }

}


int main() {
    std::string s1, s2;

    while (!input(s1));
    s1.insert(1, "0");
    if (s1[0] == '1') convert(s1);

    while (!input(s2));
    s2.insert(1, "0");
    if (s2[0] == '1') convert(s2);

    sum(s1, s2);

    if(s1[0] == '1') {
        convertAgain(s1);
    }
    std::cout << s1 << "\n";

}
