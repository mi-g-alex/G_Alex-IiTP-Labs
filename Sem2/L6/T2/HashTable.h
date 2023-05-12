#include <iostream>

#ifndef TREE_H
#define TREE_H

class HashTable {
    int *table;
    int size_;
public:
    explicit HashTable(int n) {
        table = new int[n];
        size_ = n;
        for (int i = 0; i < n; i++) {
            table[i] = -INT32_MAX;
        }
    }

    void addElement(int tmp) {
        if (table[tmp % size_] == -INT32_MAX) {
            table[tmp % size_] = tmp;
            return;
        } else {
            for (int i = (tmp + 1) % size_; i != tmp % size_; i = (i + 1) % size_) {
                if (table[i] == -INT32_MAX) {
                    table[i] = tmp;
                    return;
                }
            }
        }
    }

    bool searchElement(int tmp) {
        if (table[tmp % size_] == tmp) {
            return true;
        }
        for (int i = (tmp + 1) % size_; i != tmp % size_; i = (i + 1) % size_) {
            if (table[i] == tmp) {
                return true;
            }
        }

        return false;
    }

    void deleteElement(int tmp) {
        if (table[tmp % size_] == tmp) {
            table[tmp % size_] = -INT32_MAX;
            return;
        }
        for (int i = (tmp + 1) % size_; i != tmp % size_; i = (i + 1) % size_) {
            if (table[i] == tmp) {
                table[tmp % size_] = -INT32_MAX;
            }
        }
    }

    void print() {
        for (int i = 0; i < size_; ++i) {
            if(table[i] == -INT32_MAX) std::cout << "|";
            else std::cout << table[i] << " ";
        }
    }
};

#endif