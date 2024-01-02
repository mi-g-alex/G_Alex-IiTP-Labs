#include <iostream>
#include "../checkInput/checkInput.h"

void fillArrayByRules(long long **, long long);

void transArray(long long **, long long **, long long);

long long calcSumLine(long long **, long long, long long);

long long calcSumColumn(long long **, long long, long long);


void coutArr(long long **a, long long n, bool b) {
    for (long long i = 0; i < n; ++i) {
        std::cout << "\t";
        for (long long j = 0; j < n; ++j) {
            std::cout << a[i][j] << "\t";
        }

        if ((i + b) % 2) std::cout << "Sum: " << calcSumLine(a, i, n);

        std::cout << "\n";
    }
    std::cout << "Sum:\t";
    if (b) std::cout << "\t";
    for (int i = b; i < n; i += 2) {
        std::cout << calcSumColumn(a, i, n) << "\t\t";
    }
    std::cout << "\n\n";
}

void start() {
    long long n;
    std::cout << "Введите размер матрицы (n от 1 до 101)\n";
    n = checkInput(n);

    while (n < 0 || n > 101) {
        std::cerr << "Error\n";
        n = checkInput(n);
    }


    auto **a = new long long *[n + 1];
    for (int i = 0; i < n; ++i) {
        a[i] = new long long[n + 1];
    }

    auto **b = new long long *[n];
    for (int i = 0; i < n; ++i) {
        b[i] = new long long[n];
    }

    fillArrayByRules(a, n);
    transArray(a, b, n);

    coutArr(a, n, false);
    coutArr(b, n, true);
}

int main() {
    std::cout
            << "Задача #1\n\nРешение написал Александр Горгун\n\nСуть задания:\nСформировать двумерный динамический массив-матрицу А размерностью n×n. \n"
               "Сформировать транспонированную матрицу B=A^T. \n"
               "Определить сумму элементов четных строк и нечетных столбцов для массива-матрицы А.\n"
               "Сумму четных столбцов и нечетных строк для массива-матрицы В. На экран вывести массивы-матрицы А и В построчно и значения сумм.\n";
    while(true) {
        std::cout
                << "\n\nВведите 0, чтобы выйти из программы\nВведите 1, чтобы выполнить программы\n\n";
        long long x = checkInput(x);
        while(x != 0 && x != 1) {
            std::cerr << "Error\n\n";
            x = checkInput(x);
        }
        if(x == 0) return 0;
        else start();
    }
}
