
#include "MainWindow.h"

MainWindow::MainWindow() {
    vb->addWidget(line);
    vb->addWidget(addB);
    connect(addB, SIGNAL(clicked(bool)), SLOT(add_element()));
    vb->addWidget(searchB);
    connect(searchB, SIGNAL(clicked(bool)), SLOT(search_element()));
    vb->addWidget(deleteB);
    connect(deleteB, SIGNAL(clicked(bool)), SLOT(delete_element()));
    vb->addWidget(taskB);
    connect(taskB, SIGNAL(clicked(bool)), SLOT(task()));
    hb->addLayout(vb, 1);
    hb->addWidget(lbl, 20);
    setLayout(hb);
}

void MainWindow::add_element() const {
    int x = line->text().toInt();
    table->addElement(x);
    lbl->setText("");
    table->print(lbl);
}

void MainWindow::search_element() {
    int x = line->text().toInt();
    QMessageBox::information(this, "Find", table->searchElement(x) ? "True" : "False");
}

void MainWindow::delete_element() const {
    int x = line->text().toInt();
    table->deleteElement(x);
    lbl->setText("");
    table->print(lbl);
}

void MainWindow::task() {
    //table->clear();
    for(int i = 0; i < 10; i++) {
        int x = rand() % 51 * ((rand() % 2) ? -1 : 1);
        qDebug() << x;
        table->addElement(x);
        if(x < 0) table_m->addElement(x);
        else table_p->addElement(x);
    }

    lbl->setText(lbl->text() + "Start:\n");
    table->print(lbl);
    lbl->setText(lbl->text() + "\n\n+:\n");
    table_p->print(lbl);
    lbl->setText(lbl->text() + "\n\n-:\n");
    table_m->print(lbl);
}



