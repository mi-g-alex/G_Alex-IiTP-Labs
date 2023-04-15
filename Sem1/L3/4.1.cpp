#include <iostream>

int main() {

    long long n;
    std::cin >> n;

    long long sum = 0;
    for (long long i = 2; i <= n; i += 2){
        sum += i;
    }

    std::cout << sum;
    return 0;
}
