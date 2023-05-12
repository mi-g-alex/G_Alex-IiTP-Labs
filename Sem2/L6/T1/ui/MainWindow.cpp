//
// Created by g_alex on 5/9/23.
//

#include "MainWindow.h"

MainWindow::MainWindow() {
    auto t1 = new QLabel("Id");
    auto t2 = new QLabel("Fio");
    auto t3 = new QLabel("Id");
    vb->addWidget(t1);
    vb->addWidget(id);
    vb->addWidget(t2);
    vb->addWidget(fio);
    vb->addWidget(add);
    connect(add, SIGNAL(clicked(bool)), SLOT(add_to_tree()));
    vb->addStretch(1000);
    vb->addWidget(t3);
    vb->addWidget(idToRemove);
    vb->addWidget(remove);
    connect(remove, SIGNAL(clicked(bool)), SLOT(remove_from_tree()));
    vb->addWidget(task);
    connect(task, SIGNAL(clicked(bool)), SLOT(make_task()));

    hb->addLayout(vb, 1);

    tw->setColumnCount(2);
    tw->setHeaderLabels({"ID", "NAME"});

    tree->update_tree(tw);

    hb->addWidget(tw, 5);
    setLayout(hb);

}

void MainWindow::add_to_tree() {
    int id_t = id->text().toInt();
    auto value_t = fio->text().toStdString();
    tree->insert(id_t, value_t);
    tree->update_tree(tw);
}

void MainWindow::remove_from_tree() {
    int id_t = idToRemove->text().toInt();
    tree->remove(id_t);
    tree->update_tree(tw);
}

void MainWindow::make_task() {

    QMessageBox::information(this, "Таска",
                             "Кол-во вершин с 1 ребенком\n" + QString::number(tree->find_node_with_one_child()));

}

