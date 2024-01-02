#include "../functions.h"
#include <iostream>

void outputStruct(long long start, long long num) {
    for (long long i = start; i < start + num; i++) {
        std::cout << "Struct " << i << ":"
            << "\nRegNumber: " << db[i].regNumber
            << "\nAuthor: " << db[i].author
            << "\nName: " << db[i].name
            << "\nYear: " << db[i].year
            << "\nPublic House: " << db[i].publishHouse
            << "\nNumber of Books: " << db[i].numberOfBooks << "\n\n";
    }
}