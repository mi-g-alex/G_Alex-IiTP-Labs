#ifndef L2T2_STACK_H
#define L2T2_STACK_H

#include "item.h"


class stack {
    item *lastElement = nullptr;
    long long size = 0;
public:
    stack() = default;

    void push(item item1);

    void push(long double x);

    void push(char x);

    item *top();

    void pop();

    long long getSize() {
        return size;
    }

};


#endif //L2T2_STACK_H
