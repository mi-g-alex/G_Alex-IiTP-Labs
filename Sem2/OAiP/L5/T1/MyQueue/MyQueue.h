#ifndef UNTITLED1_MYQUEUE_H
#define UNTITLED1_MYQUEUE_H

#include "Node.h"

class MyQueue {
    SharedPtr<Node>
            startNode,
            endNode;
    size_t size_ = 0;

public:
    size_t size() const;

    bool empty() const;

    template<typename... Args>
    void emplace(Args &&... args);

    QString& front();

    QString& back();

    void pop();

    void push(QString& line);

    void swap(MyQueue a, MyQueue b);

};


#endif
