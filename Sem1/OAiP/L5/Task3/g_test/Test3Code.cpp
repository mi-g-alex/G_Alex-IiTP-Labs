#include <iostream>

void fillArr(long long **a, long long *ans, long long n, long long *length) {
    for (long long i = 0; i < n; ++i) {
        if (a[i][i] % 2 == 0)
            ans[(*length)++] = a[i][i];
    }
}


long long findMultiply(const long long *a, long long length) {
    long long ans = 1;

    for (long long i = 0; i < length; ++i) {
        ans *= a[i];
    }

    return ans;
}

long long forTest(long long n, long long k, long long **a) {
    long long length = 0;
    auto *ansArr = new long long[std::max(n, k)];
    fillArr(a, ansArr, std::min(n, k), &length);
    return (length ? findMultiply(ansArr, length) : 0);
}

