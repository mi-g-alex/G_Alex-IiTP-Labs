#include<iostream>
#include <cmath>

#include <vector>

int main() {

    //long double a[10000];
    long double result[10000];
    std::vector <int> a;

    int value = 0, n = 0;
    while(std::cin >> value)
    {
        a.push_back(value);
        n+=1;
    }
    long long mini, maxi;
    mini = 0;
    maxi = 0;
    for (int i = 1; i < n; ++i) {
        if (a[mini] > a[i]) mini = i;
        if (a[maxi] < a[i]) maxi = i;
    }

    for (long long i = std::min(mini, maxi) + 1; i < std::max(mini, maxi); i++) {
        a[i] = 0;
    }

    long long numberOf0 = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i] == 0) numberOf0++;
    }

    long long q = 0;
    if(numberOf0 * 2 > n) {
        for (int i = 0; i < n; ++i) {
            if(a[i] != 0) result[q++] = a[i];
        }
    } else {
        for (int i = 0; i < n; ++i) {
            result[q++] = a[i];
        }
    }


    for (int i = 0; i < q; ++i) {
        std::cout << result[i] << " ";
    }
}