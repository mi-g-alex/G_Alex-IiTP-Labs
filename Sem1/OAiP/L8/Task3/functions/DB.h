#ifndef LAB8_DB_H
#define LAB8_DB_H


#include <string>

class DB {
public:
    long long workshop;
    union {
        long long number;
    };
    char name[100];
};


#endif //LAB8_DB_H
