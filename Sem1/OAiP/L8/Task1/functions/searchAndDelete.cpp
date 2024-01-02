#include "../functions.h"
#include "../checkInput/checkInput.h"

void deleteNumberOfWorkshop(long long *sizeOfArray);

void deleteNameOfProduct(long long *sizeOfArray);

void deleteNumberOfProduct(long long *sizeOfArray);

void deleteWeightOfProduct(long long *sizeOfArray);

void deleteStatusIsCreated(long long *sizeOfArray);

void deleteStructFromArray(long long k, long long *sizeOfArray);

void searchAndDelete(long long *sizeOfArray) {
    printf("What you want to delete?\n0. Nothing\n1. Structures with workshop number X\n2. Structures with product Name \"S\"\n3. Structures with number of product X\n4. Structures with weight X\n5. Structures with status Completed or Not\n");
    long long x = checkInput(x);
    while (x != 0 && x != 1 && x != 2 && x != 3 && x != 4 && x != 5) {
        printf("Error\n");
        x = checkInput(x);
    }

    switch (x) {
        case 0:
            return;
        case 1:
            deleteNumberOfWorkshop(sizeOfArray);
            break;
        case 2:
            deleteNameOfProduct(sizeOfArray);
            break;
        case 3:
            deleteNumberOfProduct(sizeOfArray);
            break;
        case 4:
            deleteWeightOfProduct(sizeOfArray);
            break;
        case 5:
            deleteStatusIsCreated(sizeOfArray);
            break;
    }
}

void deleteNumberOfWorkshop(long long *sizeOfArray) {
    printf("Input X:\n");
    long long x = checkInput(x);
    while(x < 0) {
        printf("Error\n");
        x = checkInput(x);
    }
    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].numberOfWorkshop == x) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deleteNameOfProduct(long long *sizeOfArray) {
    printf("Input S:\n");

    char buf[10000] = "";
    std::scanf("%s", buf);
    std::string s = buf;

    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].nameOfProduct == s) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deleteNumberOfProduct(long long *sizeOfArray) {
    printf("Input X:\n");
    long long x = checkInput(x);
    while(x < 0) {
        printf("Error\n");
        x = checkInput(x);
    }
    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].numberOfProduct == x) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deleteWeightOfProduct(long long *sizeOfArray) {
    printf("Input X:\n");
    long double x = checkInput(x);
    while(x < 0) {
        printf("Error\n");
        x = checkInput(x);
    }

    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].weightOfOneProduct == x) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deleteStatusIsCreated(long long *sizeOfArray) {
    printf("Input status (0 - Not Completed, 1 - Completed:\n");
    long long x = checkInput(x);

    while (x != 0 && x != 1) {
        printf("Error");
        x = checkInput(x);
    }

    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].statusIsCreated == x) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deleteStructFromArray(long long k, long long *sizeOfArray) {
    for (long long i = k; i < (*sizeOfArray) - 1; i++) {
        Data tmp = a[i + 1];
        a[i + 1] = a[i];
        a[i] = tmp;
    }
    (*sizeOfArray)--;
    resizeArray(*sizeOfArray);
}