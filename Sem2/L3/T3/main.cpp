#include <iostream>
#include "vector/vector.h"
#include "vector/vector.cpp"


void qsort(MyVector<int> &arr, int b, int e) {
    int l = b, r = e;
    int piv = arr[(l + r) / 2];
    while (l <= r) {
        while (arr[l] < piv)
            l++;
        while (arr[r] > piv)
            r--;
        if (l <= r)
            std::swap(arr[l++], arr[r--]);
    }
    if (b < r)
        qsort(arr, b, r);
    if (e > l)
        qsort(arr, l, e);
}

int main() {
    MyVector<int> a, b;
    for(int i = 0; i < arc4random() % 150 + 20; i++) {
        a.push_back((int)arc4random() % 13);
    }

    int q = 0;
    for (auto i: a) {
        std::cout << i << " ";
        if(++q % 3 == 0) std::cout << "|";
    }
    std::cout << "\n";
    int i = 0;
    for (; i < a.size(); i += 3) {
        if (i + 3 < a.size()) {
            qsort(a, i, i + 2);
            b.push_back(a[i + 1]);
        }
    }

    if (i == a.size() + 1) {
        b.push_back((a[i - 3] + a[i - 2]) / 2);
    }

    if (i == a.size() + 2) {
        b.push_back(a[i - 3]);
    }
    for (auto d: b) std::cout << d << " ";

}
