#include "../functions.h"
#include "../checkInput/checkInput.h"

void inputN(long long start, long long num) {
    std::string s;
    std::cout << "Input:\n"
                 "1. Reg Number\n"
                 "2. Author\n"
                 "3. Name\n"
                 "4. Year\n"
                 "5. Public House\n"
                 "6. Number of books\n\n";

    for(long long i = start; i < start + num; i++) {
        std::cout << "Struct " << i << ":\n";
        std::cout << "1: ";
        db[i].regNumber = checkInput(db[i].regNumber);

        std::cout << "2: ";
        std::cin.getline(db[i].author, 1000, '\n');

        std::cout << "3: ";
        std::cin.getline(db[i].name, 1000, '\n');

        std::cout << "4: ";
        db[i].year = checkInput(db[i].year);

        std::cout << "5: ";
        std::cin.getline(db[i].publishHouse, 1000, '\n');

        std::cout << "6: ";
        db[i].numberOfBooks = checkInput(db[i].numberOfBooks);
    }
}