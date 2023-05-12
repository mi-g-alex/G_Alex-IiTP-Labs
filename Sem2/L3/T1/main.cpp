#include <iostream>
#include "vector/vector.h"
#include "vector/vector.cpp"
#include "vector/pair.h"


int main() {
    MyVector<MyVector<MyVector<pair<pair<std::string, std::string>, pair<std::string, std::string>>>>> a;
    a.push_back({{{{"2", "5"}, {"3", "5"}}}});

    for (auto i: a)
        for (auto j: i)
            for (const auto& k: j)
                std::cout << k.first.first << k.first.second << k.second.first << k.second.second;

}

