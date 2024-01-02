#ifndef UNTITLED1_UNIQUE_CHAR_H
#define UNTITLED1_UNIQUE_CHAR_H

#include <type_traits>
#include <utility>
#include <cstddef>

class unique_ptr {
    char *ptr;
public:
    explicit unique_ptr(char *t_ptr = nullptr);

    unique_ptr(unique_ptr &&x) noexcept;

    ~unique_ptr();

    explicit operator bool() const;

    unique_ptr(const unique_ptr &x) = delete;

    unique_ptr &operator=(unique_ptr &x) = delete;

    unique_ptr &operator=(unique_ptr &&x) noexcept;

    char &operator[](size_t x);

    char &operator*();

    char *operator->();

    bool isNull();

};


char &unique_ptr::operator[](size_t x) {
    return ptr[x];
}


unique_ptr &unique_ptr::operator=(unique_ptr &&x) noexcept {
    if (&x == this)
        return *this;

    delete ptr;
    ptr = x.ptr;
    x.ptr = nullptr;
    return *this;
}


bool unique_ptr::isNull() {
    return ptr == nullptr;
}


char *unique_ptr::operator->() {
    return ptr;
}


char &unique_ptr::operator*() {
    return *ptr;
}


unique_ptr::unique_ptr(char *t_ptr) : ptr(t_ptr) {}


unique_ptr::unique_ptr(unique_ptr &&x) noexcept: ptr(x.ptr) {
    x.ptr = nullptr;
}


unique_ptr::~unique_ptr() {
    delete[]ptr;
}


unique_ptr::operator bool() const {
    return ptr != nullptr;
}

unique_ptr make_unique(std::size_t n) {
        return unique_ptr(new std::remove_extent_t<char>[n]);
}


#endif

