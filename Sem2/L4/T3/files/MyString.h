#ifndef L3T1_MYSTRING_H
#define L3T1_MYSTRING_H

#include <cstdint>
#include <initializer_list>
#include "iterator.h"
#include "unique_char.h"

class MyString {
    using b_iterator = iterator<char>;
    using r_iterator = reverse_iterator<char>;
    using c_iterator = iterator<const char>;
private:
    unique_ptr arr_ = make_unique(1);
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    MyString();

    explicit MyString(size_t n);

    MyString(MyString const &tmp_);

    MyString(std::initializer_list<char> list_);

    MyString(const char *);

    ~MyString();


    char &operator[](size_t n_);

    void operator=(const char *);

    // Add something

    template<typename ... Args>
    void emplace(c_iterator pos, Args &&... args);

    template<typename ... Args>
    void emplace_back(Args &&... args);

    void insert(c_iterator pos_, char const &tmp_);

    void insert(c_iterator pos_, char &&tmp_);

    void push_back(char tmp_);

    // Delete

    void assign(size_t n, char tmp_);

    void assign(c_iterator beg, c_iterator end);

    void clear();

    void erase(MyString::b_iterator tmp);

    void erase(MyString::b_iterator beg, MyString::b_iterator end);

    void pop_back();

    // links

    char &front();

    char &back();

    char &at(size_t pos_);

    char *data();

    // sizes

    [[nodiscard]] size_t capacity() const;

    [[nodiscard]] size_t size() const;

    void resize(size_t size_, char tmp_ = char());

    void reserve(size_t size_);

    [[nodiscard]] bool empty() const;

    // swap
    void swap(MyString &toSwap);

    // Iterators
    b_iterator begin();

    b_iterator end();

    r_iterator rbegin();

    r_iterator rend();

};


void *my_memcpy(void *s1, const void *s2, size_t n);

void *my_memmove(void *s1, const void *s2, size_t n);

char *my_strcpy(char *s1, const char *s2);

char *my_strncpy(char *s1, const char *s2, size_t n);

char *my_strcat(char *s1, const char *s2);

char *my_strncat(char *s1, const char *s2, size_t n);

int my_memcmp(const void *s1, const void *s2, size_t n);

int my_strcmp(const char *lv, const char *rv);

int my_strncmp(const char *lv, const char *rv, size_t n);

size_t my_strlen(const char *s);

void *my_memset(void *ptr, int value, size_t num);

char *StrError(int errnum);

#endif
