#include "MyQueue.h"

size_t MyQueue::size() const {
    return size_;
}

bool MyQueue::empty() const {
    return size_ == 0;
}

template<typename... Args>
void MyQueue::emplace(Args &&... args) {

}

QString &MyQueue::front() {
    return startNode->line;
}

QString &MyQueue::back() {
    return endNode->line;
}

void MyQueue::pop() {
    if (size_ > 0) {
        startNode->next->prev = std::move(endNode);
        endNode->next = std::move(startNode->next);
        size_--;
        startNode = std::move(endNode->next);
    }
}

void MyQueue::push(QString &line) {
    SharedPtr<Node> tmp_ = make_shared<Node>(line);
    if (size_ == 0) {
        startNode = std::move(tmp_);
        endNode = std::move(startNode);
        startNode->next = std::move(startNode);
        startNode->prev = std::move(startNode);
        endNode->prev = std::move(startNode);
        endNode->prev = std::move(startNode);
        size_++;
    } else {
        endNode = std::move(tmp_);
        startNode->prev->next = std::move(endNode);
        endNode->prev = std::move(startNode->prev);
        endNode->next = std::move(startNode);
        startNode->prev = std::move(endNode);
        size_++;
    }
}

void MyQueue::swap(MyQueue a, MyQueue b) {

}
