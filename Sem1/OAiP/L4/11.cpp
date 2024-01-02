#include <iostream>
#include <cmath>
#include <string>

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

void inputNumber(long long *t) {
    *t = checkInput(*t);
}

int main() {
    std::string previewText = "Задача #11\n\nРешение написал Александр Горгун\n\nСуть задания: ввести в консоль поле сапера и вывести заполненное цифрами.\n\n";
    std::cout << previewText;
    while(true) {
        long long n, m;
        std::cout << "Введите количество кол-во строк (от 3 до " + std::to_string(100) +
                ")\n\nВведите 0 чтобы выйти из программы\n\nСтрок:\n";

        do {
            inputNumber(&n);
            if (n == 0) return 0;
            if (n > 100 || n < 3) {
                std::cerr << "Error\n";
            }
        } while (n > 100 || n < 3);

        std::cout << "Введите количество кол-во столбцов (от 3 до " + std::to_string(100) +
                     ")\n\nВведите 0 чтобы выйти из программы\n\nСтолбцов:\n";

        do {
            inputNumber(&m);
            if (m == 0) return 0;
            if (m > 100 || m < 3) {
                std::cerr << "Error\n";
            }
        } while (m > 100 || m < 3);


        n += 2;
        m += 2;
        auto field = (char **) malloc(sizeof(char **) * (n));

        for (long long i = 0; i < n; ++i) {
            field[i] = (char *) malloc(sizeof(char *) * (m));
        }

        std::cout << "Введите поле с помощью . и *\n";

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) {
                field[i][j] = '.';
            }
        }

        for (long long i = 1; i < n - 1; ++i) {
            for (long long j = 1; j < m - 1; ++j) {
                std::cin >> field[i][j];
                if (field[i][j] != '.' && field[i][j] != '*') {
                    j--;
                }
            }
        }

        for (long long i = 1; i < n - 1; ++i) {
            for (long long j = 1; j < m - 1; j++) {
                if (field[i][j] == '.') {
                    field[i][j] = '0';
                    for (long long i1 = i - 1; i1 <= i + 1; i1++)
                        for (long long i2 = j - 1; i2 <= j + 1; ++i2) {
                            if (field[i1][i2] == '*') field[i][j]++;
                        }
                }
            }
            std::cout << "\n";
        }


        for (long long i = 1; i < n - 1; ++i) {
            for (long long j = 1; j < m - 1; ++j) {
                std::cout << (field[i][j] - '0' ? field[i][j] : '.') << "  ";
            }
            std::cout << "\n";
        }

        for (long long i = 0; i < n; ++i) {
            free(field[i]);
        }
        free(field);
    }
}
