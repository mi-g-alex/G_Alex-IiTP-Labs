#include "CallsList.h"
#include "CallItem.h"

void CallsList::mergeSort(CallsList *list, int l, int r) {
    if (l < r) {
        int q = l + (r - l) / 2;

        mergeSort(list, l, q);
        mergeSort(list, q + 1, r);

        merge(list, l, q, r);
    }
}

void CallsList::merge(CallsList *list, int l, int q, int r) {
    int n1 = q - l + 1, n2 = r - q;
    CallsList N, M;
    for (int i = 0; i < n1; i++) {
        N.push_back(new CallItem(*(list->getElement(l + i))));
    }

    for (int i = 0; i < n2; i++) {
        M.push_back(new CallItem(*(list->getElement(q + 1 + i))));
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (comp(N.getElement(i), M.getElement(j))) {

            list->getElement(k)->timeSeconds = N.getElement(i)->timeSeconds;
            list->getElement(k)->tariff = N.getElement(i)->tariff;
            list->getElement(k)->phoneNumber = N.getElement(i)->phoneNumber;
            list->getElement(k)->date = N.getElement(i)->date;
            list->getElement(k)->code = N.getElement(i)->code;
            list->getElement(k)->nameOfCity = N.getElement(i)->nameOfCity;
            i++;
        } else {
            list->getElement(k)->timeSeconds = M.getElement(j)->timeSeconds;
            list->getElement(k)->tariff = M.getElement(j)->tariff;
            list->getElement(k)->phoneNumber = M.getElement(j)->phoneNumber;
            list->getElement(k)->date = M.getElement(j)->date;
            list->getElement(k)->code = M.getElement(j)->code;
            list->getElement(k)->nameOfCity = M.getElement(j)->nameOfCity;
            j++;
        }
        k++;
    }

    while (i < n1) {
        list->getElement(k)->timeSeconds = N.getElement(i)->timeSeconds;
        list->getElement(k)->tariff = N.getElement(i)->tariff;
        list->getElement(k)->phoneNumber = N.getElement(i)->phoneNumber;
        list->getElement(k)->date = N.getElement(i)->date;
        list->getElement(k)->code = N.getElement(i)->code;
        list->getElement(k)->nameOfCity = N.getElement(i)->nameOfCity;
        i++;
        k++;
    }

    while (j < n2) {
        list->getElement(k)->timeSeconds = M.getElement(j)->timeSeconds;
        list->getElement(k)->tariff = M.getElement(j)->tariff;
        list->getElement(k)->phoneNumber = M.getElement(j)->phoneNumber;
        list->getElement(k)->date = M.getElement(j)->date;
        list->getElement(k)->code = M.getElement(j)->code;
        list->getElement(k)->nameOfCity = M.getElement(j)->nameOfCity;
        j++;
        k++;
    }
}