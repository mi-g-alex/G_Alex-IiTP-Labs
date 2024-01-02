//
// Created by g_alex on 3/31/23.
//

#ifndef L3T4_MAINWINDOW_H
#define L3T4_MAINWINDOW_H

#include <QtWidgets>
#include "../vector/vector.h"

class mainWindow : public QWidget {
Q_OBJECT
public:
    mainWindow();

private:
    QVBoxLayout *vBox;
    QGridLayout *gridBox;

    QPushButton
            *atPB = new QPushButton("at"),
            *capacityPB = new QPushButton("capacityPB"),
            *clearPB = new QPushButton("clear"),
            *dataPB = new QPushButton("data"),
            *emptyPB = new QPushButton("empty"),
            *erasePB = new QPushButton("erase"),
            *maxSizePB = new QPushButton("maxSize"),
            *popBackPB = new QPushButton("popBack"),
            *pushBackPB = new QPushButton("push"),
            *reservePB = new QPushButton("reserve"),
            *resizePB = new QPushButton("resize"),
            *sizePB = new QPushButton("size");


    QLabel *labelVector;
    QLineEdit *te;

    MyVector<int> a{1, 2, 3, 4, 5, 6, 7};

    void update();

protected slots:

    void atSlot();

    void capacitySlot();

    void clearSlot();

    void dataSlot();

    void emptySlot();

    void eraseSlot();

    void maxSizeSlot();

    void popBackSlot();

    void pushBackSlot();

    void reserveSlot();

    void resizeSlot();

    void sizeSlot();
};


#endif //L3T4_MAINWINDOW_H
