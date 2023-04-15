#include <iostream>
#include <cmath>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    long double x1, x2, y1, y2, R, r;

    std::cout << "x1, y1, r\n";
    std::cin >> x1 >> y1 >> r;
    std::cout << "x2, y2, R\n";
    std::cin >> x2 >> y2 >> R;

    long double s = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if (s + r <= R) {
        std::cout << "Да";
    } else if (s + R <= r) {
        std::cout << "Да, но справедливо обратное для двух фигур";
    } else if (s <= R + r) {
        std::cout << "Фигуры пересекаются";
    } else {
        std::cout << "Ни одно условие не выполнено";
    }
    return 0;
}
