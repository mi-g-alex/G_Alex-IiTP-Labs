#ifndef L2T2_BRACKETITEM_H
#define L2T2_BRACKETITEM_H


struct item {
    item *prev{};
    long double x{};
    char c{};

    explicit item(long double x) {
        this->x = x;
    }

    explicit item(char c) {
        this->c = c;
    }


    explicit item(item *item) {
        x = item->x;
        c = item->c;
    }
};


#endif //L2T2_BRACKETITEM_H
