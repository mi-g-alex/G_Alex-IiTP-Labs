#ifndef L2T1_BOOK_ITEM_H
#define L2T1_BOOK_ITEM_H

#include <string>
#include <QString>

struct CallItem {
    CallItem *prev = nullptr;
    CallItem *next = nullptr;
    long long timeSeconds{};
    long long code{};
    long long phoneNumber{};
    long long phoneNumberSecond{};
    QString nameOfCity;
    QString tariff;
    QString date;


    CallItem() = default;

    explicit CallItem(CallItem *item) {
        timeSeconds = item->timeSeconds;
        code = item->code;
        phoneNumber = item->phoneNumber;
        nameOfCity = item->nameOfCity;
        tariff = item->tariff;
        phoneNumberSecond=item->phoneNumberSecond;
        date = item->date;
    }
};

#endif
