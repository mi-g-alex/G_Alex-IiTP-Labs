#include <QApplication>
#include <QPushButton>
#include "ui/mainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
     auto *q = new mainWindow();

    q->setWindowState(Qt::WindowFullScreen);
    q->show();

    return QApplication::exec();
}
