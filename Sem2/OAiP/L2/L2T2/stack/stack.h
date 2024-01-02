#ifndef L2T2_STACK_H
#define L2T2_STACK_H

#include "bracketItem.h"


class stack {
    bracketItem *lastElement = nullptr;
    long long size = 0;
public:
    stack() = default;

    void push(bracketItem item);

    void push(char bracket, long long row, long long clm);

    bracketItem *top();

    void pop();

    long long getSize() {
        return size;
    }

};


#endif //L2T2_STACK_H
