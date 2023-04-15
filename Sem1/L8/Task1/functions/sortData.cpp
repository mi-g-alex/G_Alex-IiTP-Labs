#include "../functions.h"

void sortArray(long long sizeOfArray) {
    bool isSorted = false;
    long long right = sizeOfArray - 1;
    long long start = 0;
    while (!isSorted) {
        isSorted = true;
        for (long long i = start; i < right; ++i) {
            if (a[i].numberOfProduct < a[i + 1].numberOfProduct) {
                std::swap(a[i], a[i + 1]);
                isSorted = false;
            }
        }
        right--;
        for (long long i = right - 1; i >= start ; --i) {
            if (a[i].numberOfProduct < a[i + 1].numberOfProduct) {
                std::swap(a[i], a[i + 1]);
                isSorted = false;
            }
        }
        start++;
    }
}