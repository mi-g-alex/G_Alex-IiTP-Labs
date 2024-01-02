#include <iostream>
#include <cmath>

bool isItNumber(char c) {
    return (c >= '0' && c <= '9');
}

long long checkInput(unsigned long long t) {


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

void inputNumber(unsigned long long *t) {
    *t = checkInput(*t);
}

void odd(unsigned long long n, unsigned long long **sq) {
    unsigned long long x = 0, y = n / 2;

    for (unsigned long long i = 1; i <= n * n; ++i) {

        sq[x][y] = i;

        if (x == 0 && y == n - 1)
            x++;
        else if (x == 0) {
            x = n - 1;
            y++;
        } else if (y == n - 1) {
            y = 0;
            x--;
        } else if (sq[x - 1][y + 1] != 0)
            x++;
        else {
            x--;
            y++;
        }
    }
}

void evenOdd(unsigned long long n, unsigned long long **sq) {
    for (unsigned long long i = 0; i < n; ++i) {
        for (unsigned long long j = 0; j < n; ++j) {
            sq[i][j] = n * i + j + 1;

        }
    }
    unsigned long long d = 4;
    for (unsigned long long i = 0; i < n / 2; i += 4) {
        for (unsigned long long j = 0; j < n; j += 4) {
            if(i == n / 2 - 2) d = 2;
            for (unsigned long long k = 0; k < d; ++k) {
                std::swap(sq[i + k][j + k], sq[n - (i + k) - 1][n - (j + k) - 1]);
                std::swap(sq[i + k][j + 3 - k], sq[n - (i + k) - 1][n - (j + 3 - k) - 1]);
            }
        }
    }
}


void even(unsigned long long n, unsigned long long **sq) {
    unsigned long long n2 = n / 2;
    odd(n2, sq);
    for (unsigned long long i = 0; i < n2; i++) {
        for (unsigned long long j = 0; j < n2; ++j) {
            sq[i][j + n2] = sq[i][j] + 2 * n2 * n2;
            sq[i + n2][j] = sq[i][j] + 3 * n2 * n2;
            sq[i + n2][j + n2] = sq[i][j] + n2 * n2;
        }
    }

    for (unsigned long long i = 0; i < n2; ++i) {
        for (unsigned long long j = 0; j < n2 / 2; ++j) {
            if(i != n2 / 2) {
                std::swap(sq[i][j], sq[n2 + i][j]);
            }
            else std::swap(sq[i][i + j], sq[i + n2][i + j]);
        }
    }

    for (unsigned long long i = 0; i < n2; i++) {
        for (unsigned long long j = n2 + n2 / 2; j > n2 + n2 / 2 - (n2 / 2 - 1); j--)
        std::swap(sq[i][j], sq[i + n2][j]);
    }
}

int main() {
    std::string previewText = "Задача #13\n\nРешение написал Александр Горгун\n\nСуть задания: ввести в сторону квадрата.\nВывести магический квадрат.\n";
    std::cout << previewText;

    unsigned long long n;
    while(true) {
        //std::cin >> n;

        std::cout << "\nВведите 0 чтобы выйти\nВведите n от 3 до 4000):\n";

        do {
            inputNumber(&n);
            if (n == 0) return 0;
            if (n > 4001 || n < 1) {
                std::cerr << "Error\n";
            }
        } while (n > 4001 || n < 3);

        auto sq = (unsigned long long **) calloc(n, sizeof(unsigned long long **));
        for (unsigned long long i = 0; i < n; i++) {
            sq[i] = (unsigned long long *) calloc(n, sizeof(unsigned long long *) * (n));
        }

        if (n % 2) odd(n, sq);
        else if (n % 4 == 0) evenOdd(n, sq);
        else even(n, sq);

        for (unsigned long long i = 0; i < n; ++i) {
            for (unsigned long long j = 0; j < n; ++j) {
                std::cout << sq[i][j] << "\t";
            }
            std::cout << "\n";
        }


        for (unsigned long long i = 0; i < n; ++i) {
            free(sq[i]);
        }
        free(sq);
    }
}