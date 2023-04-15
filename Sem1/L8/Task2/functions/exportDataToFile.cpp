#include <fstream>
#include "../functions.h"

std::ofstream out("../Task2/files/DB.out");

void exportData(long long i, DB x) {
    out << "Struct " << i << ":"
        << "\nRegNumber: " << x.regNumber
        << "\nAuthor: " << x.author
        << "\nName: " << x.name
        << "\nYear: " << x.year
        << "\nPublic House: " << x.publishHouse
        << "\nNumber of Books: " << x.numberOfBooks << "\n\n";
}
