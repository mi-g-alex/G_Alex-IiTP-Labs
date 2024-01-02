#include <QApplication>
#include "ui/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *q = new MainWindow(argv[0]);
    q->show();
    q->setMinimumWidth(500);

    return QApplication::exec();
}
