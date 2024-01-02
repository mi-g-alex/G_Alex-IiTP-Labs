#include "BooksList.h"
void BooksList::push(BookItem *item, long long int pos) {

    if (pos == 0) push_front(item);
    else if (pos >= size - 1) push_back(item);
    else {
        auto *node = new BookItem(item);
        auto s = getElement(pos);
        s->prev->next = node;
        node->prev = s->prev;
        node->next = s;
        s->prev = node;
        size++;
    }
}

void BooksList::push_back(BookItem *item) {
    auto *node = new BookItem(item);
    if (endNode != nullptr) {
        endNode->next = node;
        node->prev = endNode;
    } else {
        startNode = node;
    }
    endNode = node;
    size++;
}

void BooksList::push_front(BookItem *item) {
    auto *node = new BookItem(item);
    if (endNode == nullptr || startNode == nullptr) {
        endNode = node;
    } else {
        node->next = startNode;
        startNode->prev = node;
    }
    startNode = node;
    size++;
}

void BooksList::pop(long long int pos) {
    if(size == 0) return;
    if (size == 1) {
        size = 0;
        delete startNode;
        startNode = nullptr;
        endNode = nullptr;
    }
    if (pos == 0) pop_front();
    else if (pos == size - 1) pop_back();
    else {
        BookItem *s = getElement(pos);
        s->prev->next = s->next;
        s->next->prev = s->prev;
        delete s;
        size--;
    }
}

void BooksList::pop_back() {
    if(size == 0) return;
    if (size == 1) {
        size = 0;
        delete startNode;
        startNode = nullptr;
        endNode = nullptr;
    }
    if (startNode != nullptr || endNode != nullptr) {
        endNode = endNode->prev;
        delete endNode->next;
        endNode->next = nullptr;
        size--;
    }
    if (size == 0) {
        startNode = nullptr;
        endNode = nullptr;
    }
}

void BooksList::pop_front() {
    if(size == 0) return;
    if (size == 1) {
        size = 0;
        delete startNode;
        startNode = nullptr;
        endNode = nullptr;
    }
    if (startNode != nullptr && endNode != nullptr) {
        startNode = startNode->next;
        delete startNode->prev;
        startNode->prev = nullptr;
        size--;
    }
    if (size == 0) {
        startNode = nullptr;
        endNode = nullptr;
    }
}

void BooksList::erase() {
    while (size )
        pop_back();
}

long long BooksList::getSize() const {
    return size;
}

BookItem *BooksList::getElement(long long int n) {
    if (n >= size - 1) return endNode;
    else {
        BookItem *s = startNode;
        while (n--) {
            s = s->next;
        }
        return s;
    }
}

BookItem *BooksList::findByRegNumber(long long int id) {
    for(int i = 0; i < size; i++) {
        BookItem *tmp = getElement(i);
        if(tmp->regNumber == id) {
            return tmp;
        }
    }
    return nullptr;
}

bool BooksList::comp(BookItem *a, BookItem *b) {
    return a->nameOfBook < b->nameOfBook;
}


