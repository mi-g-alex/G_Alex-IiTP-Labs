#include <iostream>
#include <string>

std::string input;

bool isLetter(char x) {
    return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
}

bool isConsonant(char x) {
    return (((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
            && x != 'a' && x != 'o' && x != 'e' && x != 'u' && x != 'i'
            && x != 'A' && x != 'O' && x != 'E' && x != 'U' && x != 'I');
}

void toLower(std::string &s) {
    for (char &i: s) {
        if (i >= 'A' && i <= 'Z') i += 32;
    }
}

void replace(long long i, const std::string &from, const std::string &to) {
    std::string toRet;
    //std::cout << s << " " << i << " " << from << " " << to << "|\n";
    for (long long j = 0; j < i; ++j) {
        toRet += input[j];
    }
    toRet += to;
    for (long long j = i + (long long) from.size(); j < input.size(); ++j) {

        toRet += input[j];
    }
    input = toRet;
}


void check() {
    for (long long i = 0; i < input.size(); ++i) {
        if (isLetter(input[i])) {
            std::string s1, s2, s3;
            s1 += input[i];
            s1 += input[i + 1];
            bool isFirstBig = (s1[0] >= 'A' && s1[0] <= 'Z');
            s2 = s1;
            s3 = s2 + input[i + 2];
            toLower(s2);
            toLower(s3);
            if (s2 == "ee") {
                replace(i, "ee", "i");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2 == "ce") {
                replace(i, "ce", "se");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2 == "ci") {
                replace(i, "ci", "si");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2 == "cy") {
                replace(i, "cy", "sy");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2[0] == 'c') {
                replace(i, "c", "k");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2 == "oo") {
                replace(i, "oo", "u");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s3 == "you") {
                replace(i, "you", "u");
                if (isFirstBig) input[i] -= 32;
                i-=3;
            } else if (s2 == "qu") {
                replace(i, "qu", "kv");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2[0] == 'q') {
                replace(i, "q", "k");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2[0] == 'x') {
                replace(i, "x", "ks");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2[0] == 'w') {
                replace(i, "w", "v");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2 == "th") {
                replace(i, "th", "z");
                if (isFirstBig) input[i] -= 32;
                i--;
            } else if (s2 == "ph") {
                replace(i, "ph", "f");
                if (isFirstBig) input[i] -= 32;
                i--;
            }
        }
    }
}

void checkDouble() {
    for (long long i = 0; i < (long long) input.size() - 1; i++) {
        std::string s1, s2, s3, s4;
        s1 = input[i];
        toLower(s1);
        s2 = input[i + 1];
        toLower(s2);
        s3 = input[i];
        s3 += input[i + 1];
        s4 = input[i];
        if (s1 == s2 && isConsonant(input[i])) {
            replace(i, s3, s4);
            i--;
        }
    }
}

void toDoTask4(std::string& s) {
    input = s;
    check();
    checkDouble();
    std::cout << input << "\n";
}


