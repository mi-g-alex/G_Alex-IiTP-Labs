#include <iostream>
#include <regex>
#include "MyString.h"
#include "MyString.cpp"

int main() {
    MyString s = "1hello1";
    std::regex pattern("hello");
    bool match = std::regex_search(s.data(), pattern);
    std::cout << match;

    return 0;
}