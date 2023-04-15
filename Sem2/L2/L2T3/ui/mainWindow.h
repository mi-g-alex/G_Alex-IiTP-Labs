#ifndef L2T3_MAINWINDOW_H
#define L2T3_MAINWINDOW_H

#include <QtWidgets>
#include "../rpe/rpe.h"

class mainWindow : public QWidget {
Q_OBJECT
public:
    explicit mainWindow(QString link);

private:
    QString projDir;

    rpe qwerty;

    QLineEdit *lineToInput{};
    QLineEdit *lineToOutPut{};

    QVBoxLayout *mainVB;
    QHBoxLayout *mainHB;

    QPushButton *toRpePB{};
    QPushButton *fromRpePB{};

private slots:

    void toRpeClicked();
    void fromRpeClicked();

};


#endif //L2T3_MAINWINDOW_H
