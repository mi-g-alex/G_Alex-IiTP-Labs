#include "mainWindow.h"
#include "searchByIdDialog.h"

#include <utility>

mainWindow::mainWindow(QString s) {
    listOfBooks = new CallsList;
    projDir = std::move(s);
    mainHB = new QHBoxLayout;
    actionsMainVL = new QVBoxLayout;
    actionsMainVL->addStretch(1000);

    openSaveHB = new QHBoxLayout;
    open = new QPushButton("Open");
    connect(open, SIGNAL(clicked(bool)), SLOT(openDolphin()));
    save = new QPushButton("Save");
    connect(save, SIGNAL(clicked(bool)), SLOT(saveToFile()));

    openSaveHB->addWidget(open);
    openSaveHB->addWidget(save);

    actionsMainVL->addLayout(openSaveHB);

    viewGB = new QGroupBox;
    viewVL = new QVBoxLayout;
    viewGB->setLayout(viewVL);

    selectBookCB = new QComboBox;
    selectBookCB->setEditable(true);
    connect(selectBookCB, SIGNAL(currentIndexChanged(int)), SLOT(setInformation()));
    phoneNumberL = new QLabel("Phone Number: N\\N");
    phoneNumberSecondL = new QLabel("Second Phone Number: N\\N");
    codeL = new QLabel("Code: N\\N");
    timeSecondsL = new QLabel("Time (Seconds): N\\N");
    nameOfCityL = new QLabel("City: N\\N");
    tariffL = new QLabel("Tariff: N\\N");
    dateL = new QLabel("Date:");

    viewVL->addWidget(selectBookCB);
    viewVL->addWidget(phoneNumberL);
    viewVL->addWidget(phoneNumberSecondL);
    viewVL->addWidget(codeL);
    viewVL->addWidget(timeSecondsL);
    viewVL->addWidget(nameOfCityL);
    viewVL->addWidget(tariffL);
    viewVL->addWidget(dateL);
    viewVL->addSpacing(5);

    viewHB = new QHBoxLayout;
    addBookPB = new QPushButton("Add...");
    connect(addBookPB, SIGNAL(clicked(bool)), SLOT(addBookItem()));
    deleteBookPB = new QPushButton("Delete Current");
    connect(deleteBookPB, SIGNAL(clicked(bool)), SLOT(deleteBtnClicked()));
    searchByIdPB = new QPushButton("Search by Phone Number");
    connect(searchByIdPB, SIGNAL(clicked(bool)), SLOT(findById()));

    viewHB->addWidget(addBookPB);
    viewHB->addWidget(deleteBookPB);

    sortMenuHB = new QHBoxLayout;
    sortByPB = new QPushButton("Sort by Phone");
    connect(sortByPB, SIGNAL(clicked(bool)), SLOT(sortByName()));

    sortMenuHB->addWidget(sortByPB);

    viewVL->addLayout(viewHB);
    viewVL->addWidget(searchByIdPB);
    viewVL->addLayout(sortMenuHB);

    resultPTE = new QPlainTextEdit;

    actionsMainVL->addWidget(viewGB);

    mainHB->addLayout(actionsMainVL, 1);
    mainHB->addWidget(resultPTE, 2);
    actionsMainVL->addStretch(1000);

    setLayout(mainHB);

    setNotVisible();

}

void mainWindow::setNotVisible() {
    viewGB->setEnabled(false);
    addBookPB->setEnabled(false);
    deleteBookPB->setEnabled(false);
    searchByIdPB->setEnabled(false);
    save->setEnabled(false);
}

void mainWindow::setVisible() {
    viewGB->setEnabled(true);
    addBookPB->setEnabled(true);
    deleteBookPB->setEnabled(true);
    searchByIdPB->setEnabled(true);
    save->setEnabled(true);
}

void mainWindow::openDolphin() {
    pathToFile = QFileDialog::getOpenFileName(this, "Open .txt", projDir + "/..", tr("Text File (*.txt)"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "Not file selected");
        return;
    }
    setVisible();
    readFile();
}

void mainWindow::saveToFile() {
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    file.resize(0);
    QTextStream fileStream(&file);
    for (int i = 0; i < listOfBooks->getSize(); i++) {
        CallItem tmpItem = *listOfBooks->getElement(i);
        fileStream << QString::number(tmpItem.phoneNumber) +
                      "\n" + QString::number(tmpItem.phoneNumberSecond) +
                      "\n" + tmpItem.tariff +
                      "\n" + tmpItem.nameOfCity +
                      "\n" + QString::number(tmpItem.code) +
                      "\n" + QString::number(tmpItem.timeSeconds) +
                      "\n" + tmpItem.date + "\n";
    }
    file.close();
}

void mainWindow::addBookItem() {
    addDialog a(listOfBooks);
    a.exec();
    updateList();
    selectBookCB->setCurrentIndex((int) listOfBooks->getSize() - 1);
}

void mainWindow::readFile() {
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    listOfBooks->erase();
    while (!fileStream.atEnd()) {
        CallItem tmp;
        fileStream >> tmp.phoneNumber;
        fileStream >> tmp.phoneNumberSecond;
        fileStream >> tmp.tariff;
        fileStream >> tmp.nameOfCity;
        fileStream >> tmp.code;
        fileStream >> tmp.timeSeconds;
        fileStream >> tmp.date;
        if (!tmp.date.isEmpty())
            listOfBooks->push_back(&tmp);
    }
    file.close();
    updateList();
}

void mainWindow::updateList() {
    selectBookCB->clear();
    for (long long i = 0; i < listOfBooks->getSize(); i++) {
        CallItem tmp = *listOfBooks->getElement(i);
        QString toAdd = QString::number(tmp.phoneNumber) + " (" + tmp.date + ")";
        QVariant var = QVariant(i);
        selectBookCB->addItem(toAdd, var);
    }
    selectBookCB->setCurrentIndex(0);
    setInformation();
}

void mainWindow::setInformation() {
    if (listOfBooks->getSize() > 0 && selectBookCB->currentIndex() > -1) {
        CallItem tmpItem = *listOfBooks->getElement(selectBookCB->currentIndex());
        phoneNumberL->setText("Phone Number: " + QString::number(tmpItem.phoneNumber));
        phoneNumberSecondL->setText("Sec Phone Number: " + QString::number(tmpItem.phoneNumberSecond));
        codeL->setText("Code: " + QString::number(tmpItem.code));
        timeSecondsL->setText("Time: " + QString::number(tmpItem.timeSeconds));
        nameOfCityL->setText("City: " + tmpItem.nameOfCity);
        tariffL->setText("Tariff: " + tmpItem.tariff);
        dateL->setText("Date: " + tmpItem.date);
    } else {
        if (listOfBooks->getSize() == 0) {
            phoneNumberL->setText("Phone Number: N\\N");
            phoneNumberSecondL->setText("Sec Phone Number: N\\N");
            codeL->setText("Code: N\\N");
            timeSecondsL->setText("Time: N\\N");
            nameOfCityL->setText("City: N\\N");
            tariffL->setText("Tariff: N\\N");
            dateL->setText("Date: N\\N");
        }
    }
}

void mainWindow::deleteBtnClicked() {
    listOfBooks->pop(selectBookCB->currentIndex());
    qDebug() << listOfBooks->getSize();
    updateList();
}

void mainWindow::findById() {
    searchByIdDialog a(listOfBooks, resultPTE);
    a.exec();
}

void mainWindow::sortByName() {
    listOfBooks->mergeSort(listOfBooks, 0, listOfBooks->getSize() - 1);
    updateList();
}
