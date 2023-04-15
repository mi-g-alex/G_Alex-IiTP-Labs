#ifndef L3T1_MYSTRING_H
#define L3T1_MYSTRING_H

#include <cstdint>
#include <cstring>
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

    void operator=(const char *);

    ~MyString();


    char &operator[](size_t n_);

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


#include "MyString.h"

MyString::MyString() {
    size_ = 0;
    capacity_ = 0;
}

MyString::MyString(size_t n) {
    reserve(n + 1);
}


MyString::MyString(MyString const &tmp_) {
    size_ = tmp_.size_;
    capacity_ = tmp_.capacity_;

}

MyString::MyString(std::initializer_list<char> l) :
        size_(l.size()),
        capacity_(l.size()) {
    arr_ = make_unique(size_);
    auto listIt = l.begin();
    size_t i = 0;
    for (i; i < size_; i++, listIt++) {
        arr_[i] = *listIt;
    }
    arr_[i] = '\0';
}


MyString::~MyString() {
    arr_ = make_unique(0);
    capacity_ = 0;
    size_ = 0;
}


char &MyString::operator[](size_t n_) {
    return arr_[n_];
}


template<typename... Args>
void MyString::emplace(MyString::c_iterator pos, Args &&... args) {
    char tmp(args...);
    insert(pos, tmp);
}


template<typename... Args>
void MyString::emplace_back(Args &&... args) {
    char tmp(args...);
    push_back(tmp);
}


void MyString::insert(MyString::c_iterator pos_, char const &tmp_) {
    size_t pos = (pos_).base() - arr_.operator->();
    reserve(size_ + 2);
    for (size_t i = size_; i > pos; i--) {
        arr_[i] = arr_[i - 1];
    }
    arr_[pos] = tmp_;
    size_++;
}


void MyString::insert(MyString::c_iterator pos_, char &&tmp_) {
    size_t pos = pos_.base() - arr_.operator->();
    reserve(size_ + 2);
    for (size_t i = size_; i > pos; i--) {
        arr_[i] = arr_[i - 1];
    }
    arr_[pos] = tmp_;
    size_++;
}


void MyString::push_back(char tmp_) {
    if (size_ + 1 >= capacity_) reserve(2 * size_ + 2);
    arr_[size_] = tmp_;
    arr_[size_ + 1] = '\0';
    size_++;
}


void MyString::assign(size_t n, char tmp_) {
    clear();
    resize(n, tmp_);
}


void MyString::assign(MyString::c_iterator beg, MyString::c_iterator end) {
    clear();
    int sz = end.base() - beg.base();
    resize(sz);
    for (auto i = 0; i < sz; i++) {
        arr_[i] = *(beg + i);
    }
}


void MyString::clear() {
    resize(0);
}


void MyString::erase(MyString::b_iterator tmp) {
    erase(tmp, tmp + 1);
}


void MyString::erase(MyString::b_iterator beg, MyString::b_iterator end) {
    int i1 = beg.base() - arr_.operator->();
    int i2 = end.base() - arr_.operator->();
    for (auto i = i1; i <= i2; i++) {
        arr_[i] = arr_[i + 1];
    }
    size_ = size_ - (i2 - i1);
}


void MyString::pop_back() {
    ~(arr_[size_ - 1]);
    size_--;
}


char &MyString::front() {
    return arr_[0];
}


char &MyString::back() {
    return arr_[size_ - 1];
}


char &MyString::at(size_t pos_) {
    if (pos_ > size_) throw;
    try {
        return arr_[pos_];
    } catch (...) {
        throw;
    }
}


char *MyString::data() {
    return arr_.operator->();
}


size_t MyString::capacity() const {
    return capacity_;
}


size_t MyString::size() const {
    return size_;
}

void MyString::resize(size_t n_size_, char tmp_) {
    if (n_size_ > capacity_) reserve(n_size_);
    for (size_t i = size_; i < n_size_; i++) {
        arr_[i] = tmp_;
    }
    for (size_t i = n_size_; i < size_; i++) {
        ~(arr_[i]);
    }
    size_ = n_size_;
}


void MyString::reserve(size_t n_size_) {
    if (n_size_ <= capacity_) return;
    unique_ptr tmp_ = make_unique(n_size_);
    for (int i = 0; i < size_; i++) {
        tmp_[i] = arr_[i];
    }
    arr_ = std::move(tmp_);
    capacity_ = n_size_;
}


bool MyString::empty() const {
    return size_ == 0;
}


void MyString::swap(MyString &toSwap) {
    std::swap(arr_, toSwap.arr_);
    std::swap(size_, toSwap.size_);
    std::swap(capacity_, toSwap.capacity_);
}


MyString::b_iterator MyString::begin() {
    return b_iterator(arr_.operator->());
}


MyString::b_iterator MyString::end() {
    return b_iterator(arr_.operator->() + size_);
}


MyString::r_iterator MyString::rbegin() {
    return r_iterator(arr_.operator->() + size_);
}


MyString::r_iterator MyString::rend() {
    return r_iterator(arr_.operator->());
}

MyString::MyString(const char *c_str) {
    size_t size = 0;
    while (c_str[size++] != '\0');
    size--;

    reserve(size);

    for (size_t i = 0; i < size; i++) {
        arr_[i] = c_str[i];
    }
    size_ = size;
    arr_[size_] = '\0';
}

void MyString::operator=(const char *c_str) {
    size_t size = 0;
    while (c_str[size++] != '\0');
    size--;

    reserve(size);

    for (size_t i = 0; i < size; i++) {
        arr_[i] = c_str[i];
    }
    size_ = size;
    arr_[size_] = '\0';
}

void *my_memcpy(void *s1, const void *s2, size_t n) {
    auto *dest = static_cast<char *>(s1);
    const auto *src = static_cast<const char *>(s2);

    for (size_t i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void *my_memmove(void *s1, const void *s2, size_t n) {
    auto *dest = static_cast<char *>(s1);
    const auto *src = static_cast<const char *>(s2);

    if (dest < src) {
        for (size_t i = 0; i < n; i++) {
            dest[i] = src[i];
        }
    }
    if (dest > src) {
        for (size_t i = n; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }
    return s1;
}

char *my_strcpy(char *s1, const char *s2) {
    auto *dest = static_cast<char *>(s1);
    const auto *src = static_cast<const char *>(s2);
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return s1;
}

char *my_strncpy(char *s1, const char *s2, size_t n) {
    auto *dest = static_cast<char *>(s1);
    const auto *src = static_cast<const char *>(s2);
    int i = 0;
    for (i; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    if (dest[i - 1] != 0) dest[i] = '\0';
    return s1;
}

char *my_strcat(char *s1, const char *s2) {
    char *dest = s1;
    while (*dest != '\0') {
        dest++;
    }
    while (*s2 != '\0') {
        *dest = *s2;
        dest++;
        s2++;
    }
    *dest = '\0';
    return s1;
}

char *my_strncat(char *s1, const char *s2, size_t n) {
    char *dest = s1;
    while (*dest != '\0') {
        dest++;
    }
    while (*s2 != '\0' && n--) {
        *dest = *s2;
        dest++;
        s2++;
    }
    *dest = '\0';
    return s1;
}

int my_memcmp(const void *s1, const void *s2, size_t n) {
    auto *lv = static_cast<const char *>(s1);
    const auto *rv = static_cast<const char *>(s2);
    while (*lv == *rv && n--) {
        lv++;
        rv++;
    }
    if (*lv > *rv) return 1;
    if (*lv < *rv) return -1;
    return 0;
}

int my_strcmp(const char *lv, const char *rv) {

    while (*lv == *rv && *lv != '\0' && *rv != '\0') {
        lv++;
        rv++;
    }

    if (*lv > *rv) return 1;
    if (*lv < *rv) return -1;
    return 0;
}

int my_strncmp(const char *lv, const char *rv, size_t n) {
    while (*lv == *rv && *lv != '\0' && *rv != '\0' && n--) {
        lv++;
        rv++;
    }

    if (*lv > *rv) return 1;
    if (*lv < *rv) return -1;
    return 0;
}

size_t my_strlen(const char *s) {
    size_t n = 0;
    do {
        n++;
        s++;
    } while (*s != '\0');
    return n;
}

void *my_memset(void *ptr, int value, size_t num) {
    auto *dest = static_cast<unsigned char *>(ptr);
    auto v = static_cast<unsigned char>(value);
    size_t i = 0;
    for (; i < num; i++) {
        dest[i] = v;
    }
    dest[num] = '\0';
    return ptr;
}


char* StrError(int errnum) {
    return std::strerror(errnum);
}

#endif
