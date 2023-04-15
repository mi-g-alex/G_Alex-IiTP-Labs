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

    std::string previewText = "Задача #3\nВариант 9\n\nРешение написал Александр Горгун\n\nСуть задания: ввести в консоль матрицу размерности n.\nНадо проверить является ли матрица волшебным квадратом\n\n";
    std::cout << previewText;

    const long long maxArrayNumberOfItems = 100;
    long long numberOfItems, i, j;

    while (true) {
        
        std::cout << "Введите размерность матрицы (от 1 до " + std::to_string(maxArrayNumberOfItems) +")\n\nВведите 0 чтобы выйти из программы\n\nПорядок матрицы:\n";
        do {
            inputNumber(&numberOfItems);
            if (numberOfItems == 0) return 0;
            if (numberOfItems > maxArrayNumberOfItems || numberOfItems < 1) {
                std::cerr << "Error\n";
            }
        } while (numberOfItems > maxArrayNumberOfItems || numberOfItems < 1);

        auto **defaultArray = new long double *[numberOfItems];

        for (i = 0; i < numberOfItems; i++)
            defaultArray[i] = new long double[numberOfItems];

        inputArray(defaultArray, &numberOfItems, &numberOfItems,
                   "\nВведите матрицу " + std::to_string(numberOfItems) +
                   "-го порядка\n");

        std::cout << "\nИсходная матрица:\n";
        outputArray(defaultArray, &numberOfItems, &numberOfItems);

        long double sum1 = 0;
        for (i = 0; i < numberOfItems; i++) sum1 += defaultArray[0][i];

        bool isMagicSquare = true;
        for (i = 0; i < numberOfItems && isMagicSquare; i++) {
            long double checksum = 0;
            for (j = 0; j < numberOfItems; j++)
                checksum += defaultArray[i][j];
            if (checksum != sum1) isMagicSquare = false;
        }

        for (i = 0; i < numberOfItems && isMagicSquare; i++) {
            long double checksum = 0;
            for (j = 0; j < numberOfItems; j++)
                checksum += defaultArray[j][i];
            if (checksum != sum1) isMagicSquare = false;
        }

        long double checksum = 0;
        for (i = 0, j = 0; i < numberOfItems && isMagicSquare; i++, j++) {
            checksum += defaultArray[i][j];
        }
        if (checksum != sum1) isMagicSquare = false;

        checksum = 0;
        for (i = 0, j = numberOfItems - 1; i < numberOfItems && isMagicSquare; i++, j--) {
            checksum += defaultArray[i][j];
        }
        if (checksum != sum1) isMagicSquare = false;

        std::cout << "Матрица " << (isMagicSquare ? "является" : "не является") << " магическим квадратом";
        std::cout << "\n\nAh shit. Here we go again.\n\n";

        for (i = 0; i < numberOfItems; i++)
            delete defaultArray[i];

        delete[] defaultArray;

    }
}
