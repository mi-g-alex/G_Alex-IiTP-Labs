#include "../functions.h"

void start() {
    f = fopen("../Task3/files/db.dat", "rb+");
    bool q = 0;
    fwrite(&q, 0, 1, f);
    fseek(f, 0L, SEEK_END);
    bool empty = ftell(f) == 0L;
    long long sizeOfArray = 0;
    db = (DB *) calloc(sizeof(DB), 10000);
    if(empty) {
        std::cout << "Data file not exist or there are no data on it\n\nNumber of available 0\n\n";
        sizeOfArray = 0;
    } else {
        fseek(f, 0, SEEK_SET);
        fread(&sizeOfArray, sizeof(long long), 1, f);
        std::cout << "Number of available classes: " << sizeOfArray << "\n\n";
        resizeArray(sizeOfArray);
        for(int i = 0; i < sizeOfArray; i++) {
            fread(&db[i], sizeof(DB), 1, f);
            std::cout << "Struct " << i << ":"
                      << "\nWorkshop: " << db[i].workshop
                      << "\nName: " << db[i].name
                      << "\nNumber: " << db[i].number << "\n\n";
        }

    }


    long long x;

    while (true) {
        std::cout
                << "Select what to do:\n"
                  // "1. Initialize data from DB.in (will delete all data)\n"
                   "2. Add N new class to DB\n"
                   "3. Delete class with number N\n"
                   "4. Edit class with number N\n"
                   "5. View classes from DB\n"
                   "6. Do task (Input workshop X)\n"
                   "0. Exit\n";

        x = checkInput(x);
        switch (x) {
            /*case 1:
                importData(&sizeOfArray);
                outputStruct(0, sizeOfArray);
                break;*/
            case 2:
                long long N;
                std::cout << "Input N:\n";
                N = checkInput(N);
                resizeArray(sizeOfArray + N);
                inputN(sizeOfArray, N);
                sizeOfArray += N;
                fseek(f, 0, SEEK_SET);
                fwrite(&sizeOfArray, sizeof(sizeOfArray), 1, f);
                break;
            case 3:
                if(sizeOfArray == 0) {
                    std::cout << "Error - 0 structs left\n";
                    continue;
                }
                deleteData(&sizeOfArray);
                break;
            case 4:
                if (sizeOfArray == 0) {
                    std::cout << "Error - 0 structs left\n";
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
                if(sizeOfArray == 0) {
                    std::cout << "Error - 0 structs left\n";
                    continue;
                }
                outputStruct(0, sizeOfArray);
                break;
            case 6:
                if(sizeOfArray == 0) {
                    std::cout << "Error - 0 structs left\n";
                    continue;
                }
                long long wh;
                std::cout << "Input workshop number:\n";
                wh = checkInput(wh);
                sortDBAndOutput(sizeOfArray, wh);
                break;
            case 0:
                fclose(f);
                return;
            default:
                continue;
        }
    }
}