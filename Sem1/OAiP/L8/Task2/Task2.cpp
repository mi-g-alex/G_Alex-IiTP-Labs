#include <string>
#include <iostream>

void start();

struct DB {
    long long regNumber;
    std::string author;
    std::string name;
    long long year;
    std::string publishHouse;
    long long numberOfBooks;
};

DB *db = nullptr;

int main() {
    start();
}