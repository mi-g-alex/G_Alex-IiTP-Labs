#include "../functions.h"
#include "../checkInput/checkInput.h"


void searchAndEdit(const long long *sizeOfArray) {
    printf("Input number of struct, what u want to edit: \n");

    long long x = checkInput(x);
    while(x >= *sizeOfArray) {
        printf("Error\n");
        x = checkInput(x);
    }

    inputNewStruct(x, 1);

}