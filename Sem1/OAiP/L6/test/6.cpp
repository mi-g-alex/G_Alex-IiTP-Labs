#include <iostream>
#include <map>


long long toDoTask6(std::string& s1) {
    std::map <char, int> a;
    unsigned long long sum = 1;
    for(int i = 1; i <= s1.size(); i++) sum *= i;
    for(char i : s1) sum /= ++a[i];
    return sum;
}