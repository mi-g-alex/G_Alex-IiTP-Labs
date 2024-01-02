//
// Created by g_alex on 5/9/23.
//

#ifndef UNTITLED1_MAINWINDOW_H
#define UNTITLED1_MAINWINDOW_H

#include <QtWidgets>
#include "../BinaryTree.h"

class MainWindow : public QWidget {
Q_OBJECT
private:
    Tree *tree = new Tree;

    QVBoxLayout *vb = new QVBoxLayout();
    QHBoxLayout *hb = new QHBoxLayout();

    QPushButton *add = new QPushButton("Add");
    QPushButton *remove = new QPushButton("Remove");
    QPushButton *task = new QPushButton("Task");
    QLineEdit *id = new QLineEdit();
    QLineEdit *fio = new QLineEdit();
    QLineEdit *idToRemove = new QLineEdit();

    QTreeWidget *tw = new QTreeWidget;

public:
    MainWindow();
private slots:
    void add_to_tree();
    void remove_from_tree();
    void make_task();
};


#endif //UNTITLED1_MAINWINDOW_H
