#include <QApplication>
#include "ui/mainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto q = new mainWindow(argv[0]);
    q->setMinimumWidth(700);
    q->show();
    return QApplication::exec();
}
