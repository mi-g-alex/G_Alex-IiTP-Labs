#ifndef UNTITLED1_MYDEQUE_H
#define UNTITLED1_MYDEQUE_H

#include <iostream>
#include "../unique_ptr.h"
#include "../shared_ptr.h"

struct A {
    long long out = 0;
    long long in = -1;
};


template<typename T>
class MyDeque {

    struct chunk {
    public:
        T arr[10];
        int nmb;
    };

    UniquePtr<chunk*[]> arr_;

    class Iterator {
    public:
        MyDeque *ptr;
        chunk *a;
        long long elem = 0;

        explicit Iterator(MyDeque<T> *tmp_, int t1, int t2) : ptr(tmp_) {
            a = ptr->arr_[t1];
            elem = t2;
        }

        T &operator*() const {
            return a->arr[elem];
        }

        // ->
        T *operator->() const {
            return a->arr[elem];
        }

        // ++ | --
        Iterator &operator++() {
            if (elem == 9) {
                elem = 0;
                a = ptr->arr_[a->nmb + 1];
            } else {
                elem++;
            }
            return *this;
        }

        Iterator &operator--() {
            if (elem == 0) {
                elem = 9;
                a = ptr->arr_[a->nmb - 1];
            } else {
                elem--;
            }
        }

        // + | -
        Iterator operator+(int n) {
            elem = (elem + n) % 10;
            a = ptr->arr_[a->nmb + n / 10];
            return *this;
        }

        Iterator operator-(size_t n) {
            elem = (elem - n) % 10;
            a = ptr->arr_[a->nmb - n / 10];
            return *this;
        }

        // += | -=
        Iterator &operator+=(size_t n) {
            elem = (elem + n) % 10;
            a = ptr->arr_[a->nmb + n / 10];
            return *this;
        }

        Iterator &operator-=(size_t n) {
            elem = (elem - n) % 10;
            a = ptr->arr_[a->nmb - n / 10];
            return *this;
        }

        // []
        T operator[](size_t t) {
            if (t % 10 == 0) return ptr->arr_[a->nmb + t / 10].arr[elem];
            return ptr->arr_[a->nmb + (t > 10 - elem - 1 ? t / 10 + 1 : t / 10)]->arr[(elem + t % 10) % 10];
        }

        bool operator != (Iterator c) {
            return c.a != this->a;
        }

    };

    A start_, end_;
    long long size_ = 1;
    long long all_ = 0;

public:

    MyDeque() :
            arr_(make_unique<chunk*[]>(1)) {
        arr_[0] = new chunk;
    };

    void push_front(T elm);

    void pop_front();

    void push_back(T elm);

    void pop_back();

    void clear();

    long long size();

    bool empty();

    Iterator begin() {
        return Iterator(this, start_.out, start_.in);
    }

    Iterator end() {
        return Iterator(this, end_.out, end_.in);
    }

    T &operator[](long long t) {
        if (t % 10 == 0) return arr_[start_.out + t / 10].arr[start_.in];
        return arr_[start_.out + (t > 10 - start_.in - 1 ? t / 10 + 1 : t / 10)].arr[(start_.in + t % 10) % 10];
    }

private:

    void resize_back(long long new_);

    void resize_front(long long new_);

};

template<typename T>
void MyDeque<T>::push_front(T elm) {
    if (start_.in == -1) {
        start_.in = 9;
        arr_[start_.out]->arr[start_.in] = elm;
        end_.in = 9;
    } else {
        if (start_.in == 0) {
            resize_front(size_ + 1);
            start_.in = 9;
            start_.out--;
            arr_[start_.out]->arr[start_.in] = elm;
        } else {
            start_.in--;
            arr_[start_.out]->arr[start_.in] = elm;
        }
    }
    all_++;
}


template<typename T>
void MyDeque<T>::pop_front() {
    if (all_ == 0) throw std::out_of_range("Size == 0");
    arr_[start_.out]->arr[start_.in].~T();
    arr_[start_.out]->arr[start_.in] = T();
    all_--;
    if (all_ == 0) {
        start_.in = -1;
        start_.out = 0;
        end_.in = -1;
        end_.out = 0;
    } else {
        if (start_.in == 9) {
            start_.out++;
            start_.in = 0;
        } else {
            start_.in--;
        }
    }
}

template<typename T>
void MyDeque<T>::push_back(T elm) {
    if (end_.in == -1) {
        end_.in = 0;
        arr_[end_.out]->arr[end_.in] = elm;
        start_.in = 0;
    } else {
        if (end_.in == 9) {
            resize_back(size_ + 1);
            end_.in = 0;
            end_.out++;
            arr_[end_.out]->arr[end_.in] = elm;
        } else {
            end_.in++;
            arr_[end_.out]->arr[end_.in] = elm;
        }
    }
    all_++;
}

template<typename T>
void MyDeque<T>::pop_back() {
    if (all_ == 0) throw std::out_of_range("Size == 0");
    arr_[end_.out]->arr[end_.in].~T();
    arr_[end_.out]->arr[end_.in] = T();
    all_--;
    if (all_ == 0) {
        start_.in = -1;
        start_.out = 0;
        end_.in = -1;
        end_.out = 0;
    } else {
        if (end_.in == 0) {
            end_.out--;
            end_.in = 9;
        } else {
            end_.in--;
        }
    }
}

template<typename T>
void MyDeque<T>::clear() {
    UniquePtr<chunk[]> tmp_ = make_unique<chunk[]>(1);
    arr_ = std::move(tmp_);
    all_ = 0;
    size_ = 0;
    start_.in = -1;
    start_.out = 0;
    end_.in = -1;
    end_.out = 0;
}

template<typename T>
long long MyDeque<T>::size() {
    return all_;
}

template<typename T>
bool MyDeque<T>::empty() {
    return all_ == 0;
}

template<typename T>
void MyDeque<T>::resize_front(long long new_) {
    if (new_ > size_) {
        UniquePtr<chunk*[]> tmp_ = make_unique<chunk*[]>(new_);
        for (int i = 0; i < size_; i++) {
            std::swap(tmp_[i + new_ - size_], arr_[i]);
        }
        for(int i = 0; i < new_ - size_; i++) {
            tmp_[i] = new chunk;
        }
        for (int i = 0; i < new_; i++) {
            tmp_[i]->nmb = i;
        }
        end_.out = new_ - 1;
        start_.out = new_ - size_;
        size_ = new_;
        arr_ = std::move(tmp_);
    }
}

template<typename T>
void MyDeque<T>::resize_back(long long new_) {
    if (new_ > size_) {
        UniquePtr<chunk*[]> tmp_ = make_unique<chunk*[]>(new_);
        for (int i = 0; i < size_; i++) {
            std::swap(tmp_[i], arr_[i]);
        }
        for(int i = size_; i < new_; i++) {
            tmp_[i] = new chunk;
        }

        for (int i = 0; i < new_; i++) {
            tmp_[i]->nmb = i;
        }
        size_ = new_;
        arr_ = std::move(tmp_);
    }
}

#endif
