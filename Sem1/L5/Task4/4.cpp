#include <iostream>
#include "../checkInput/checkInput.h"

long double ** createDynArray(long long n, long long m) {
    auto **a = new long double *[n];
    for (long long i = 0; i < n; ++i) {
        a[i] = new long double[m];
    }

    return a;
}

void cinArray(long double **a, long long n, long long m, long long *k) {
    std::cout << "Введите " << n * m << " элементов\n";
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            a[i][j] = checkInput(a[i][j]);
            if (a[i][j] == 0) (*k)++;
        }
    }
}

void find0(long double **a, long double **arrayOf0, long long n, long long m) {
    long long k = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                arrayOf0[k][0] = i;
                arrayOf0[k++][1] = j;
            }
        }
    }
}

void replaceArray(long double **a, long long n, long long m) {
    for (long long i = 0; i < n / 2; ++i) {
        for (long long j = 0; j < m; ++j) {
            std::swap(a[i][j], a[n - i - 1][m - j - 1]);
        }
    }
    if(n % 2)
        for (long long i = 0; i < m / 2; ++i) {
            std::swap(a[n / 2][i], a[n / 2][m - i - 1]);
        }
}

void coutArr(long double **a, long long n, long long m) {
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            std::cout << a[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void start() {
    long long n = 0, m = 0;

    std::cout << "Введите n и m (от 1 до 100)\n";
    n = checkInput(n);
    m = checkInput(m);
    while(n < 0 || n > 101 || m < 0 || m > 101) {
        std::cout << "Error\n";
        n = checkInput(n);
        m = checkInput(m);
    }

    long double **a = createDynArray(n, m);

    long long k = 0;

    cinArray(a, n, m, &k);

    long double **arrayOf0 = nullptr;
    if (k) {
        arrayOf0 = createDynArray(k, 2);
        find0(a, arrayOf0, n, m);
    }
    if(k) {
        std::cout << k << "\n\n";
        std::cout << "\ni\tj нулей\n";
        coutArr(arrayOf0, k, 2);
        std::cout << "\n";
    }
    std::cout << "Введенный массив\n";
    coutArr(a, n, m);
    std::cout << "\nГотовый массив\n";
    replaceArray(a, n, m);
    coutArr(a, n, m);
}

int main() {
    std::cout
            << "Задача #4\n\nРешение написал Александр Горгун\n\nСуть задания:\nСоздать двумерный динамический массив вещественных чисел. \n"
               "Определить, встречаются ли среди них элементы с нулевым значением.\n"
               "Если встречаются такие элементы, то определить их индексы и общее количество.\n"
               "Переставить элементы этого массива в обратном порядке и вывести на экран.";
    while(true) {
        std::cout
                << "\n\nВведите 0, чтобы выйти из программы\nВведите 1, чтобы выполнить программу\n\n";
        long long x = 0;
        x = checkInput(x);
        while(x != 0 && x != 1) {
            std::cerr << "Error\n\n";
            x = checkInput(x);
        }
        if(x == 0) return 0;
        else start();
    }
}