#include <iostream>
#include "../checkInput/checkInput.h"

void fillArr(long long **a, long long *ans, long long n, long long *length) {
    for (long long i = 0; i < n; ++i) {
        if (a[i][i] % 2 == 0)
            ans[(*length)++] = a[i][i];
    }
}


long long findMultiply(const long long *a, long long length) {
    long long ans = 1;

    for (long long i = 0; i < length; ++i) {
        ans *= a[i];
    }

    return ans;
}

long long forTest(long long n, long long k, long long **a) {
    long long length = 0;
    auto *ansArr = new long long[std::max(n, k)];
    fillArr(a, ansArr, std::min(n, k), &length);
    return findMultiply(ansArr, length);
}

void start() {
    long long n = 0, k = 0;

    std::cout << "\nВведите n и k (от 1 до 100)\n";
    n = checkInput(n);
    k = checkInput(k);
    while(n < 0 || n > 101 || k < 0 || k > 101) {
        std::cout << "Error\n";
        n = checkInput(n);
        k = checkInput(k);
    }
    std::cout << "\nВведите " << n * k << " элементов\n";
    auto **a = new long long *[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new long long[k];
    }

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < k; ++j) {
            a[i][j] = checkInput(a[i][j]);
        }
    }

    long long length = 0;
    auto *ansArr = new long long[std::max(n, k)];
    fillArr(a, ansArr, std::min(n, k), &length);

    if(length) std::cout  << "\nЭлементы\n";
    for (long long i = 0; i < length; ++i) {
        std::cout << ansArr[i] << " ";
    }
    if(length)
        std::cout << "\nПеремножение элементов: " << findMultiply(ansArr, length) << "\n\n";
    else std::cout << "\nЧётных элементов нет\n";
}

int main() {

    std::cout
            << "Задача #3\n\nРешение написал Александр Горгун\n\nСуть задания:\nСформировать двумерный динамический массив-матрицу А размерностью n×k. \n"
               "Создать динамический массив из элементов, расположенных на главной диагонали матрицы и имеющих четное значение.\n"
               "Вычислить произведение элементов динамического массива.\n"
               "Созданный массив и результат произведения вывести на экран.";

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