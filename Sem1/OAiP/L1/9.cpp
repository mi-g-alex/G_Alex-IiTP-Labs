#include <iostream>
#include <cmath>

int main() {
    long long a, b;
    std::cout << (123 && 130);
    //1000001
    //0111111
    //1111110
    //126
    std::cin >> a >> b;
    // 1001 0110
    a = a ^ b;
    std::cout << a << " " << b << "\n";
    // 1111 0110
    b = a ^ b;
    std::cout << a << " " << b << "\n";
    // 1111 1001
    a = a ^ b;
    std::cout << a << " " << b << "\n";
    // 0110 1001
}

