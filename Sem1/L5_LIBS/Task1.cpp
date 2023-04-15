void fillArrayByRules(long long **a, long long n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(i <= 5) a[i - 1][j - 1] = 2 * i * j * j - 2 * j;
            else a[i - 1][j - 1] = 3 * i * j - 3;
        }
    }
}

void transArray(long long **a, long long **b, long long n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[j][i];
        }
    }
}

long long calcSumLine(long long **a, long long num, long long n) {
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans+= a[num][i];
    }

    return ans;
}

long long calcSumColumn(long long **a, long long num, long long n) {
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans+= a[i][num];
    }

    return ans;
}
