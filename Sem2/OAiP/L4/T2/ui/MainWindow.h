#ifndef T2_MAINWINDOW_H
#define T2_MAINWINDOW_H

#include "QtWidgets"
#include "../files/MyString.h"

class MainWindow : public QWidget {
Q_OBJECT

public:
    MainWindow();

private:
    QHBoxLayout *mainVB = new QHBoxLayout;
    QVBoxLayout *buttonsHB = new QVBoxLayout;
    QVBoxLayout *resultHB = new QVBoxLayout;

    MyString s1 = {'1', '2', '3', '4', '5', '\0'};
    MyString s2 = {'0', '9', '6', '7', '8', '\0'};


    QPushButton
            *memcpyPB = new QPushButton("memcpy"),
            *memmovePB = new QPushButton("memmove"),
            *strcpyPB = new QPushButton("strcpy"),
            *strncpyPB = new QPushButton("strNcpy"),
            *strcatPB = new QPushButton("strcat"),
            *strncatPB = new QPushButton("strNcat"),
            *memcmpPB = new QPushButton("memcmp"),
            *strcmpPB = new QPushButton("strcmp"),
            *strncmpPB = new QPushButton("strNcmp"),
            *memsetPB = new QPushButton("memset"),
            *strerrorPB = new QPushButton("strerror"),
            *strlenPB = new QPushButton("strlen"),
            *setS1PB = new QPushButton("Set S1"),
            *setS2PB = new QPushButton("Set S2"),
            *resetPB = new QPushButton("Reset");

    QLabel *s1L = new QLabel(),
            *s2L = new QLabel();

    QLineEdit *textEdit = new QLineEdit();

    void update();

private slots:

    void memcpyClicked();

    void memmoveClicked();

    void strcpyClicked();

    void strncpyClicked();

    void strcatClicked();

    void strncatClicked();

    void memcmpClicked();

    void strcmpClicked();

    void strncmpClicked();

    void memsetClicked();

    void strerrorClicked();

    void strlenClicked();

    void setS1Clicked();

    void setS2Clicked();

    void resetClicked();
};

#endif //T2_MAINWINDOW_H
