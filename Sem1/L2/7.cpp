#include <iostream>

int main() {
    long double Y, a, b, c;
    long long N;
    std::cout << "N, a, b, c\n";
    std::cin >> N >> a >> b >> c;
    switch(N) {
        case 2:
            Y = b * c - a * a;
            break;
        case 3:
            Y = a - b * c;
            break;
        case 7:
            Y = a * a + c;
            break;
        case 56:
            Y = b * c;
            break;
        default:
            Y = (a + b) * (a + b) * (a + b);
            break;
    }

    std::cout << Y;
    return 0;
}
