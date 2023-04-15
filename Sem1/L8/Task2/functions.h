#pragma once

#ifndef LAB8_FUNCTIONS_H
#define LAB8_FUNCTIONS_H

#include <string>
#include <iostream>

struct DB {
    long long regNumber;
    char author[1000];
    char name[1000];
    long long year;
    char publishHouse[1000];
    long long numberOfBooks;
};

extern DB *db;

//importDataFromFile
void importData(long long *sizeOfArray);

//viewData
void outputStruct(long long start, long long num);

//deleteData
void deleteData(long long *sizeOfArray);

//exportDataFromFile
void exportData(long long i, DB x);

//resize
void resizeArray(long long newSize);

//addData
void inputN(long long start, long long num);
void outputStruct(long long start, long long num);

//sortDB
void sortDBAndOutput(long long sizeOfArray, long long year);



#endif //LAB8_FUNCTIONS_H
