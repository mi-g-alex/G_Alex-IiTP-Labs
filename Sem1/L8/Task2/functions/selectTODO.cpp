#include "../functions.h"
#include "../checkInput/checkInput.h"

void start() {
    long long sizeOfArray = 0;
    db = (DB *) calloc(sizeof(DB), 1);
    long long x;
    while (true) {
        std::cout
                << "\nSelect what to do:\n"
                   "1. Initialize data from DB.in\n"
                   "2. Add N new structs to DB\n"
                   "3. Delete struct with number N\n"
                   "4. Edit struct with number N\n"
                   "5. View structures from DB\n"
                   "6. Do task and end program\n"
                   "0. Exit\n";

        x = checkInput(x);
        switch (x) {
            case 1:
                importData(&sizeOfArray);
                outputStruct(0, sizeOfArray);
                break;
            case 2:
                long long N;
                std::cout << "Input N:\n";
                N = checkInput(N);
                resizeArray(sizeOfArray + 1);
                inputN(sizeOfArray, 1);
                sizeOfArray += N;
                break;
            case 3:
                if (sizeOfArray == 0) {
                    std::cout << "Error - 0 structs left\n";
                    continue;
                }
                deleteData(&sizeOfArray);
                break;
            case 4:
                if (sizeOfArray == 0) {
                    printf("Error - 0 structs left\n");
                    continue;
                }
                long long ye;
                std::cout << "Input N(" << 0 << " - " << sizeOfArray - 1 << "):\n";
                ye = checkInput(ye);
                while (ye < 0 || ye >= sizeOfArray) {
                    std::cout << "Error\n";
                    ye = checkInput(ye);
                }
                inputN(ye, 1);
                break;
            case 5:
                if (sizeOfArray == 0) {
                    printf("Error - 0 structs left\n");
                    continue;
                }
                outputStruct(0, sizeOfArray);
                break;
            case 6:
                if (sizeOfArray == 0) {
                    printf("Error - 0 structs left\n");
                    continue;
                }
                long long year;
                std::cout << "Input year X:\n";
                year = checkInput(year);
                sortDBAndOutput(sizeOfArray, year);
                return;
            case 0:
                return;
            default:
                break;
        }
    }
}