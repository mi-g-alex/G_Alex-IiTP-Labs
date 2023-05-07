#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H

#include "../shared_ptr.h"
#include <QString>

struct Node {
    SharedPtr<Node> prev;
    SharedPtr<Node> next;
    QString line;

    Node() = default;

    explicit Node(QString& item) {
        line = item;
    }
};

#endif
