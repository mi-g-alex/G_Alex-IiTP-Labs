#include <iostream>
#include <cmath> //потому что корень 3ей степени надо(

long double abs_a(long double f) {
    return (f < 0 ? -f : f);
}

//итерационная формула герона
long double sqrt_a(long double num) {
    if (num == 0) return num;
    long double x = 1;
    while (abs_a(x * x - num) >= 1E-8) {
        x = ((num / x) + x) / 2;
    }
    return x;
}

long double a, b, c;

//ax^4 + bx^2 + c = 0
void first() {
    long double D = b * b - 4 * a * c;
    if (D < 0) {
        std::cout << "No Answer\n";
    } else {
        long double t1, t2;
        t1 = (-b + sqrt_a(D)) / (2 * a);
        t2 = (-b - sqrt_a(D)) / (2 * a);
        if (t1 >= 0) {
            if (t1 == 0) {
                std::cout << 0 << " ";
            } else {
                std::cout << sqrt_a(t1) << " " << -sqrt_a(t1) << " ";
            }
        }
        if (t2 > 0) {
            std::cout << sqrt_a(t2) << " " << -sqrt_a(t2);
        }

        if (t1 < 0 && t2 < 0) {
            std::cout << "No Answer\n";
        }
    }
}

void second() {
    if (b == 0) {
        b = c;
        c = a;
        first();
    } else {
        //at^2 + ct + c - 2a
        long double D = b * b - 4 * a * (c - 2 * a);
        if (D < 0) {
            std::cout << "No Answer\n";
        } else {
            long double t1, t2;
            t1 = (-b + sqrt_a(D)) / (2 * a);
            t2 = (-b - sqrt_a(D)) / (2 * a);
            long double D1 = t1 * t1 - 4;
            if (D1 >= 0) {
                long double t11, t12;
                t11 = (t1 + sqrt_a(D1)) / 2;
                t12 = (t1 - sqrt_a(D1)) / 2;
                if (t11 == t12) {
                    std::cout << t11 << " ";
                } else {
                    std::cout << t11 << " " << t12 << " ";
                }
            }
            long double D2 = t2 * t2 - 4;
            if (D2 >= 0) {
                long double t21, t22;
                t21 = (t2 + sqrt_a(D2)) / 2;
                t22 = (t2 - sqrt_a(D2)) / 2;

                if (t21 == t22) {
                    std::cout << t21 << " ";
                } else {
                    std::cout << t21 << " " << t22 << " ";
                }
            }
        }
    }
}


void third() {
    long double p, q, a1, b1;
    std::cout << "p, q\n";
    std::cin >> p >> q;
    long double Q = (p / 3) * (p / 3) * (p / 3) + (q / 2) * (q / 2);
    if (Q > 0) {
        a1 = -q / 2 + sqrt_a(Q);
        b1 = -q / 2 - sqrt_a(Q);
        a1 = std::cbrt(a1);
        b1 = std::cbrt(b1);
        std::cout << a1 + b1 << " ";
    }
    if (Q == 0) {
        a1 = -q / 2;
        a1 = std::cbrt(a1);
        std::cout << 2 * a1 << " " << -a1;
    }
    if (Q < 0) {
        std::cout <<
                  2 * sqrt_a(-p / 3) * cosl(acosl(-q / 2 * powl(3 / -p, 1.5)) / 3) << " " <<
                  2 * sqrt_a(-p / 3) * cosl(acosl(-q / 2 * powl(3 / -p, 1.5)) / 3 + 2 * M_PI / 3) << " " <<
                  2 * sqrt_a(-p / 3) * cosl(acosl(-q / 2 * powl(3 / -p, 1.5)) / 3 - 2 * M_PI / 3) << " ";
    }
}

int main() {
    int i;
    std::cout << "Select:\n1) ax^4 + bx^2 + c = 0\nor\n2) ax^4 + bx^3 + cx^2 + bx + a = 0\nor\n3) x^3 + px + q = 0\n";
    std::cin >> i;
    switch (i) {
        case 1:
            std::cout << "a, b, c\n";
            std::cin >> a >> b >> c;
            first();
            break;
        case 2:
            std::cout << "a, b, c\n";
            std::cin >> a >> b >> c;
            second();
            break;
        case 3:
            third();
            break;
        default:
            std::cout << "Wtf. 3, 2, 1...\nBoom!!!";
            break;
    }
    return 0;
}