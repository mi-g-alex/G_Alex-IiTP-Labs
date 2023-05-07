#include "MainWindow.h"

MainWindow::MainWindow() {

    buttonsHB->addWidget(text);
    buttonsHB->addWidget(pu_b);
    buttonsHB->addWidget(pu_f);
    buttonsHB->addWidget(po_b);
    buttonsHB->addWidget(po_f);
    connect(pu_b, SIGNAL(clicked(bool)), SLOT(onPuB()));
    connect(po_b, SIGNAL(clicked(bool)), SLOT(onPoB()));
    connect(pu_f, SIGNAL(clicked(bool)), SLOT(onPuF()));
    connect(po_f, SIGNAL(clicked(bool)), SLOT(onPoF()));

    mainVB->addLayout(buttonsHB, 1);
    mainVB->addWidget(lbl, 1);

    setLayout(mainVB);
}

void MainWindow::update_dq() {
    QString s = "";
    auto i = a.begin();
    for(; i != a.end(); ++i) {
        s+= *i + " ";
    }
    s += *a.end() + " ";
    lbl->setText(s);
}

void MainWindow::onPuB() {
    a.push_back(text->text());
    update_dq();
}

void MainWindow::onPoB() {
    a.pop_back();
    if(a.size() != 0) update_dq();
    else lbl->setText("");
}

void MainWindow::onPuF() {
    a.push_front(text->text());
    update_dq();
}

void MainWindow::onPoF() {
    a.pop_front();
    if(a.size() != 0) update_dq();
    else lbl->setText("");
}
