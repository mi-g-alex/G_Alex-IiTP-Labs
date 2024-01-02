#include "CallsList.h"

void CallsList::push(CallItem *item, long long int pos) {
    if (length == size) resize(size + 1);
    for (unsigned long long i = pos; i < length; i++) {
        array[i + 1] = array[i];
    }
    length++;
}

void CallsList::push_back(CallItem *item) {
    auto *node = new CallItem(item);
    if (length == size) resize(size + 1);
    array[length] = node;
    length++;
}

void CallsList::push_front(CallItem *item) {
    auto *node = new CallItem(item);
    if (length == size) resize(size + 1);
    for (unsigned long long i = 0; i < length; i++) {
        array[i + 1] = array[i];
    }
    array[0] = node;
    length++;
}

void CallsList::pop(long long int pos) {
    if (length == 0) return;
    for (unsigned long long i = pos; i < length - 1; i++) {
        qDebug() << " :" << i << " " << length;
        array[i] = array[i + 1];
    }
    array[length - 1] = nullptr;
    length--;
}

void CallsList::pop_back() {
    if (length == 0) return;
    array[length - 1] = nullptr;
    length--;
}

void CallsList::pop_front() {
    pop(0);
}

void CallsList::erase() {
    while (length)
        pop_back();
}

long long CallsList::getSize() const {
    return length;
}

CallItem *CallsList::getElement(long long int n) {
    if (n >= length) n = length - 1;
    return array[n];
}

CallItem *CallsList::findByRegNumber(long long int id) {
    for (int i = 0; i < size; i++) {
        CallItem *tmp = getElement(i);
        if (tmp->phoneNumber == id) {
            return tmp;
        }
    }
    return nullptr;
}

bool CallsList::comp(CallItem *a, CallItem *b) {
    return a->tariff < b->tariff;
}

void CallsList::resize(long long int newSize) {
    auto **tmp = new CallItem *[newSize];
    for (unsigned long long i = 0; i < length; i++) {
        tmp[i] = array[i];
    }
    delete[] array;
    array = tmp;
    size = newSize;
}


