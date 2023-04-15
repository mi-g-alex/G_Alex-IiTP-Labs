#include "stack.h"

void stack::push(bracketItem item) {
    auto *node = new bracketItem(item);
    if (lastElement != nullptr) {
        node->prev = lastElement;
    }
    lastElement= node;
    size++;
}

void stack::push(char bracket, long long row, long long clm) {
    auto *node = new bracketItem(bracket, row, clm);
    if (lastElement != nullptr) {
        node->prev = lastElement;
    }
    lastElement = node;
    size++;
}

bracketItem *stack::top() {
    return lastElement;
}

void stack::pop() {
    bracketItem *tmp = lastElement;
    lastElement = lastElement->prev;
    delete tmp;
    size--;
}
