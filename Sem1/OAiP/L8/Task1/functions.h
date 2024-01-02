#pragma once

#ifndef LAB8_FUNCTIONS_H
#define LAB8_FUNCTIONS_H

#include <string>

//Main
struct Data {
    long long numberOfWorkshop;
    char nameOfProduct[1000];
    long long numberOfProduct;
    long double weightOfOneProduct;
    long double weightOfAllProducts;
    bool statusIsCreated;
};

extern Data *a;


//inputData
void inputNewStruct(long long start, long long num);
void inputWhile(const std::string& whileWhat, long long *sizeOfArray);

//outputData
void outputStruct(long long start, long long num);

//resizeArray
void resizeArray(long long newSize);

//searchAndDelete
void searchAndDelete(long long *sizeOfArray);

//searchAndEdit
void searchAndEdit(const long long *sizeOfArray);

//searchAndOutput
void searchAndOutput(const long long *sizeOfArray);

//sort
void sortArray(long long sizeOfArray);

#endif //LAB8_FUNCTIONS_H
