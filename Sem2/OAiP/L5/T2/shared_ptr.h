#ifndef UNTITLED1_SHARED_PTR_H
#define UNTITLED1_SHARED_PTR_H

#include <cstdio>
#include <type_traits>
#include <utility>

template<typename T>
class SharedPtr {
    T *ptr;
    size_t *count;

public:
    explicit SharedPtr(T *t_ptr = nullptr);

    SharedPtr(SharedPtr &&x) noexcept;

    ~SharedPtr();

    SharedPtr(const SharedPtr &x);

    explicit operator bool() const;

    SharedPtr &operator=(SharedPtr &x) = delete;

    SharedPtr &operator=(SharedPtr &&x) noexcept;

    T &operator*();

    T *operator->();

    bool isNull();

};

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr &x) {
    count = x.count;
    ptr = x.ptr;
    (*count)++;
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr &&x) noexcept {
    if (&x == this)
        return *this;

    this->~SharedPtr();
    ptr = x.ptr;
    count = x.count;
    (*count)++;
    return *this;
}

template<typename T>
bool SharedPtr<T>::isNull() {
    return ptr == nullptr;
}

template<typename T>
T *SharedPtr<T>::operator->() {
    return ptr;
}

template<typename T>
T &SharedPtr<T>::operator*() {
    return *ptr;
}


template<typename T>
SharedPtr<T>::SharedPtr(T *t_ptr) : ptr(t_ptr), count(new size_t(1)) {}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr &&x) noexcept : ptr(x.ptr), count(x.count) {
    x.count = 1;
    x.ptr = nullptr;
}

template<typename T>
SharedPtr<T>::~SharedPtr() {
    (*count)--;
    if(!*count)
    delete ptr;
}

template<typename T>
SharedPtr<T>::operator bool() const {
    return ptr != nullptr;
}


template<typename T>
class SharedPtr<T[]> {
    T *ptr;
    size_t *count;
public:
    explicit SharedPtr(T *t_ptr = nullptr);
    
    SharedPtr(SharedPtr &&x) noexcept;

    ~SharedPtr();

    SharedPtr(const SharedPtr &x);

    explicit operator bool() const;

    SharedPtr &operator=(SharedPtr &x) = delete;

    SharedPtr &operator=(SharedPtr &&x) noexcept;
    
    T &operator[](size_t x);

    T &operator*();

    T *operator->();

    bool isNull();

};

template<typename T>
T &SharedPtr<T[]>::operator[](size_t x) {
    return ptr[x];
}

template<typename T>
SharedPtr<T[]>::SharedPtr(const SharedPtr &x) {
    count = x.count;
    ptr = x.ptr;
    (*count)++;
}

template<typename T>
SharedPtr<T[]> &SharedPtr<T[]>::operator=(SharedPtr &&x) noexcept {
    if (&x == this)
        return *this;

    this->~SharedPtr();
    ptr = x.ptr;
    count = x.count;
    (*count)++;
    return *this;
}

template<typename T>
bool SharedPtr<T[]>::isNull() {
    return ptr == nullptr;
}

template<typename T>
T *SharedPtr<T[]>::operator->() {
    return ptr;
}

template<typename T>
T &SharedPtr<T[]>::operator*() {
    return *ptr;
}


template<typename T>
SharedPtr<T[]>::SharedPtr(T *t_ptr) : ptr(t_ptr), count(new size_t(1)) {}

template<typename T>
SharedPtr<T[]>::SharedPtr(SharedPtr &&x) noexcept : ptr(x.ptr), count(x.count) {
    x.count = 1;
    x.ptr = nullptr;
}

template<typename T>
SharedPtr<T[]>::~SharedPtr() {
    (*count)--;
    if(!*count)
    delete ptr;
}

template<typename T>
SharedPtr<T[]>::operator bool() const {
    return ptr != nullptr;
}

template<class T, class... Args>
std::enable_if_t<!std::is_array<T>::value, SharedPtr<T>>
make_shared(Args&&... args)
{
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

template<class T>
requires std::is_unbounded_array_v<T>
SharedPtr<T> make_shared(std::size_t n) {
    return SharedPtr<T>(new std::remove_extent_t<T>[n]);
}

#endif

