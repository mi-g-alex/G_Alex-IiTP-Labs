#include "MainWindow.h"
#include "../parser.h"

MainWindow::MainWindow() {
    buttonsHB->addWidget(openPB);
    buttonsHB->addWidget(valuesPB);
    buttonsHB->addWidget(classedPB);
    buttonsHB->addWidget(prototypesPB);
    buttonsHB->addWidget(changesPB);
    buttonsHB->addWidget(locValPB);
    buttonsHB->addWidget(reloadFunPB);
    buttonsHB->addWidget(glubPB);
    buttonsHB->addWidget(errorPB);

    connect(valuesPB, SIGNAL(clicked(bool)), SLOT(valuesClicked()));
    connect(classedPB, SIGNAL(clicked(bool)), SLOT(classedClicked()));
    connect(prototypesPB, SIGNAL(clicked(bool)), SLOT(prototypesClicked()));
    connect(changesPB, SIGNAL(clicked(bool)), SLOT(changesClicked()));
    connect(locValPB, SIGNAL(clicked(bool)), SLOT(locValClicked()));
    connect(reloadFunPB, SIGNAL(clicked(bool)), SLOT(reloadFunClicked()));
    connect(glubPB, SIGNAL(clicked(bool)), SLOT(glubClicked()));
    connect(errorPB, SIGNAL(clicked(bool)), SLOT(errorClicked()));
    connect(openPB, SIGNAL(clicked(bool)), SLOT(openClicked()));
    mainVB->addLayout(buttonsHB, 1);
    mainVB->addWidget(text, 1);

    setLayout(mainVB);
}


void MainWindow::valuesClicked() {
    QString s = searchValues(text->toPlainText());
    QMessageBox::information(this, "Vals", s);
}

void MainWindow::classedClicked() {
    QString s = searchClasses(text->toPlainText().toStdString());
    QMessageBox::information(this, "Classes", s);
}

void MainWindow::prototypesClicked() {
    QString s = searchPrototypes(text->toPlainText());
    QMessageBox::information(this, "Prot", s);
}

void MainWindow::changesClicked() {
    QString s = searchChanges(text->toPlainText());
    QMessageBox::information(this, "Changes", s);
}

void MainWindow::locValClicked() {
    QString s = searchLocVal(text->toPlainText());
    QMessageBox::information(this, "Vals", s);
}

void MainWindow::reloadFunClicked() {
    QString s = searchReloadFun(text->toPlainText());
    QMessageBox::information(this, "Reload", s);
}

void MainWindow::glubClicked() {
    QString s = searchGlub(text->toPlainText());
    QMessageBox::information(this, "Глубина", s);
}

void MainWindow::errorClicked() {
    QString s = searchError(text->toPlainText());
    QMessageBox::information(this, "Error", s);
}

void MainWindow::openClicked() {
    pathToFile = QFileDialog::getOpenFileName(this, "Open .txt", "", tr(""));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "Not file selected");
        return;
    }
    QFile file;
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream
            filestream(&file);
    QString s = filestream.readAll();
    a = s.toStdString();
    file.close();
    text->setPlainText(s);
}











