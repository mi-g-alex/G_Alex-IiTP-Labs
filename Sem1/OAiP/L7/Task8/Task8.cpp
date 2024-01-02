#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long x;
    std::cin >> x;
    std::vector <long long> a;
    while(x) { // O(log(n))
        a.push_back(x % 3);
        x /= 3;
    }
    for(long long i = 0; i < a.size() - 1; i++) { // O(n)
        if(a[i] <= 0) {
            a[i] += 3;
            a[i + 1]--;
            if(a[i + 1] == 0 && i == a.size() - 2) a.erase(a.end() - 1);
        }
    }
    std::reverse(a.begin(), a.end());
    for(auto i : a) { // O(n)
        std::cout << i;
    }

}