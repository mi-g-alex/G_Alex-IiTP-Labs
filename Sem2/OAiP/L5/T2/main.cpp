#include <QApplication>
#include "ui/MainWindow.h"

int main(int argc, char *argv[]) {

     QApplication a(argc, argv);
     auto *q = new MainWindow();
     q->show();

     return QApplication::exec();
}