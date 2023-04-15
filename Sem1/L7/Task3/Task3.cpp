#include <iostream>
#include <string>
#include "../checkInput/checkInput.h"

bool checkNumber(std::string &s1, long long x) {
    for (char &i: s1) { // O(n)
        if (i >= '0' && i <= '9') i = char(int(i) - '0');
        else if (i >= 'A' && i <= 'A' - 11 + x) i = char(int(i) - 'A' + 10);
        else return false;
    }

    return true;
}

void outputArray(std::string &s1) {
    for (char i: s1) { // O(n)
        if (i <= 9) std::cout << char(i + '0');
        else std::cout << char(i + 'A' - 10);
    }
}


void sum(std::string &s1, std::string &s2, long long x) {
    s1.insert(0, 1, 0);
    long long q = (long long) s1.size() - 1;
    for (auto i = (long long) s2.size() - 1; i >= 0; i--) { // O(n)
        s1[q] = char(s1[q] + s2[i]);
        long long k = q - 1;
        if (s1[q] >= x) {
            while (s1[k + 1] >= x && k >= 0) {
                s1[k + 1] = char(int(s1[k + 1]) % x);
                s1[k]++;
                k--;
            }
        }
        q--;
    }
}

void minus(std::string &s1, std::string &s2, long long x) {
    auto k1 = (long long) s1.size() - 1, k2 = (long long) s2.size() - 1;
    for (auto i = 0; i < s2.size(); i++) { // O(n)
        if (s2[k2 - i] > s1[k1 - i]) {
            s1[k1 - i - 1]--;
            s1[k1 - i] = char(s1[k1 - i] + x);
        }
        s1[k1 - i] = char(s1[k1 - i] - s2[k2 - i]);
    }
}

bool isS1Minus = false, isS2Minus = false;

bool TODO(std::string s1, std::string s2, long long x) {
    if (isS1Minus == isS2Minus) {

        if (s2.size() > s1.size()) std::swap(s1, s2);

        sum(s1, s2, x);
        if (isS1Minus) {
            std::cout << "-";
        }

    } else {
        if (s2.size() > s1.size()) {

            std::swap(s1, s2);
            if (isS2Minus) std::cout << "-";

        } else if (s2.size() == s1.size()) {
            if (s2 > s1) {
                std::swap(s1, s2);

                if (isS2Minus) std::cout << "-";

            } else if (s2 == s1) {
                std::cout << 0;
                return 0;
            } else {

                if (isS1Minus) std::cout << "-";

            }
        } else {

            if (isS1Minus) std::cout << "-";

        }
        minus(s1, s2, x);
    }


    while (s1[0] == 0) s1.erase(0, 1); // O(n)
    outputArray(s1);
    std::cout << "_" << x;
}

int main() {
    std::cout << "Введи СИ:\n";
    long long x = 4;
    x = checkInput(x);
    while (x < 1 || x > 36) {
        x = checkInput(x);
    }
    std::cout << "Введи перевое:\n";
    std::string s1;
    do {
        std::cin >> s1;
        if (s1[0] == '-') {
            isS1Minus = true;
            s1.erase(0, 1);
        }
    } while (!checkNumber(s1, x));
    std::cout << "Введи второе:\n";
    std::string s2;
    do {
        std::cin >> s2;
        if (s2[0] == '-') {
            isS2Minus = true;
            s2.erase(0, 1);
        }
    } while (!checkNumber(s2, x));

    std::string s1_1 = s1, s1_2 = s2;
    std::cout << "+: ";
    TODO(s1, s2, x);
    std::cout << "\n";
    std::cout << "-: ";
    isS2Minus = !isS2Minus;

    TODO(s1, s2, x);

}