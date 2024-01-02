#include<iostream>
#include<vector>


int main() {
    long long n, m;
    std::cin >> n >> m;

    long long a[n + 2][m + 2];
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            if (i == 0) {
                if (j == 0) {
                    continue;
                } else a[i][j] = std::max(a[i][j - 1], a[i][j]);
            } else if (j == 0) {
                a[i][j] = std::max(a[i - 1][j], a[i][j]);
            } else {
                a[i][j] = std::max(a[i][j - 1], std::max(a[i][j], a[i - 1][j]));
            }
        }
    }

    for(long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++)
            std::cout << a[i][j] << " ";
        std::cout << "\n";
    }

}