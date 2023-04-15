#include "../functions.h"
#include <iostream>

void outputStruct(long long start, long long num) {
    for (long long i = start; i < start + num; i++) {
        printf("\n\nStruct %lld", i);
        printf("\n0. Number of workshop:\t\t\t\t");
        printf("%lld", a[i].numberOfWorkshop);
        printf("\n1. Name of Product:\t\t\t\t\t");
        printf("%s", a[i].nameOfProduct);
        printf("\n2. Number of Products produced:\t\t");
        printf("%lld", a[i].numberOfProduct);
        printf("\n3.0. Weight of one product:\t\t\t");
        printf("%.3Lf", a[i].weightOfOneProduct);
        printf("\n3.1. Weight of all products:\t\t");
        printf("%.3Lf", a[i].weightOfAllProducts);
        printf("\n4. Is product ready:\t\t\t\t");
        printf("%s", a[i].statusIsCreated ? "Completed" : "Not completed");

    }
}