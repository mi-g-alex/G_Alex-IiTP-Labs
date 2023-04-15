#include <iostream>

int main() {
    int h1, h2, m1, m2, dm, h0, m0;

    std::cin >> h1 >> m1 >> h2 >> m2;
    if (h1 > 23 || h1 < 0
     || m1 > 59 || m1 < 0
     || h2 > 23 || h2 < 0
     || m2 > 59 || m2 < 0) {

        std::cout << "input format error:\n0 <= h1, h2 <= 23\n0 <= m1, m2 <= 59";
        return 0;
    }
    m1 = h1 * 60 + m1;
    m2 = h2 * 60 + m2;

    dm = m2 - m1;

    if (dm <= 0) dm += 1440;

    h0 = dm / 60;
    m0 = dm % 60;
    if (h0 == 24) {
        std::cout << "1d";
    } else {
        if (h0) std::cout << h0 << "h ";
        if (m0) std::cout << m0 << "m";
    }

    return 0;
}

