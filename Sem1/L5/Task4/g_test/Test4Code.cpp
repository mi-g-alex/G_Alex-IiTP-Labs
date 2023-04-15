#include <iostream>

void cinArray(long double **a, long long n, long long m, long long *k) {
//    std::cout << "Введите " << n * m << " элементов\n";
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
//            a[i][j] = checkInput(a[i][j]);
            if (a[i][j] == 0) (*k)++;
        }
    }
}

void find0(long double **a, long double **arrayOf0, long long n, long long m) {
    long long k = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                arrayOf0[k][0] = i;
                arrayOf0[k++][1] = j;
            }
        }
    }
}

void replaceArray(long double **a, long long n, long long m) {
    for (long long i = 0; i < n / 2; ++i) {
        for (long long j = 0; j < m; ++j) {
            std::swap(a[i][j], a[n - i - 1][m - j - 1]);
        }
    }
    if(n % 2)
        for (long long i = 0; i < m / 2; ++i) {
            std::swap(a[n / 2][i], a[n / 2][m - i - 1]);
        }
}


long long forTest(long long n, long long m, long double **a) {
    long long k = 0;
    cinArray(a, n, m, &k);
    return k;
}
