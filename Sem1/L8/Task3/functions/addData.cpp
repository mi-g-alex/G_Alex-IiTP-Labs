#include "../functions.h"

void inputN(long long start, long long num) {
    std::string s;
    std::cout << "Input:\n"
                 "1. Workshop\n"
                 "2. Name\n"
                 "3. Number\n\n";

    fseek(f, sizeof(long long) + start * (long long) sizeof(db[0]), SEEK_SET);
    for (long long i = start; i < start + num; i++) {
        std::cout << "1: ";
        db[i].workshop = checkInput(db[i].workshop);

        std::cout << "2: ";
        std::cin >> db[i].name;

        std::cout << "3: ";
        db[i].number = checkInput(db[i].number);
        fwrite(&db[i], sizeof(db[i]), 1, f);
    }
}