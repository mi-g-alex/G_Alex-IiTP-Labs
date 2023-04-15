#include <iostream>
#include <cmath>

#include <iostream>
#include <string>
#include <cmath>

bool isItNumber(char c) {
    return (c >= '0' && c <= '9');
}

long long checkInput(long long t) {


    std::string s;

    do {

        std::cin >> s;

        bool wasDot = false;
        bool wasE = false;
        bool isNumber = true;

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
                isNumber = false;
            } else {
                if (s > "9223372036854775807") isNumber = false;
            }
            if (isNumber) return stoll(s);
        }
        std::cerr << "Error\n";
    } while (true);
}

long double checkInput(long double t) {

    std::string s;
    do {
        bool isNumber = true;
        bool wasDot = false;
        bool wasE = false;
        std::cin >> s;

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
                return 0;
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
        else std::cerr << "Error\n";
    } while (true);
}


void inputNumber(long long *t) {
    *t = checkInput(*t);
}

void inputNumber(long double *t) {
    *t = checkInput(*t);
}

void inputArray(auto t, const long long *n, const std::string &text) {

    std::cout << text << "\n";
    for (long long i = 0; i < *n; i++) {
        for (long long j = 0; j < *n; ++j) {
            for (int k = 0; k < *n; ++k) {
                t[i][j][k] = checkInput(t[i][j][k]);
            }
        }
    }
}

int main() {
    std::string previewText = "Задача #9\n\nРешение написал Александр Горгун\n\nСуть задания: ввести в консоль трехмерный массив.\nВывести сумму элементов максимальной диагонали куба и сами элементы.\n";
    std::cout << previewText;
    while(true) {


        long long numberOfLines;
        long long maxArrayNumberOfLines = 100;

        std::cout << "Введите количество сторону куба (от 1 до " + std::to_string(maxArrayNumberOfLines) +
                     ")\n\nВведите 0 чтобы выйти из программы\n\nСторона:\n";

        do {
            inputNumber(&numberOfLines);
            if (numberOfLines == 0) return 0;
            if (numberOfLines > maxArrayNumberOfLines || numberOfLines < 1) {
                std::cerr << "Error\n";
            }
        } while (numberOfLines > maxArrayNumberOfLines || numberOfLines < 1);


        auto a = (long long ***) malloc(sizeof(long long ***) * numberOfLines);
        for (long long i = 0; i < numberOfLines; i++) {
            a[i] = (long long **) malloc(sizeof(long long **) * numberOfLines);

            for (int j = 0; j < numberOfLines; ++j) {
                a[i][j] = (long long *) malloc(sizeof(long long *) * numberOfLines);
            }
        }

        inputArray(a, &numberOfLines,
                   "Введите " + std::to_string(numberOfLines * numberOfLines * numberOfLines) + " элементов:\n");

        long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

        for (int i = 0; i < numberOfLines; i++) {
            sum1 += a[i][i][i];
            sum2 += a[numberOfLines - i - 1][i][i];
            sum3 += a[i][numberOfLines - i - 1][i];
            sum4 += a[i][i][numberOfLines - i - 1];
        }

        if (std::max({sum1, sum2, sum3, sum4}) == sum1) {
            std::cout << sum1 << "\n";
            for (int i = 0; i < numberOfLines; i++) {
                std::cout << a[i][i][i] << " ";
            }
        } else if (std::max({sum1, sum2, sum3, sum4}) == sum2) {
            std::cout << sum2 << "\n";
            for (int i = 0; i < numberOfLines; i++) {
                std::cout << a[numberOfLines - i - 1][i][i] << " ";
            }
        } else if (std::max({sum1, sum2, sum3, sum4}) == sum3) {
            std::cout << sum3 << "\n";
            for (int i = 0; i < numberOfLines; i++) {
                std::cout << a[i][numberOfLines - i - 1][i] << " ";
            }
        } else if (std::max({sum1, sum2, sum3, sum4}) == sum4) {
            std::cout << sum4 << "\n";
            for (int i = 0; i < numberOfLines; i++) {
                std::cout << a[i][i][numberOfLines - i - 1] << " ";
            }
        }

        for (int i = 0; i < numberOfLines; i++)
            for (int j = 0; j < numberOfLines; ++j) {
                free(a[i][j]);
            }
        for (int i = 0; i < numberOfLines; i++)
            free(a[i]);

        free(a);
    }
}