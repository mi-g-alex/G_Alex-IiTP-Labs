#include<iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    long long i = ceil(std::sqrt(n));
    long long k = 1 + (i) * (i - 1);
    if (n < k) std::cout << (i - (k - n) - 1) << " " << i - 1;
    else if(n == k) std::cout << i - 1 << " " << i - 1;
    else std::cout << i - 1 << " " << (i - (n - k) - 1);
}