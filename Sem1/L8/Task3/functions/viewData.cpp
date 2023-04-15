#include "../functions.h"
#include <iostream>

void outputStruct(long long start, long long num) {
    DB *x = new DB[1];
    std::cout << "Format: NameOfDara inArray | inBunFile\n\n";
    for (long long i = start; i < start + num; i++) {
        fseek(f, (long long)sizeof(start) + i * (long long)sizeof(DB), SEEK_SET);
        fread(&x[0], (long long)sizeof(DB), 1, f);
        std::cout << "Struct " << i << ":"
            << "\nWorkshop: " << db[i].workshop << " | " << x[0].workshop
            << "\nName: " << db[i].name << " | " << x[0].name
            << "\nNumber: " << db[i].number << " | " << x[0].number << "\n\n";
    }
}