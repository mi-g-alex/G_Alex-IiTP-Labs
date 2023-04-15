#include <iostream>

int main() {
    int i = 1;
    long long sum = 0;
    while(i <= 30) {
        long long a, b;
        if (i % 2) {
            a = i;
            b = i * i;
        } else {
            a = i / 2;
            b = i * i * i;
        }
        sum += (a - b) * (a - b);
        i++;
    }
    std::cout << sum;
    return 0;
}
