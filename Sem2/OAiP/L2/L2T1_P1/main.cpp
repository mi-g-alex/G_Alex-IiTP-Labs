#include <QApplication>
#include "ui/mainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *q = new mainWindow(argv[0]);
    q->show();
    q->setMinimumWidth(1000);

    return QApplication::exec();
}
