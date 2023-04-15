#include "mainWindow.h"
#include "../vector/vector.h"
#include "../vector/pair.h"

mainWindow::mainWindow() {
    tableLeft = new QTableView;
    tableRight = new QTableView;

    modelL = new QStandardItemModel(0, 2, this);
    modelR = new QStandardItemModel(0, 3, this);

    /*index = new QModelIndex;*/

    hbox = new QHBoxLayout;
    tableLeft->setModel(modelL);
    tableRight->setModel(modelR);

    hbox->addWidget(tableLeft);
    hbox->addWidget(tableRight);

    modelL->setHeaderData(0, Qt::Horizontal, "Value");
    modelL->setHeaderData(1, Qt::Horizontal, "Reference");

    modelR->setHeaderData(0, Qt::Horizontal, "Value");
    modelR->setHeaderData(1, Qt::Horizontal, "Value1");
    modelR->setHeaderData(2, Qt::Horizontal, "Reference");

    setLayout(hbox);

    MyVector<pair<MyVector<int>, MyVector<pair<int, double>>>> vec;
    vec.resize(1);
    for (int i = 0; i < 20; i++) {
        vec[0].first.push_back(arc4random());
        vec[0].second.push_back(
                {
                        static_cast<int>(arc4random()),
                        static_cast<double>(arc4random()) / 5
                }
        );
    }
    /*modelL->insertRow(0);
    modelR->insertRow(0);*/
    for (int i = 0; i < 20; i++) {
        qDebug() << i;
        modelL->insertRow(i);
        index = modelL->index(i, 0);
        modelL->setData(index, vec[0].first[i]);
        index = modelL->index(i, 1);
        modelL->setData(index, vec[0].first[i]);
        modelR->insertRow(i);
        index = modelR->index(i, 0);
        modelR->setData(index, vec[0].second[i].first);
        index = modelR->index(i, 1);
        modelR->setData(index, vec[0].second[i].second);
        index = modelR->index(i, 2);
        modelR->setData(index, vec[0].second[i].first);
    }
}
