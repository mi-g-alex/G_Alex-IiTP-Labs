#include <fstream>
#include "../functions.h"

void importData(long long *sizeOfArray) {
    *sizeOfArray = 0;
    resizeArray(1);
    std::ifstream in;
    in.open("../Task2/files/DB.in");
    while (in) {
        std::string s;
        char c = '1';

        while(in.peek() == '\n') in.get(c);
        if(in.peek() < '0' || in.peek() > '9') break;

        ///resize Array + 1
        (*sizeOfArray)++;
        resizeArray(*sizeOfArray);

        ///Input register number
        in >> db[*sizeOfArray - 1].regNumber;

        ///Input author
        in.get(c);
        while(in.peek() == '\n') in.get(c);
        in.getline(db[*sizeOfArray - 1].author, 1000, '\n');

        ///Input name
        in.getline(db[*sizeOfArray - 1].name, 1000, '\n');

        ///Input year
        in >> db[*sizeOfArray - 1].year;

        ///Input publish house
        in.get(c);
        while(in.peek() == '\n') in.get(c);
        in.getline(db[*sizeOfArray - 1].publishHouse, 1000, '\n');

        ///Input number of books
        in >> db[*sizeOfArray - 1].numberOfBooks;

    }

    in.close();
}