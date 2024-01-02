#include <iostream>

long long **createDynArray(long long n, long long m) {
    auto **a = new long long *[n];
    for (long long i = 0; i < n; ++i) {
        a[i] = new long long[m];
    }

    return a;
}

void cinArray(long long **a, long long n, long long m, long long *k) {
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            if (i % 2 && a[i][j] % 2) (*k)++;
        }
    }
}

void fillArray(long long **a, long long *ansArr, long long n, long long m) {
    long long k = 0;
    for (int i = 1; i < m; i += 2) {
        for (int j = 0; j < n; j++) {
            if (a[j][i] % 2) ansArr[k++] = a[j][i];
        }
    }
}

void coutArr(long long *a, long long n) {
    for (long long j = 0; j < n; ++j) {
        std::cout << a[j] << "\t";
    }
}

long double findSum(const long long *a, long long n) {
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    return ((long double) sum / (long double) n);
}

long double forTest(long long n, long long m, long long **a) {
    long long k = 0;

    cinArray(a, n, m, &k);

    auto *ansArr = new long long[k];

    fillArray(a, ansArr, n, m);

    return (k ? findSum(ansArr, k) : 0);
}
