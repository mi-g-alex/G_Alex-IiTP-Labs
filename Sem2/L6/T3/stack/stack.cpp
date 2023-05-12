#include "stack.h"

void stack::push(item item1) {
    auto *node = new item(item1);
    if (lastElement != nullptr) {
        node->prev = lastElement;
    }
    lastElement = node;
    size++;
}

void stack::push(int x) {
    auto *node = new item(x);
    if (lastElement != nullptr) {
        node->prev = lastElement;
    }
    lastElement = node;
    size++;
}

int &stack::top() {
    return lastElement->x;
}

void stack::pop() {
    item *tmp = lastElement;
    lastElement = lastElement->prev;
    if(size != 1) delete tmp;
    size--;
}