#ifndef L2T1_BOOKS_LIST_H
#define L2T1_BOOKS_LIST_H

#include <string>
#include "CallItem.h"
#include <QtWidgets>

class CallsList {
    CallItem **array;
    long long size = 1;
    long long length = 0;

public:

    CallsList() {
        array = new CallItem*[1];
    }

    void push(CallItem *item, long long pos);

    void push_back(CallItem *item);

    void push_front(CallItem *item);

    void pop(long long pos);

    void pop_back();

    void pop_front();

    void erase();

    CallItem *getElement(long long n);

    [[nodiscard]] long long getSize() const;

    //find by ...
    CallItem *findByRegNumber(long long id);

    // Sort
    void mergeSort(CallsList *list, int l, int r);

    void merge(CallsList *list, int l, int q , int r);

    bool comp(CallItem *a, CallItem *b);

private:

    void resize(long long newSize);



};


#endif
