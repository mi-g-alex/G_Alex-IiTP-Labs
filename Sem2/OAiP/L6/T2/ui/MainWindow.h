#ifndef UNTITLED1_MAINWINDOW_H
#define UNTITLED1_MAINWINDOW_H

#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include "../qplot/qcustomplot.h"
#include "../HashTable.h"

class MainWindow : public QWidget {
Q_OBJECT
private:


public:
    MainWindow();

    QVBoxLayout *vb = new QVBoxLayout;
    QHBoxLayout *hb = new QHBoxLayout;

    QPushButton *b16 = new QPushButton("16");
    QPushButton *b64 = new QPushButton("64");
    QPushButton *b128 = new QPushButton("128");
    QPushButton *b2048 = new QPushButton("2048");
    QCustomPlot *plot = new QCustomPlot(this);

    QCPGraph *graph = plot->addGraph();
    QVector<double> xData, yData;



private slots:
    void add_elements16();
    void add_elements64();
    void add_elements128();
    void add_elements2048();
};


#endif //UNTITLED1_MAINWINDOW_H
