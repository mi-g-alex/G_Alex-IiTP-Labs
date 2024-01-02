// OK | была на степике, а теперь нет...
//          A
//          .
//         / \
//        _____
//       B     C

#include <iostream>
#include <cmath>

const float PI = 3.1415929;

double findMedian(double left, double right, double down) {
    return 0.5 * sqrt(2 * (left * left + right * right) - down * down);
}

double findBisector(double left, double right, double down) {
    return sqrt(left * right * (left + right - down) * (left + right + down)) / (right + left);
}

double findRadians(double left, double right, double down) {
    // c^2 = a^2 + b^2 - 2ab*cos(c)
    return acos((left * left + right * right - down * down) / (2 * left * right));
}

int main() {
    double x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // вычисление сторон
    double ab = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));    //AB
    double bc = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));    //BC
    double ca = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));    //CA
    std::cout << "AB " << ab << "\tBC " << bc << "\tCA " << ca << "\n";

    // площадь и полупериметр
    double p = (ab + bc + ca) / 2;
    double S = sqrt(p * (p - ab) * (p - bc) * (p - ca));

    // высоты
    double ha = 2 * S / bc;
    double hb = 2 * S / ca;
    double hc = 2 * S / ab;
    std::cout << "AH " << ha << "\tBH " << hb << "\tCH " << hc << "\n";

    // медианы
    double ma = findMedian(ca, ab, bc);
    double mb = findMedian(bc, ab, ca);
    double mc = findMedian(ca, bc, ab);
    std::cout << "AM " << ma << "\tBM " << mb << "\tCM " << mc << "\n";

    // биссектрисы
    double la = findBisector(ab, ca, bc);
    double lb = findBisector(ab, bc, ca);
    double lc = findBisector(ca, bc, ab);
    std::cout << "AL " << la << "\tBL " << lb << "\tCL " << lc << "\n";

    // значения углов
    double ra = findRadians(ab, ca, bc);
    double rb = findRadians(ab, bc, ca);
    double rc = findRadians(ca, bc, ab);
    std::cout << "rad A " << ra << "\trad B " << rb << "\t rad C " << rc << "\n";
    std::cout << "deg A " << ra / PI * 180 << "\tdeg B " << rb / PI * 180 << "\tdeg C " << rc / PI * 180 << "\n";


    // радиусы окружностей
    double ri = S / p;
    double ro = ab * bc * ca / (4 * S);
    std::cout << "Radius inscribed " << ri << "\nRadius circumscribed " << ro << "\n";

    // площади и длины окружностей
    double li, lo, si, so;
    li = 2 * PI * ri;
    lo = 2 * PI * ro;
    si = PI * ri * ri;
    so = PI * ro * ro;
    std::cout << "Inscribed: L - " << li << "\t S - " << si << "\n";
    std::cout << "Circumscribed: L - " << lo << "\t S - " << so << "\n";

    //периметр и площадь
    double P = p * 2;
    std::cout << "P " << P << "\n";

    double s1 = bc * ha / 2;
    double s2 = sqrt(p * (p - ab) * (p - bc) * (p - ca));
    double s3 = 0.5 * ab * ca * sin(ra);
    std::cout << "S " << s1 << " " << s2 << " " << s3;

    return 0;
}

