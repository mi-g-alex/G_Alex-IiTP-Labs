#ifndef L2T1_BOOKS_LIST_H
#define L2T1_BOOKS_LIST_H

#include <string>
#include "BookItem.h"
#include <vector>
#include <QtWidgets>

class BooksList {
    BookItem *startNode = nullptr;
    BookItem *endNode = nullptr;
    long long size = 0;

public:
    void push(BookItem *item, long long pos);

    void push_back(BookItem *item);

    void push_front(BookItem *item);

    void pop(long long pos);

    void pop_back();

    void pop_front();

    void erase();

    BookItem *getElement(long long n);

    [[nodiscard]] long long getSize() const;

    //find by ...
    BookItem *findByRegNumber(long long id);

    // Sort
    void mergeSort(BooksList *list, int l, int r);

    void merge(BooksList *list, int l, int q , int r);

    bool comp(BookItem *a, BookItem *b);

};


#endif
