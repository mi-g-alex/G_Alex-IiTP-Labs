#ifndef L2T2_MAINWINDOW_H
#define L2T2_MAINWINDOW_H

#include <QtWidgets>
#include "../stack/bracketItem.h"
#include "../stack/stack.h"

class MainWindow : public QWidget {
Q_OBJECT
public:
    MainWindow(QString link);

private:

    stack *a = new stack;

    QString projDir;
    QString pathToFile;
    QPlainTextEdit *textTE;
    QPushButton *checkPB;
    QPushButton *openFilePB;

    QVBoxLayout *mainVB;
    QHBoxLayout *mainHB;

    void check();

private slots:

    void openDelphin();

    void checkBtnClick();

};


#endif //L2T2_MAINWINDOW_H
