#include <QtWidgets>
#include "mainWindow/mainWindow.h"

int main (int argc, char** argv) {
    QApplication app(argc, argv);

    auto *q = new mainWindow;

    q->show();

    QApplication::exec();
}