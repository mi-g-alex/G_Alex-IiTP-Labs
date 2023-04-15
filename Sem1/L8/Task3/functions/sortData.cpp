#include "../functions.h"

DB *x;

void qSort(long long b, long long e) {
    long long l = b, r = e;
    long long mid = (l + r) / 2;
    while(l <= r) {
        while(x[l].number < x[mid].number) l++;
        while(x[r].number > x[mid].number) r--;

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
    for(long long i = sizeOfArray - 1; i >= 0; i--) {
        if(x[i].workshop == year) {
         //   exportData(i, x[i]);
            std::cout << "Struct " << i << ":"
                      << "\nWorkshop: " << x[i].workshop
                      << "\nName: " << x[i].name
                      << "\nNumber: " << x[i].number << "\n\n";
        }
    }
}