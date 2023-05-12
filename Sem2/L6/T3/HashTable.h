#include <iostream>
#include "stack/stack.h"

#ifndef TREE_H
#define TREE_H

class HashTable {
    stack *table;
    int size_;
public:
    explicit HashTable(int n) {
        table = new stack[n];
        size_ = n;
    }

    void addElement(int tmp) {
        table[abs(tmp % size_)].push(tmp);
    }

    bool searchElement(int tmp) {
        stack t;
        for (; 0 != table[abs(tmp % size_)].getSize();) {
            int tt = table[abs(tmp % size_)].top();
            table[abs(tmp % size_)].pop();
            t.push(tt);
            if (tt == tmp) {
                for (; t.getSize() != 0;) {
                    table[abs(tmp % size_)].push(t.top());
                    t.pop();
                }
                return true;
            }
        }
        for (; t.getSize() != 0;) {
            table[abs(tmp % size_)].push(t.top());
            t.pop();
        }
        return false;
    }

    void deleteElement(int tmp) {
        stack t;
        for (; 0 != table[abs(tmp % size_)].getSize();) {
            int tt = table[abs(tmp % size_)].top();
            table[abs(tmp % size_)].pop();
            t.push(tt);
            if (tt == tmp) {
                t.pop();
                for (; t.getSize() != 0;) {
                    table[abs(tmp % size_)].push(t.top());
                    t.pop();
                }
                return;
            }
        }
        for (; t.getSize() != 0;) {
            table[abs(tmp % size_)].push(t.top());
            t.pop();
        }
    }

    void print(QLabel *lbl) {
        QString s = lbl->text();
        stack t;
        for (int i = 0; i < size_; i++) {
            for (; 0 != table[i].getSize();) {
                int tt = table[i].top();
                table[i].pop();
                t.push(tt);
            }
            for (; t.getSize() != 0;) {
                s += QString::number(t.top()) + " ";
                table[i].push(t.top());
                t.pop();
            }
            s += ".\n";
        }
        lbl->setText(s);
    }

    void clear() {
        delete [] table;
        table = new stack[size_];
    }

};

#endif