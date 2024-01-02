#ifndef T2_MAINWINDOW_H
#define T2_MAINWINDOW_H

#include "QtWidgets"
#include "../files/MyString.h"

class MainWindow : public QWidget {
Q_OBJECT

public:
    MainWindow();

private:
    QHBoxLayout *mainVB = new QHBoxLayout;
    QVBoxLayout *buttonsHB = new QVBoxLayout;
    QString pathToFile;

    std::string a;

    QPushButton
            *valuesPB = new QPushButton("Кол-во  переменных"),
            *classedPB = new QPushButton("Кол-во классов структрур, массивов"),
            *prototypesPB = new QPushButton("Прототипы"),
            *changesPB = new QPushButton("Изменений"),
            *locValPB = new QPushButton("Локальные валуе"),
            *reloadFunPB = new QPushButton("Перегруженных ф-й"),
            *glubPB = new QPushButton("Глубина ветл."),
            *errorPB = new QPushButton("Ошибки"),
            *openPB = new QPushButton("Open");


    QTextEdit *text = new QTextEdit;


private slots:
    void valuesClicked();
    void classedClicked();
    void prototypesClicked();
    void changesClicked();
    void locValClicked();
    void reloadFunClicked();
    void glubClicked();
    void errorClicked();
    void openClicked();
};

#endif
