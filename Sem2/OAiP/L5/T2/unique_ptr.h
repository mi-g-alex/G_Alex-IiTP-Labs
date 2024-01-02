#ifndef UNTITLED1_UNIQUE_PTR_H
#define UNTITLED1_UNIQUE_PTR_H

#include <type_traits>
#include <utility>
#include <cstddef>

template<typename T>
class UniquePtr {
    T *ptr;
public:
    explicit UniquePtr(T *t_ptr = nullptr);

    UniquePtr(UniquePtr &&x) noexcept;

    ~UniquePtr();

    explicit operator bool() const;

    UniquePtr(const UniquePtr &x) = delete;

    UniquePtr &operator=(UniquePtr &x) = delete;

    UniquePtr &operator=(UniquePtr &&x) noexcept;

    T &operator*();

    T *operator->();

    bool isNull();

};

template<typename T>
UniquePtr<T> &UniquePtr<T>::operator=(UniquePtr &&x) noexcept {
    if (&x == this)
        return *this;

    delete ptr;
    ptr = x.ptr;
    x.ptr = nullptr;
    return *this;
}

template<typename T>
bool UniquePtr<T>::isNull() {
    return ptr == nullptr;
}

template<typename T>
T *UniquePtr<T>::operator->() {
    return ptr;
}

template<typename T>
T &UniquePtr<T>::operator*() {
    return *ptr;
}


template<typename T>
UniquePtr<T>::UniquePtr(T *t_ptr) : ptr(t_ptr) {}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr &&x) noexcept : ptr(x.ptr) {
    x.ptr = nullptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    delete ptr;
}

template<typename T>
UniquePtr<T>::operator bool() const {
    return ptr != nullptr;
}


template<typename T>
class UniquePtr<T[]> {
    T *ptr;
public:
    explicit UniquePtr(T *t_ptr = nullptr);

    UniquePtr(UniquePtr &&x) noexcept;

    ~UniquePtr();

    explicit operator bool() const;

    UniquePtr(const UniquePtr &x) = delete;

    UniquePtr &operator=(UniquePtr &x) = delete;

    UniquePtr &operator=(UniquePtr &&x) noexcept;

    T &operator[](size_t x);

    T &operator*();

    T *operator->();

    bool isNull();

};

template<typename T>
T &UniquePtr<T[]>::operator[](size_t x) {
    return ptr[x];
}

template<typename T>
UniquePtr<T[]> &UniquePtr<T[]>::operator=(UniquePtr &&x) noexcept {
    if (&x == this)
        return *this;

    delete ptr;
    ptr = x.ptr;
    x.ptr = nullptr;
    return *this;
}

template<typename T>
bool UniquePtr<T[]>::isNull() {
    return ptr == nullptr;
}

template<typename T>
T *UniquePtr<T[]>::operator->() {
    return ptr;
}

template<typename T>
T &UniquePtr<T[]>::operator*() {
    return *ptr;
}


template<typename T>
UniquePtr<T[]>::UniquePtr(T *t_ptr) : ptr(t_ptr) {}

template<typename T>
UniquePtr<T[]>::UniquePtr(UniquePtr &&x) noexcept : ptr(x.ptr) {
    x.ptr = nullptr;
}

template<typename T>
UniquePtr<T[]>::~UniquePtr() {
    delete []ptr;
}

template<typename T>
UniquePtr<T[]>::operator bool() const {
    return ptr != nullptr;
}

template<class T, class... Args>
std::enable_if_t<!std::is_array<T>::value, UniquePtr<T>>
make_unique(Args&&... args)
{
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

template<class T>
requires std::is_unbounded_array_v<T>
UniquePtr<T> make_unique(std::size_t n) {
    return UniquePtr<T>(new std::remove_extent_t<T>[n]);
}


#endif

