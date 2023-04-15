#include <bits/stdc++.h>

using namespace std;

bool a[10];

int main() {
    string s;
    int q;
    cin >> s >> q;
    long long ans = 0;
    for(long long i = 0; i < s.length(); i++){
        if(a[s[i] - '0'] == false) ans++;
        a[s[i] - '0'] = true;
    }

    cout << ans << "\n";

    for(long long i = s.length() - 1; i >= 0; i--) {
        if(s[i] == s[q - 1]) cout << s.length() - 1 - i << " ";
    }


    return 0;
}