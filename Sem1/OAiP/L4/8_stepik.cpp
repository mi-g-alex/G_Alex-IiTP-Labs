#include<iostream>

int main() {
    long long n, m;
    std::cin >> n;
    long double a[100][100], b[100][100], c[100][100];
    bool was = false;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        m = 0;
        do {
            std::cin >> value;
            a[i][m] = value;
            m++;

        } while(std::cin.peek() == ' ');
        was = true;
    }

    std::cin.clear();
    while(std::cin.get() != '\n');

    std::cin >> m;


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> b[i][j];
        }
    }
    long long ia, ib;
    for (ia = 0; ia < n; ia++)
        for (ib = 0; ib < n; ib++) {
            long double sum = 0;
            for (long long i = 0; i < m; i++)
            {
                sum += a[ia][i] * b[i][ib];
            }
            c[ia][ib] = sum;
        }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << c[i][j];
            if(j != n - 1) std::cout << " ";
        }
        std::cout << "\n";
    }

}
