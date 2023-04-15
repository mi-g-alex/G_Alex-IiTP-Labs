#include <iostream>
#include "forStart.h"

int isVowed(char x) {
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) {
        if (x == 'a' || x == 'o' || x == 'u' || x == 'i' || x == 'e' || x == 'y' ||
            x == 'A' || x == 'O' || x == 'U' || x == 'I' || x == 'E' || x == 'Y') {
            return 1;
        } else return -1;
    }
    if (x != ' ' && x != '\n') return 0;
}

void toDoTask2(char *start, long long i) {
    char x;
    long long ans = 0;
    long long numberOfVowed = 0, numberOfConsonant = 0, numberOfOther = 0;

    for (int j = 0; j < i; j++) {
        x = start[j];
        switch (isVowed(x)) {
            case 1:
                numberOfVowed++;
                break;
            case -1:
                numberOfConsonant++;
                break;
            case 0:
                numberOfOther++;
                break;
        }
    }

    ans = numberOfVowed - numberOfConsonant;

    if (ans > 0) {
        std::cout << "Vowed" << "\n";
        std::cout << "Other elements number: " << numberOfOther << "\n";
    } else if (ans < 0) {
        std::cout << "Consonant" << "\n";
        std::cout << "Other elements number: " << numberOfOther << "\n";
    } else if (numberOfVowed != 0) {
            std::cout << "Equal" << "\n";
            std::cout << "Other elements number: " << numberOfOther << "\n";
    } else {
        std::cout << "Error\nOther elements number: " << numberOfOther << "\n";
    }
}
