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
                s[0] = '1';
                if (s > "19223372036854775808") isNumber = false;
                s[0] = '-';
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
        else std::cerr << "Error\n";
    } while (true);
}


void inputNumber(long long *t) {
    *t = checkInput(*t);
}

void inputNumber(long double *t) {
    *t = checkInput(*t);
}

void inputArray(auto t, const long long *m, const long long *n, const std::string &text) {

    std::cout << text << "\n";
    for (long long i = 0; i < *m; i++) {
        for (long long j = 0; j < *n; j++) {
            t[i][j] = checkInput(t[i][j]);
        }
    }
}

void outputArray(auto array, const long long *m, const long long *n) {
    for (long long i = 0; i < *m; ++i) {
        for (long long j = 0; j < *n; j++)
            std::cout << array[i][j] << "\t";
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

int main() {
    std::string previewText = "Задача #2\nВариант 9\n\nРешение написал Александр Горгун\n\nСуть задания: ввести в консоль двухмерный массив размером m * n.\nВывести максимальный элемент находящийся выше побочной диагонали\n\n";
    std::cout << previewText;

    const long long maxArrayNumberOfLines = 100, maxArrayNumberOfItems = 100;
    long double defaultArray[maxArrayNumberOfLines][maxArrayNumberOfItems];
    long long numberOfItems, numberOfLines, i, j;

    while (true) {
        std::cout << "Введите количество строк в массиве (от 1 до " + std::to_string(maxArrayNumberOfLines) +
                     ")\n\nВведите 0 чтобы выйти из программы\n\nКоличество строк:\n";
        do {
            inputNumber(&numberOfLines);
            if (numberOfLines == 0) return 0;
            if (numberOfLines > maxArrayNumberOfLines || numberOfLines < 1) {
                std::cerr << "Error\n";
            }
        } while (numberOfLines > maxArrayNumberOfLines || numberOfLines < 1);

        std::cout << "\nВведите количество столбцов в каждой строчке массива (от 2 до " +
                     std::to_string(maxArrayNumberOfItems) +
                     ")\n\nВведите 0 чтобы выйти из программы\n\nКоличество столбцов:\n";

        do {
            inputNumber(&numberOfItems);
            if (numberOfItems == 0) return 0;
            if (numberOfItems > maxArrayNumberOfItems || numberOfItems < 2) {
                std::cerr << "Error\n";
            }
        } while (numberOfLines > maxArrayNumberOfItems || numberOfItems < 2);

        inputArray(defaultArray, &numberOfLines, &numberOfItems,
                   "\nПострочно введите двухмерный массив состоящий из " + std::to_string(numberOfLines * numberOfItems) +
                   " элементов");

        std::cout << "\nИсходный массив:\n";
        outputArray(defaultArray, &numberOfLines, &numberOfItems);

        long double maxElement = -INT64_MAX;
        for (i = 0; i < numberOfLines && j > 0; i++)
            for (j = 0; j < numberOfItems - i - 1; ++j)
                maxElement = std::max(maxElement, defaultArray[i][j]);

        std::cout << "Максимальные элемент, находящийся выше побочной оси равен " << maxElement;

        std::cout << "\n\nAh shit. Here we go again.\n\n";

    }
}
