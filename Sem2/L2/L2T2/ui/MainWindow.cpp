#include "MainWindow.h"

#include <utility>

MainWindow::MainWindow(QString link) {

    projDir = std::move(link);

    textTE = new QPlainTextEdit;
    checkPB = new QPushButton("Check");
    openFilePB = new QPushButton("Open File");
    mainVB = new QVBoxLayout;
    mainHB = new QHBoxLayout;

    mainVB->addWidget(textTE, 8);
    mainHB->addWidget(checkPB, 5);
    mainHB->addWidget(openFilePB, 2);
    connect(openFilePB, SIGNAL(clicked(bool)), SLOT(openDelphin()));
    connect(checkPB, SIGNAL(clicked(bool)), SLOT(checkBtnClick()));
    mainVB->addLayout(mainHB);

    setLayout(mainVB);

}

void MainWindow::checkBtnClick() {
    check();
}


void MainWindow::openDelphin() {
    pathToFile = QFileDialog::getOpenFileName(this, "Open .txt", projDir + "/..", tr(""));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "Not file selected");
        return;
    }
    QFile file;
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream filestream(&file);
    QString s = filestream.readAll();
    file.close();
    textTE->setPlainText(s);
}

void MainWindow::check() {
    delete a;
    a = new stack;
    long long row = 1, clm = 1;
    std::string s = textTE->toPlainText().toStdString();
    for (char i: s) {
        if (i == '[' || i == '{' || i == '(') {
            a->push(i, row, clm);
            qDebug() << a->top()->bracket << " " << a->top()->colm << " " << a->top()->row;
        }
        if (i == '\n') {
            row++;
            clm = 0;
        }
        if (i == ']' || i == '}' || i == ')') {
            //qDebug() << a->top()->bracket << " " << a->top()->colm << " " << a->top()->row << "~" << a->getSize();
            if (a->getSize() > 0) {
                if (i == ']' && a->top()->bracket == '['
                    || i == '}' && a->top()->bracket == '{' ||
                    i == ')' && a->top()->bracket == '(') {
                    a->pop();
                    qDebug() << "Size: " << a->getSize();
                } else {
                    QMessageBox::warning(this, "Error-",
                                         "Error:\nrow = " + QString::number(row) + "\nclm = " + QString::number(clm));
                    return;
                }
            } else {
                QMessageBox::warning(this, "Error|",
                                     "Error:\nrow = " + QString::number(row) + "\nclm = " + QString::number(clm));
                return;
            }
        }
        clm++;
    }

    if (a->getSize() != 0) {
        QMessageBox::warning(this, "Error~",
                             "Error:\nrow = " + QString::number(a->top()->row) + "\nclm = " +
                             QString::number(a->top()->colm));
        return;
    }

    QMessageBox::information(this, "OOOK", "All good!!! Be like.");
}
