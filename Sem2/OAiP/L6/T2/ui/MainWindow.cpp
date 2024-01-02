
#include "MainWindow.h"

MainWindow::MainWindow() {
    vb->addWidget(b16);
    connect(b16, SIGNAL(clicked(bool)), SLOT(add_elements16()));
    vb->addWidget(b64);
    connect(b64, SIGNAL(clicked(bool)), SLOT(add_elements64()));
    vb->addWidget(b128);
    connect(b128, SIGNAL(clicked(bool)), SLOT(add_elements128()));
    vb->addWidget(b2048);
    connect(b2048, SIGNAL(clicked(bool)), SLOT(add_elements2048()));
    hb->addLayout(vb, 1);
    hb->addWidget(plot, 20);
    setLayout(hb);
}

void MainWindow::add_elements16() {
    auto *a = new QElapsedTimer;
    HashTable b(16);
    QVector<int> v(16);
    for (int i = 0; i < 16; i++) {
        v[i] = rand();
        b.addElement(v[i]);
    }
    xData.clear();
    yData.clear();
    a->start();
    for (int i = 0; i < v.size(); i++) {
        b.searchElement(v[i]);
        yData.push_back((double) a->nsecsElapsed() / 1000);
        xData.push_back(i + 1);
        a->restart();
    }
    delete a;
    graph->setData(xData, yData);
    plot->rescaleAxes();
    plot->replot();
}

void MainWindow::add_elements64() {
    auto *a = new QElapsedTimer;
    HashTable b(64);
    QVector<int> v(64);
    for (int i = 0; i < 64; i++) {
        v[i] = rand();
        b.addElement(v[i]);
    }
    xData.clear();
    yData.clear();
    a->start();
    for (int i = 0; i < v.size(); i++) {
        b.searchElement(v[i]);
        yData.push_back((double) a->nsecsElapsed() / 1000);
        xData.push_back(i + 1);
        a->restart();
    }
    delete a;
    graph->setData(xData, yData);
    plot->rescaleAxes();
    plot->replot();
}

void MainWindow::add_elements128() {
    auto *a = new QElapsedTimer;
    HashTable b(128);
    QVector<int> v(128);
    for (int i = 0; i < 128; i++) {
        v[i] = rand();
        b.addElement(v[i]);
    }
    xData.clear();
    yData.clear();
    a->start();
    for (int i = 0; i < v.size(); i++) {
        b.searchElement(v[i]);
        yData.push_back((double) a->nsecsElapsed() / 1000);
        xData.push_back(i + 1);
        a->restart();
    }
    delete a;
    graph->setData(xData, yData);
    plot->rescaleAxes();
    plot->replot();
}

void MainWindow::add_elements2048() {
    auto *a = new QElapsedTimer;
    HashTable b(2048);
    QVector<int> v(2048);
    for (int i = 0; i < 2048; i++) {
        v[i] = rand();
        b.addElement(v[i]);
    }
    xData.clear();
    yData.clear();
    a->start();
    for (int i = 0; i < v.size(); i++) {
        b.searchElement(v[i]);
        yData.push_back((double) a->nsecsElapsed());
        xData.push_back(i + 1);
        a->restart();
    }
    delete a;
    graph->setData(xData, yData);
    plot->rescaleAxes();
    plot->replot();
}



