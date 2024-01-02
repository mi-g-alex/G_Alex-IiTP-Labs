#ifndef L2T2_BRACKETITEM_H
#define L2T2_BRACKETITEM_H


struct bracketItem {
    bracketItem *prev{};
    char bracket{};
    int row{};
    int colm{};

    bracketItem(char bracket, int row, int colm) {
        this->bracket = bracket;
        this->row = row;
        this->colm = colm;
    }

    explicit bracketItem(bracketItem *item) {
        this->bracket = item->bracket;
        this->row = item->row;
        this->colm = item->colm;
    }
};


#endif //L2T2_BRACKETITEM_H
