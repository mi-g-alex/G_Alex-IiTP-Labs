#include <QtWidgets>
#include "ui/MainWindow.h"
#include "HashTable.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *q = new MainWindow();
    q->setFixedSize(1000, 500);
    q->show();
    return QApplication::exec();
}