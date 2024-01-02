#include "../functions.h"
#include "../checkInput/checkInput.h"

void deleteData(long long *sizeOfArray) {
    long long x;
    std::cout << "Input N:(" << 0 << " - " << *sizeOfArray - 1 << ")\n";
    x = checkInput(x);
    while(x < 0 || x >= *sizeOfArray) {
        std::cout << "Error\n";
        x = checkInput(x);
    }

    for (long long i = x; i < (*sizeOfArray) - 1; i++) {
        db[i] = db[i + 1];
    }
    (*sizeOfArray)--;
    resizeArray(*sizeOfArray);

}