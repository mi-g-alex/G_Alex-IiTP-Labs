/*
#include "../functions.h"
#include "../../checkInput/checkInput.h"

void searchNumberOfWorkshop(long long sizeOfArray);

void searchNameOfProduct(long long sizeOfArray);

void searchNumberOfProduct(long long sizeOfArray);

void searchWeightOfProduct(long long sizeOfArray);

void searchStatusIsCreated(long long sizeOfArray);

void searchAndOutput(const long long *sizeOfArray) {
    printf("What you want to search?\n0. Nothing\n1. Structures with workshop number X\n2. Structures with product Name \"S\"\n3. Structures with number of product X\n4. Structures with weight X\n5. Structures with status Completed or Not\n");
    long long x = checkInput(x);
    while (x != 0 && x != 1 && x != 2 && x != 3 && x != 4 && x != 5) {
        printf("Error");
        x = checkInput(x);
    }

    switch (x) {
        case 0:
            return;
        case 1:
            searchNumberOfWorkshop(*sizeOfArray);
            break;
        case 2:
            searchNameOfProduct(*sizeOfArray);
            break;
        case 3:
            searchNumberOfProduct(*sizeOfArray);
            break;
        case 4:
            searchWeightOfProduct(*sizeOfArray);
            break;
        case 5:
            searchStatusIsCreated(*sizeOfArray);
            break;
    }
}

void searchNumberOfWorkshop(long long sizeOfArray) {
    printf("Input X:\n");
    long long x = checkInput(x);
    while(x < 0) {
        printf("Error\n");
        x = checkInput(x);
    }

    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].numberOfWorkshop == x) {
            outputStruct(i, 1);
        }
    }
}

void searchNameOfProduct(long long sizeOfArray) {
    printf("Input S:\n");

    char buf[10000] = "";
    std::scanf("%s", buf);
    std::string s = buf;

    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].nameOfProduct == s) {
            outputStruct(i, 1);
        }
    }
}

void searchNumberOfProduct(long long sizeOfArray) {
    printf("Input X:\n");
    long long x = checkInput(x);
    while(x < 0) {
        printf("Error\n");
        x = checkInput(x);
    }
    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].numberOfProduct == x) {
            outputStruct(i, 1);
        }
    }
}

void searchWeightOfProduct(long long sizeOfArray) {
    printf("Input X:\n");
    long double x = checkInput(x);
    while(x < 0) {
        printf("Error\n");
        x = checkInput(x);
    }
    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].weightOfOneProduct == x) {
            outputStruct(i, 1);
        }
    }
}

void searchStatusIsCreated(long long sizeOfArray) {
    printf("Input status (0 - Not Completed, 1 - Completed:\n");
    long long x = checkInput(x);

    while(x != 0 && x != 1) {
        printf("Error");
        x = checkInput(x);
    }

    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].statusIsCreated == x) {
            outputStruct(i, 1);
        }
    }
}*/

#include "../functions.h"
#include "../checkInput/checkInput.h"

void searchAndOutput(const long long *sizeOfArray) {
    printf("Input Number of Workshop:\n");
    long long x = checkInput(x);
    while(x < 0) {
        printf("Error\n");
        x = checkInput(x);
    }

    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].numberOfWorkshop == x) {
            printf("\nNumber of \"%s\": %lld", a[i].nameOfProduct, a[i].numberOfProduct);
        }
    }
}