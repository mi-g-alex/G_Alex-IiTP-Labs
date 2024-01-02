// OK 4.3.4
#include <iostream>

int main(){
    long long a, b;
    long double x, y, z, k;
    std::cin >> a >> b >> x >> y >> z >> k;
    if (a == b) {
        a = 0;
        b = 0;
    } else if (a > b) {
        b = 0;
    } else {
        a = 0;
    }

    if (x > y && x > z) {
        x -= k;
    } else if (y > x && y > z) {
        y -= k;
    } else {
        z -= k;
    }

    std::cout << a << " " << b << "\n" << x << " " << y << " " << z;

}