#ifndef T2_MAINWINDOW_H
#define T2_MAINWINDOW_H

#include "QtWidgets"
#include "../MyQueue/MyDeque.h"

class MainWindow : public QWidget {
Q_OBJECT

public:
    MainWindow();

private:
    QHBoxLayout *mainVB = new QHBoxLayout;
    QVBoxLayout *buttonsHB = new QVBoxLayout;

    MyDeque<QString> a;


    QPushButton
            *pu_b = new QPushButton("Push Back"),
            *pu_f = new QPushButton("Push Front"),
            *po_b = new QPushButton("Pop Back"),
            *po_f = new QPushButton("Pop Front");


    QLineEdit *text = new QLineEdit;
    QLabel *lbl = new QLabel;

    void update_dq();


private slots:
    void onPuB();
    void onPoB();
    void onPuF();
    void onPoF();
};

#endif
