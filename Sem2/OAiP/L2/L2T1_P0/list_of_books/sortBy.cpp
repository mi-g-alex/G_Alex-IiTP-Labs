#include "BooksList.h"
#include "BookItem.h"

void BooksList::mergeSort(BooksList *list, int l, int r) {
    if (l < r) {
        int q = l + (r - l) / 2;

        mergeSort(list, l, q);
        mergeSort(list, q + 1, r);

        merge(list, l, q, r);
    }
}

void BooksList::merge(BooksList *list, int l, int q, int r) {
    int n1 = q - l + 1, n2 = r - q;
    BooksList N, M;
    for (int i = 0; i < n1; i++) {
        N.push_back(new BookItem(*(list->getElement(l + i))));
    }

    for (int i = 0; i < n2; i++) {
        M.push_back(new BookItem(*(list->getElement(q + 1 + i))));
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (comp(N.getElement(i), M.getElement(j))) {

            list->getElement(k)->yearOfPublish = N.getElement(i)->yearOfPublish;
            list->getElement(k)->nameOfBook = N.getElement(i)->nameOfBook;
            list->getElement(k)->regNumber = N.getElement(i)->regNumber;
            list->getElement(k)->publishHouse = N.getElement(i)->publishHouse;
            list->getElement(k)->numberOfPapers = N.getElement(i)->numberOfPapers;
            list->getElement(k)->authorName = N.getElement(i)->authorName;
            i++;
        } else {
            list->getElement(k)->yearOfPublish = M.getElement(j)->yearOfPublish;
            list->getElement(k)->nameOfBook = M.getElement(j)->nameOfBook;
            list->getElement(k)->regNumber = M.getElement(j)->regNumber;
            list->getElement(k)->publishHouse = M.getElement(j)->publishHouse;
            list->getElement(k)->numberOfPapers = M.getElement(j)->numberOfPapers;
            list->getElement(k)->authorName = M.getElement(j)->authorName;
            j++;
        }
        k++;
    }

    while (i < n1) {
        list->getElement(k)->yearOfPublish = N.getElement(i)->yearOfPublish;
        list->getElement(k)->nameOfBook = N.getElement(i)->nameOfBook;
        list->getElement(k)->regNumber = N.getElement(i)->regNumber;
        list->getElement(k)->publishHouse = N.getElement(i)->publishHouse;
        list->getElement(k)->numberOfPapers = N.getElement(i)->numberOfPapers;
        list->getElement(k)->authorName = N.getElement(i)->authorName;
        i++;
        k++;
    }

    while (j < n2) {
        list->getElement(k)->yearOfPublish = M.getElement(j)->yearOfPublish;
        list->getElement(k)->nameOfBook = M.getElement(j)->nameOfBook;
        list->getElement(k)->regNumber = M.getElement(j)->regNumber;
        list->getElement(k)->publishHouse = M.getElement(j)->publishHouse;
        list->getElement(k)->numberOfPapers = M.getElement(j)->numberOfPapers;
        list->getElement(k)->authorName = M.getElement(j)->authorName;
        j++;
        k++;
    }
}