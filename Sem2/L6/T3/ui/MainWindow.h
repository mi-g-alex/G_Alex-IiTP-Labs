#ifndef UNTITLED1_MAINWINDOW_H
#define UNTITLED1_MAINWINDOW_H

#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include "../HashTable.h"

class MainWindow : public QWidget {
Q_OBJECT
private:


public:
    MainWindow();

    QVBoxLayout *vb = new QVBoxLayout;
    QHBoxLayout *hb = new QHBoxLayout;

    QPushButton *addB = new QPushButton("Add");
    QPushButton *searchB = new QPushButton("Search");
    QPushButton *deleteB = new QPushButton("Delete");
    QPushButton *taskB = new QPushButton("Task");

    QLineEdit *line = new QLineEdit;

    HashTable *table = new HashTable(10);
    HashTable *table_p = new HashTable(10);
    HashTable *table_m = new HashTable(10);

    QLabel *lbl = new QLabel;


private slots:
    void add_element() const;
    void search_element();
    void delete_element() const;
    void task();
};


#endif //UNTITLED1_MAINWINDOW_H
