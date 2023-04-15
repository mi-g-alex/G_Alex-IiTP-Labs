#include "../functions.h"
#include <unistd.h>
 #include <sys/types.h>



void deleteData(long long *sizeOfArray) {
    long long x;
    std::cout << "Input N:(" << 0 << " - " << *sizeOfArray - 1 << ")\n";
    x = checkInput(x);
    while(x < 0 || x >= *sizeOfArray) {
        std::cout << "Error\n";
        x = checkInput(x);
    }
    fseek(f, sizeof(long long) + x * sizeof(DB), SEEK_SET);
    for (long long i = x; i < (*sizeOfArray) - 1; i++) {
        db[i] = db[i + 1];
        fwrite(&db[i], sizeof(db[i]), 1, f);
    }
    (*sizeOfArray)--;
    fseek(f, 0, SEEK_SET);
    fwrite(sizeOfArray, sizeof(sizeOfArray), 1, f);
    resizeArray(*sizeOfArray);

    int fp  = fileno(f);
    if(*sizeOfArray > 0) ftruncate(fp, sizeof(long long) + *sizeOfArray * sizeof(DB));
    else ftruncate(fp, sizeof(long long) - sizeof(long long));
}