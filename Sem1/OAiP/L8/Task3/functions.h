#include "functions/DB.h"
#include <string>
#include <iostream>
#include "checkInput/checkInput.h"

extern DB *db;
extern FILE *f;

void resizeArray(long long newSize);
void importData(long long *sizeOfArray);
void exportData(long long i, DB x);
void outputStruct(long long start, long long num);
void inputN(long long start, long long num);
void deleteData(long long *sizeOfArray);
void sortDBAndOutput(long long sizeOfArray, long long year);