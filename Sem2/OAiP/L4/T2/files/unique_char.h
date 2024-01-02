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

unique_ptr make_unique(std::size_t n) ;


#endif

