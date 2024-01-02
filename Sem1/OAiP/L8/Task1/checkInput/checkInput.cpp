#include <string>
#include <cstdio>
#include "checkInput.h"

bool isItNumber(char c) {
    return (c >= '0' && c <= '9');
}

long long checkInput(long long t) {

    std::string s;

    do {

        char buf[10000];
        scanf("%s", buf);
        s = buf;

        bool wasDot = false;
        bool wasE = false;
        bool isNumber = true;

        if(s.size() == 1) if(isItNumber(s[0])) return s[0] - '0'; else {
                printf("Error\n");
                continue;
            }

        for (long long i = 0; i < s.length() && isNumber; i++) {
            if ((s[i] != 'e' && s[i] != 'E') && s[i] != '-' && s[i] != '.' && !isItNumber(s[i])) isNumber = false;

            if (s[i] == '-')
                if (i != 0 && (s[i - 1] != 'e' && s[i - 1] != 'E' || i == s.length() - 1)) isNumber = false;

            if (s[i] == 'e' || s[i] == 'E') {
                if (wasE) isNumber = false;
                wasE = true;
                if (i == 0 || i == s.length() - 1) isNumber = false;
            }

            if (s[i] == '.') {
                if (wasE || wasDot || s[i + 1] == '-') isNumber = false;
                else if (!wasDot) wasDot = true;
            }

        }
        if (isNumber) {
            if (wasDot || wasE) isNumber = false;
            else if (s[0] == '-') {
                s[0] = '1';
                if (s > "19223372036854775808") isNumber = false;
                s[0] = '-';
            } else {
                if (s.size() > 19) isNumber = false;
                else if(s.size() < 19) isNumber;
                else if (s > "9223372036854775807") isNumber = false;
            }
            if (isNumber) return stoll(s);
        }
        printf("Error\n");
    } while (true);
}

long double checkInput(long double t) {
    std::string s;

    do {

        char buf[10000];
        scanf("%s", buf);
        s = buf;

        bool wasDot = false;
        bool wasE = false;
        bool isNumber = true;

        if(s.size() == 1) if(isItNumber(s[0])) return s[0] - '0'; else {
                printf("Error\n");
                continue;
        }

        for (long long i = 0; i < s.length() && isNumber; i++) {
            if ((s[i] != 'e' && s[i] != 'E') && s[i] != '-' && s[i] != '.' && !isItNumber(s[i])) isNumber = false;

            if (s[i] == '-')
                if (i != 0 && (s[i - 1] != 'e' && s[i - 1] != 'E' || i == s.length() - 1)) isNumber = false;

            if (s[i] == 'e' || s[i] == 'E') {
                if (wasE) isNumber = false;
                wasE = true;
                if (i == 0 || i == s.length() - 1) isNumber = false;
            }

            if (s[i] == '.') {
                if (wasE || wasDot || s[i + 1] == '-') isNumber = false;
                else if (!wasDot) wasDot = true;
            }

        }
        if (isNumber) {

            bool is0 = true;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '0' && s[i] != '.' && s[i] != '-') is0 = false;
            }

            if (is0) {
                t = 0;
                return t;
            }


            std::string s1;
            if (s.size() > 307) isNumber = false;
            else if (!wasE) {
                if (wasDot) {
                    while (s[s.length() - 1] == '0' && s.length() != 1 && s[s.length() - 2] != '-') {
                        s.erase(s.length() - 1, 1);
                    }
                }
                if (s[s.length() - 1] == '.') s.erase(s.length() - 1, 1);
                s1 = s;
                s1[s1.length() - 1]--;
                if (stold(s) == stold(s1)) isNumber = false;
                else {
                    return stold(s);
                }
            } else {
                int e = s.find('e');
                if (e == -1) e = s.find('E');
                if (wasDot)
                    while (s[e - 1] == '0') {
                        s.erase(e - 1, 1);
                        e--;
                    }
                if (s[e - 1] == '.') {
                    s.erase(e - 1, 1);
                    e--;
                }
                s1 = s;
                s1[e - 1]--;
                if (stold(s) == stold(s1)) isNumber = false;
                else {
                    return stold(s);
                }
            }
        }
        if (isNumber) return t;
        else printf("Error\n");
    } while (true);
}

