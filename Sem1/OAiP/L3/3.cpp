#include <iostream>
#include <cmath>

int main() {
    double A, B, M, step;

    std::cout << "A, B, M, step\n";
    std::cin >> A >> B >> M >> step;

    long double H = (B - A) / M;

    for(long double i = A; i <= B; i+= step){

        long double x = A + i * H;

        std::cout << sin(x) - cos(x) << "\n";
    }
}