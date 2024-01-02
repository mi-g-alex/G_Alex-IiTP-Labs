#include "../checkInput/checkInput.h"
#include <iostream>
#include <windows.h>
#include <iomanip>

void start() {
    auto (*P)(long double *, long long, long long) = (long double (*)(long double *, long long, long long)) GetProcAddress(
            LoadLibrary(("../Task2/lib/libTask2.dll")), "P");

    long long n = 0;
    std::cout << "\nВведите n (от 1 до 20)\n";
    n = checkInput(n);
    while (n < 0 || n > 20) {
        std::cout << "Error\n";
        n = checkInput(n);
    }

    auto *a = new long double[n];
    std::cout << "\nВведите " << n << "  элементов\n";
    for (long long i = 0; i < n; ++i) {
        a[i] = checkInput(a[i]);
    }

    std::cout << std::setprecision(15) << P(a, 1, n);


}


int main() {
    std::cout
            << "Задача #2\n\nРешение написал Александр Горгун\n\nСуть задания:\nЧто-то рекурсивно посчитать по формуле sin-cos\n";

    while (true) {
        std::cout
                << "\n\nВведите 0, чтобы выйти из программы\nВведите 1, чтобы выполнить программу\n\n";
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

