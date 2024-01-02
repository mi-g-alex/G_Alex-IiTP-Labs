#include <iostream>
#include "../checkInput/checkInput.h"

long long **createDynArray(long long n, long long m) {
    auto **a = new long long *[n];
    for (long long i = 0; i < n; ++i) {
        a[i] = new long long[m];
    }

    return a;
}

void cinArray(long long **a, long long n, long long m, long long *k) {
    std::cout << "Введите " << n * m << " элементов\n";
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            a[i][j] = checkInput(a[i][j]);
            if (i % 2 && a[i][j] % 2) (*k)++;
        }
    }
}

void fillArray(long long **a, long long *ansArr, long long n, long long m) {
    long long k = 0;
    for (int i = 1; i < m; i += 2) {
        for (int j = 0; j < n; j++) {
            if (a[j][i] % 2) ansArr[k++] = a[j][i];
        }
    }
}

void coutArr(long long *a, long long n) {
    for (long long j = 0; j < n; ++j) {
        std::cout << a[j] << "\t";
    }
}

long double findSum(const long long *a, long long n) {
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    return ((long double) sum / (long double) n);
}

void start() {
    long long n = 0, m = 0;

    std::cout << "Введите n и m (от 1 до 100)\n";
    n = checkInput(n);
    m = checkInput(m);
    while (n < 0 || n > 101 || m < 0 || m > 101) {
        std::cout << "Error\n";
        n = checkInput(n);
        m = checkInput(m);
    }

    auto **a = createDynArray(n, m);

    long long k = 0;

    cinArray(a, n, m, &k);

    auto *ansArr = new long long[k];

    fillArray(a, ansArr, n, m);

    coutArr(ansArr, k);

    std::cout << "\n";
    std::cout << findSum(ansArr, k);
}

int main() {
    std::cout
            << "Задача #5\n\nРешение написал Александр Горгун\n\nСуть задания:\nСоздать динамический массив из элементов,расположенных в четных столбцах данного массива и имеющих нечетное значение.\n"
               "Вычислить среднее арифметическое элементов динамического массива.\nВывести результат на экран";
    while (true) {
        std::cout
                << "\n\nВведите 0, чтобы выйти из программы\nВведите 1, чтобы выполнить программы\n\n";
        long long x = 0;
        x = checkInput(x);
        while (x != 0 && x != 1) {
            std::cerr << "Error\n\n";
            x = checkInput(x);
        }
        if (x == 0) return 0;
        else start();
    }
}