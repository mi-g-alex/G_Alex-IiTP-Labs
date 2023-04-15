#include <iostream>

int main() {
    long long k;
    std::cin >> k;
    while (k--) { // O(n)
        std::string x;
        std::cin >> x;
        std::cout << (std::stoll(x) + 1) / 10 << "\n";
    }
}