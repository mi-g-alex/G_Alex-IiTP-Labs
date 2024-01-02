#include <fstream>
#include "../functions.h"

void importData(long long *sizeOfArray) {
    *sizeOfArray = 0;
    std::ifstream in;
    in.open("../Task3/files/DB.in");
    while (in) {
        std::string s;
        char c = '1';

        while (in.peek() == '\n') in.get(c);
        if (in.peek() < '0' || in.peek() > '9') break;

        (*sizeOfArray)++;
        fseek(f, 0, SEEK_SET);
        fwrite(&(*sizeOfArray), sizeof(*sizeOfArray), 1, f);
        fseek(f, (long long) (sizeof(long long) + (*sizeOfArray - 1) * sizeof(DB)), SEEK_SET);

        resizeArray(*sizeOfArray);
        in >> db[*sizeOfArray - 1].workshop;

        in.get(c);
        while (in.peek() == '\n') in.get(c);
        in >>db[*sizeOfArray - 1].name;

        in >> db[*sizeOfArray - 1].number;
        fwrite(&db[*sizeOfArray - 1], (long long) sizeof(DB), 1, f);
    }
    in.close();
}