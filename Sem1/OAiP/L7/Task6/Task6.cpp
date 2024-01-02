#include <iostream>
#include "../checkInput/checkInput.h"

bool check(long long a, long long k) {
    long long plus = (k + 1) >> 1;
    while (a > k) a = (a >> 1) + ((a & 1) ? plus : 0); // O(log(n))
    return (a == k || a == 0);
}

int main() {
    long long a;
    a = checkInput(a);
    if(a < 0) a = ~a + 1;
    std::cout << a << " ⋮ 7  \t- " << (check(a, 7) ? "True" : "False") << "\n"
              << a << " ⋮ 73 \t- " << (check(a, 73) ? "True" : "False") << "\n"
              << a << " ⋮ 109\t- " << (check(a, 109) ? "True" : "False") << "\n";
}