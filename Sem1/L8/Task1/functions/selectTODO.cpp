#include "../functions.h"
#include "../checkInput/checkInput.h"

long long firstInput();

void inputN(long long *sizeOfArray);

bool needToContinue();

void whatToDo(long long *sizeOfArray);

void input(long long *sizeOfArray);


void start() {

    a = (Data *) calloc(sizeof(Data), 1);

    long long sizeOfArray = 0;

    whatToDo(&sizeOfArray);

}

void whatToDo(long long *sizeOfArray) {
    input(sizeOfArray);
    if (*sizeOfArray == 0) return;
    while (true) {
        printf("\n\n"
               "1. View all structures\n"
               "2. Add new structs\n"
               "3. Search and output them\n"
               "4. Search and delete\n"
               "5. Edit struct number X\n"
               "6. Sort array of structures\n"
               "0. Exit\n");
        long long i = checkInput(i);
        switch (i) {
            case 0:
                return;
            case 1:
                if (*sizeOfArray) outputStruct(0, *sizeOfArray);
                else printf("0 structs left\n");
                break;
            case 2:
                input(sizeOfArray);
                break;
            case 3:
                if (*sizeOfArray) searchAndOutput(sizeOfArray);
                else printf("0 structs left\n");
                break;
            case 4:
                if (*sizeOfArray) searchAndDelete(sizeOfArray);
                else printf("0 structs left\n");
                break;
            case 5:
                if (*sizeOfArray) searchAndEdit(sizeOfArray);
                else printf("0 structs left\n");
                break;
            case 6:
                if (*sizeOfArray) sortArray(*sizeOfArray);
                else printf("0 structs left\n");
                break;
            default:
                printf("Error\n");
                break;
        }
    }
}

void input(long long *sizeOfArray) {
    switch (firstInput()) {
        case 0:
            return;
        case 1:
            do {
                inputN(sizeOfArray);
            } while (needToContinue());
            break;
        case 2:
            do {
                inputWhile("ball", sizeOfArray);
            } while (needToContinue());
    }
}


bool needToContinue() {
    printf("Need to continue?\n0. No\n1. Yes\n");
    long long i = checkInput(i);
    while (i != 0 && i != 1) {
        printf("Error\n");
        i = checkInput(i);
    }
    return (bool) i;
}

long long firstInput() {
    printf("\nSelect:\n1. Input N structures\nor\n2. Input while name of product is not \"ball\"\n\n0. Exit\n");
    long long i = checkInput(i);
    while (i != 0 && i != 1 && i != 2) {
        printf("Error\n");
        i = checkInput(i);
    }
    return i;
}

void inputN(long long *sizeOfArray) {
    printf("Input number of structures that you want to add:\n");
    long long N = checkInput(N);
    while (N < 1) {
        printf("Error\n");
        N = checkInput(N);
    }
    (*sizeOfArray) += N;
    resizeArray(*sizeOfArray);

    inputNewStruct(*sizeOfArray - N, N);
}