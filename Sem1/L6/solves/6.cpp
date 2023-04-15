#include <iostream>
#include <map>

std::map <char, int> a;

void toDoTask6() {
    std::string s1;
    std::cin >> s1;
    unsigned long long sum = 1;
    for(int i = 1; i <= s1.size(); i++) sum *= i;
    for(char i : s1) sum /= ++a[i];
    std::cout << sum;
}