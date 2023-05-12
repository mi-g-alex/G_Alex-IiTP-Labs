#ifndef L2T2_BRACKETITEM_H
#define L2T2_BRACKETITEM_H


struct item {
    item *prev{};
    int x{};

    explicit item(int x) {
        this->x = x;
    }

    explicit item(item *item) {
        x = item->x;
    }
};


#endif //L2T2_BRACKETITEM_H
