#include "mainWindow.h"

mainWindow::mainWindow(QString link) {

    projDir = std::move(link);

    lineToInput = new QLineEdit;
    lineToInput->setPlaceholderText("Инфиксная запись");
    lineToOutPut = new QLineEdit;
    lineToOutPut->setPlaceholderText("Постфиксная запись (ОПЗ)");
    lineToOutPut->setReadOnly(true);

    mainVB = new QVBoxLayout;
    mainHB = new QHBoxLayout;

    toRpePB = new QPushButton("Из Инфиксной в ОПЗ");
    connect(toRpePB, SIGNAL(clicked(bool)), SLOT(toRpeClicked()));
    fromRpePB = new QPushButton("ОПЗ");

    mainVB->addWidget(lineToInput);
    mainVB->addWidget(lineToOutPut);
    mainHB->addWidget(toRpePB);
    //mainHB->addWidget(fromRpePB);

    mainVB->addLayout(mainHB);

    setLayout(mainVB);
}

void mainWindow::toRpeClicked() {
    //qDebug() << qwerty.toRpe(lineToInput->text());
    QString s = qwerty.toRpe(lineToInput->text());
    if(s[0] == '|') {
        s = "Error. Something went wrong";
    }
    lineToOutPut->setText(s);
}

void mainWindow::fromRpeClicked() {

}

