#include<iostream>
#include<vector>


int main() {
    long long n, m;
    std::cin >> n >> m;
    long long a[n + 2][m + 2];
    for (long long i = 0; i < n + 2; i++) {
        for (long long j = 0; j < m + 2; j++) {
            a[i][j] = INT64_MAX;
        }
    }

    for (long long i = 1; i < n + 1; i++) {
        for (long long j = 1; j < m + 1; j++) {
            std::cin >> a[i][j];
        }
    }
    long long ans = 0;
    for (long long i = 1; i < n + 1; i++) {
        for (long long j = 1; j < m + 1; j++) {
            ans += (a[i][j] < std::min(std::min(a[i][j + 1], a[i - 1][j]), std::min(a[i + 1][j], a[i][j - 1])));
        }
    }

    std::cout << ans;

}