// OK 4.3.8
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    long long x;
    std::cin >> x;

    if (x % 100 > 10 && x % 100 < 20) {
        std::cout << "Мы нашли " << x << " грибов в лесу";
    } else {
        if (x % 10 == 0) {
            std::cout << "Мы нашли " << x << " грибов в лесу";
        } else {
            if (x % 10 == 1) {
                std::cout << "Мы нашли " << x << " гриб в лесу";
            } else {
                if (x % 10 >= 2 && x % 10 <= 4) {
                    std::cout << "Мы нашли " << x << " гриба в лесу";
                } else {
                    if (x % 10 >= 5 && x % 10 <= 9) std::cout << "Мы нашли " << x << " грибов в лесу";
                }
            }
        }
    }
    return 0;
}