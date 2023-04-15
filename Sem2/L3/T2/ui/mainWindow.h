#ifndef L3T2_MAINWINDOW_H
#define L3T2_MAINWINDOW_H

#include <QtWidgets>

class mainWindow : public QWidget {
Q_OBJECT

public:
    mainWindow();

private:
    QHBoxLayout *hbox;
    QTableView *tableLeft, *tableRight;
    QStandardItemModel *modelL, *modelR;
    QModelIndex index;
};


#endif //L3T2_MAINWINDOW_H
