#ifndef L2T1_BOOK_ITEM_H
#define L2T1_BOOK_ITEM_H

#include <string>
#include <QString>

struct BookItem {
    BookItem *prev = nullptr;
    BookItem *next = nullptr;
    long long yearOfPublish{};
    long long numberOfPapers{};
    long long regNumber{};
    QString authorName;
    QString nameOfBook;
    QString publishHouse;


    BookItem() = default;

    explicit BookItem(BookItem *item) {
        yearOfPublish = item->yearOfPublish;
        numberOfPapers = item->numberOfPapers;
        regNumber = item->regNumber;
        authorName = item->authorName;
        nameOfBook = item->nameOfBook;
        publishHouse = item->publishHouse;
    }
};

#endif
