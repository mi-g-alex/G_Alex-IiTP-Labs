#include <iostream>
#include <cmath>

void v1() {

    double D, x;
    std::cin >> D >> x;

    double b = x + D;
    double A = D * x / b;

    if (D * D * D + (A + D - (x + D)) == 0) {
        std::cout << "Ups. x / 0 == error\n";
    } else {
        double S = (A * A + b * cos(x)) / (D * D * D + (A + D - (x + D)));
        std::cout << S << "\n";
    }
}

void v2() {

    double x, p, K, C, D;
    std::cin >> C >> D >> K >> p >> x;

    double A = x + sin(p);
    double B = exp(K);

    if (A * B == 0) {
        std::cout << "Ups. x / 0 == error\n";
    } else {
        double U = 1 + K * K / (2.0 * A * B) - B + D * C;
        std::cout << U << "\n";
    }
}

void v3() {

    double x, p, n, K, D;
    std::cin >> x >> p >> n >> K >> D;

    double B = cos(x);
    double C = p - n;

    if (K * D == 0) {
        std::cout << "Ups. x / 0 == error";
    } else {
        double Q = B * B / (K * D) + B * C * C * C;
        std::cout << Q;
    }

}

void v4() {

    double x, y, z, C, D, K;
    std::cin >> x >> y >> z >> C >> D >> K;

    double A = x - y;

    if (z < 0) {
        std::cout << "Ups. sqrt(" << z << ") == error\n";
    } else {
        double B = sqrt(z);
        if (K - C * D == 0) {
            std::cout << "Ups. x / 0 == error\n";
        } else {
            double T = cos(x) + A * A / (K - C * D) - B;
            std::cout << T << "\n";
        }
    }

}

void v5() {

    double x, n, m, K;
    std::cin >> x >> n >> m >> K;

    double A = std::abs(n + m);
    double D = tan(x);

    if (A == 0) {
        std::cout << "Ups. x / 0 == error\n";
    } else {
        double U = 1.29 + K / A + D * D;
        std::cout << U << "\n";
    }
}

void v6() {

    double x, y, C, K;
    std::cin >> x >> y >> C >> K;

    double A = x + y;
    double D = std::abs(C - A);

    if (C * K == 0) {
        std::cout << "Ups. x / 0 == error\n";
    } else {
        double S = 10.1 + A / C + D / (K * K);
        std::cout << S << "\n";
    }
}

void v7() {

    double x, p, h, K, C, D;
    std::cin >> x >> p >> h >> K >> C >> D;

    double A = x - p;
    if (h <= 0) {
        std::cout << "Ups. log(" << h << ") == error\n";
    } else {
        double B = log(h);

        if (K * C * D == 0) {
            std::cout << "Ups. x / 0 == error\n";
        } else {
            double Y = 0.78 * B + (A * A * A) / (K * C * D);
            std::cout << Y << "\n";
        }
    }
}

void v8() {

    double x, d, C, K;
    std::cin >> x >> d >> C >> K;
    if (x <= 0) {
        std::cout << "Ups. log10(" << x << ") == error\n";
    } else {
        double A = log10(x);
        double B = x + exp(d);

        if (K == 0) {
            std::cout << "Ups. x / 0 == error\n";
        } else {
            double Y = (A + B) - (C * C) / K;
            std::cout << Y << "\n";
        }
    }
}

void v9() {

    double x, p, z, K, C, D;
    std::cin >> x >> p >> z >> K >> C >> D;

    double A = sin(x) - z;
    double B = std::abs(p - x);

    if (C * D == 0) {
        std::cout << "Ups. x / 0 == error\n";
    } else {
        double Y = (A + B) * (A + B) - K / (C * D);
        std::cout << Y << "\n";
    }
}

void v10() {
    double x, k, z, D, C;
    std::cin >> x >> k >> z >> D >> C;
    if (x <= 0) {
        std::cout << "Ups. log(" << x << ") == error.\n";
    } else {
        double A = log(x) - k;

        if (z < 0) {
            std::cout << "Ups. sqrt(" << z << ") == error";
        } else {
            double B = sqrt(z);

            if (A == 0) {
                std::cout << "Ups. x / 0 == error\n";
            } else {
                double Y = D * D + C * C / (0.75 * A) + B;
                std::cout << Y << "\n";
            }
        }

    }
}

int main() {
    int a;
    std::cin >> a;
    switch (a) {
        case 1 :
            v1();
            break;
        case 2:
            v2();
            break;
        case 3:
            v3();
            break;
        case 4:
            v4();
            break;
        case 5:
            v5();
            break;
        case 6:
            v6();
            break;
        case 7:
            v7();
            break;
        case 8:
            v8();
            break;
        case 9:
            v9();
            break;
        case 10:
            v10();
            break;
        default:
            std::cout << "Wtf. Pls write number from 1 to 10";
            break;
    }

    return 0;
}