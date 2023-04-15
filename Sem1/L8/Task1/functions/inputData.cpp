#include "../functions.h"
#include "../checkInput/checkInput.h"
#include <cstdio>

void inputNewStruct(long long start, long long num) {
    printf("Struct include:\n"
           "0. Number of workshop\n"
           "1. Name of Product\n"
           "2. Number of Products produced\n"
           "3. Weight of product\n"
           "4. Is product ready (0 - not completed. 1 - completed)\n\n");
    for (long long i = start; i < start + num; i++) {
        printf("Input struct %lld:\n0: ", i);
        a[i].numberOfWorkshop = checkInput(a[i].numberOfWorkshop);
        while(a[i].numberOfWorkshop < 0) {
            printf("Error\n");
            a[i].numberOfWorkshop = checkInput(a[i].numberOfWorkshop);
        }

        printf("1: ");
        std::scanf("%s", a[i].nameOfProduct);

        printf("2: ");
        a[i].numberOfProduct = checkInput(a[i].numberOfProduct);
        while(a[i].numberOfProduct <= 0) {
            printf("Error\n");
            a[i].numberOfProduct = checkInput(a[i].numberOfProduct);
        }


        printf("3: ");
        a[i].weightOfOneProduct = checkInput(a[i].weightOfOneProduct);
        while(a[i].weightOfOneProduct <= 0) {
            printf("Error\n");
            a[i].weightOfOneProduct = checkInput(a[i].weightOfOneProduct);
        }

        printf("4: ");
        while(true) {
            long long x = checkInput(x);
            if(x == 0 || x == 1) {
                a[i].statusIsCreated = (bool)x;
                break;
            } else {
                printf("Error\n");
            }
        }

        a[i].weightOfAllProducts = a[i].weightOfOneProduct * a[i].numberOfProduct;

    }
}

void inputWhile(const std::string& whileWhat, long long *sizeOfArray) {
    printf("Struct include:\n0. Number of workshop\n1. Name of Product\n2. Number of Products produced\n3. Weight of product\n4. Is product ready (0 - not completed. 1 - completed)\n\n");
    do {
        (*sizeOfArray)++;
        resizeArray(*sizeOfArray);

        printf("Input struct %lld:\n0: ", *sizeOfArray - 1);
        a[*sizeOfArray - 1].numberOfWorkshop = checkInput(a[*sizeOfArray - 1].numberOfWorkshop);
        while(a[*sizeOfArray - 1].numberOfWorkshop < 0) {
            printf("Error\n0: ");
            a[*sizeOfArray - 1].numberOfWorkshop = checkInput(a[*sizeOfArray - 1].numberOfWorkshop);
        }

        printf("1: ");
        std::scanf("%s", a[*sizeOfArray - 1].nameOfProduct);

        printf("2: ");
        a[*sizeOfArray - 1].numberOfProduct = checkInput(a[*sizeOfArray - 1].numberOfProduct);
        while(a[*sizeOfArray - 1].numberOfProduct <= 0) {
            printf("Error\n2: ");
            a[*sizeOfArray - 1].numberOfProduct = checkInput(a[*sizeOfArray - 1].numberOfProduct);
        }

        printf("3: ");
        a[*sizeOfArray - 1].weightOfOneProduct = checkInput(a[*sizeOfArray - 1].weightOfOneProduct);
        while(a[*sizeOfArray - 1].weightOfOneProduct <= 0) {
            printf("Error\n3: ");
            a[*sizeOfArray - 1].weightOfOneProduct = checkInput(a[*sizeOfArray - 1].weightOfOneProduct);
        }


        while(true) {
            printf("4: ");
            long long x = checkInput(x);
            if(x == 0 || x == 1) {
                a[*sizeOfArray - 1].statusIsCreated = (bool)x;
                break;
            } else {
                printf("Error\n");
            }
        }
    } while(a[*sizeOfArray - 1].nameOfProduct != whileWhat);
}