#include "../functions.h"

DB *x;

void qSort(long long b, long long e) {
    long long l = b, r = e;
    long long mid = (l + r) / 2;
    while(l <= r) {
        std::string s1 = x[l].author;
        std::string s2 = x[mid].author;
        std::string s3 = x[r].author;
        while(s1 < s2) l++;
        while(s3 > s2) r--;

        if(l <= r) std::swap(x[l++], x[r--]);
    }

    if(b < r) qSort(b, r);
    if(l < e) qSort(l, e);
}

void sortDBAndOutput(long long sizeOfArray, long long year) {
    x = (DB*)calloc(sizeOfArray, sizeof(DB));
    for(int i = 0; i < sizeOfArray; i++) {
        x[i] = db[i];
    }
    qSort(0, sizeOfArray - 1);
    for(long long i = 0; i < sizeOfArray; i++) {
        if(db[i].year > year) {
            exportData(i, x[i]);
            std::cout
                << "\nRegNumber: " << x[i].regNumber
                << "\nAuthor: " << x[i].author
                << "\nName: " << x[i].name
                << "\nYear: " << x[i].year
                << "\nPublic House: " << x[i].publishHouse
                << "\nNumber of Books: " << x[i].numberOfBooks << "\n\n";
        }
    }
}