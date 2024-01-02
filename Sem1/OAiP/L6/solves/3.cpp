#include <iostream>

bool isPol (const char *a, int n) {
    for (int i = 0; i < n / 2; ++i) {
        if(a[i] != a[n - i - 1]) return false;
     }
    return true;
}

bool toDoTask3(char **a,long long *num, long long line) {
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < num[i]; j++) {
            std::cout << a[i][j];
        }
        std::cout << " " << (isPol(a[i],num[i]) ? "YES" : "NO") << "\n";
    }
}