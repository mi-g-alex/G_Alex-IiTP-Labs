#include <bits/stdc++.h>

using namespace std;

int first[1000], second[1000], ans[1000], n = 999;

void sum(int d) {
    for (int i = 999; i > n; i--) {
        ans[i - d] += first[i];
        int k = 0;
        while (ans[i - d -k] > 9) {
            ans[i - k - d - 1] += ans[i - k - d] / 10;
            ans[i - k - d] %= 10;
            k++;
        }
    }
}

int main() {
    long long x;
    cin >> x;
    ans[999] = 1;
    long long y = x - 1;
    x % 2 ? y /= 2 : x /= 2;
    int m = 999;
    while (x) {
        first[n--] = x % 10;
        x /= 10;
    }

    while (y) {
        second[m--] = y % 10;
        y /= 10;
    }
    for (int i = 999; i > m; i--) {
        for (int j = 0; j < second[i]; ++j) {
            sum(999 - i);
        }
    }

    int k = 0;
    while(!ans[k++]);
    for (k = k - 1; k < 1000; ++k) {
        cout << ans[k];
    }

}