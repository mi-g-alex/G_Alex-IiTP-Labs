#include "mainWindow.h"
#include "searchByIdDialog.h"

#include <utility>

mainWindow::mainWindow(QString s) {
    listOfBooks = new BooksList;
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
    regNumberL = new QLabel("Reg Number: N\\N");
    bookNameL = new QLabel("Name: N\\N");
    authorNameL = new QLabel("Author: N\\N");
    numberOfPapersL = new QLabel("Papers: N\\N");
    yearOfPublishL = new QLabel("Publish year: N\\N");
    publishHouseL = new QLabel("Publish house: N\\N");

    viewVL->addWidget(selectBookCB);
    viewVL->addWidget(regNumberL);
    viewVL->addWidget(bookNameL);
    viewVL->addWidget(authorNameL);
    viewVL->addWidget(numberOfPapersL);
    viewVL->addWidget(yearOfPublishL);
    viewVL->addWidget(publishHouseL);
    viewVL->addSpacing(5);

    viewHB = new QHBoxLayout;
    addBookPB = new QPushButton("Add...");
    connect(addBookPB, SIGNAL(clicked(bool)), SLOT(addBookItem()));
    deleteBookPB = new QPushButton("Delete Current");
    connect(deleteBookPB, SIGNAL(clicked(bool)), SLOT(deleteBtnClicked()));
    searchByIdPB = new QPushButton("Search by book RegNumber");
    connect(searchByIdPB, SIGNAL(clicked(bool)), SLOT(findById()));
    searchByNameYearPB = new QPushButton("Search by Name and Year");
    connect(searchByNameYearPB, SIGNAL(clicked(bool)), SLOT(findByNameAndYear()));

    viewHB->addWidget(addBookPB);
    viewHB->addWidget(deleteBookPB);

    sortMenuHB = new QHBoxLayout;
    sortByPB = new QPushButton("Sort by Name");
    connect(sortByPB, SIGNAL(clicked(bool)), SLOT(sortByName()));

    sortMenuHB->addWidget(sortByPB);

    viewVL->addLayout(viewHB);
    viewVL->addWidget(searchByIdPB);
    viewVL->addWidget(searchByNameYearPB);
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
    searchByNameYearPB->setEnabled(false);
    save->setEnabled(false);
}

void mainWindow::setVisible() {
    viewGB->setEnabled(true);
    addBookPB->setEnabled(true);
    deleteBookPB->setEnabled(true);
    searchByIdPB->setEnabled(true);
    searchByNameYearPB->setEnabled(true);
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
            BookItem tmpItem = *listOfBooks->getElement(i);
            fileStream << QString::number(tmpItem.regNumber) +
                       "\n" + tmpItem.nameOfBook +
                       "\n" + tmpItem.authorName +
                       "\n" + QString::number(tmpItem.numberOfPapers) +
                       "\n" + QString::number(tmpItem.yearOfPublish) +
                       "\n" + tmpItem.publishHouse + "\n";
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
        BookItem tmp;
        fileStream >> tmp.regNumber;
        fileStream >> tmp.nameOfBook;
        fileStream >> tmp.authorName;
        fileStream >> tmp.numberOfPapers;
        fileStream >> tmp.yearOfPublish;
        fileStream >> tmp.publishHouse;
        if (!tmp.publishHouse.isEmpty())
            listOfBooks->push_back(&tmp);
    }
    file.close();
    updateList();
}

void mainWindow::updateList() {
    selectBookCB->clear();
    for (long long i = 0; i < listOfBooks->getSize(); i++) {
        BookItem tmp = *listOfBooks->getElement(i);
        QString toAdd = tmp.nameOfBook + " (" + QString::number(tmp.regNumber) + ")";
        QVariant var = QVariant(i);
        selectBookCB->addItem(toAdd, var);
    }
    selectBookCB->setCurrentIndex(0);
    setInformation();
}

void mainWindow::setInformation() {
    if (listOfBooks->getSize() > 0 && selectBookCB->currentIndex() > -1) {
        BookItem tmpItem = *listOfBooks->getElement(selectBookCB->currentIndex());
        regNumberL->setText("Reg Number: " + QString::number(tmpItem.regNumber));
        bookNameL->setText("Name: " + tmpItem.nameOfBook);
        authorNameL->setText("Author: " + tmpItem.authorName);
        numberOfPapersL->setText("Papers: " + QString::number(tmpItem.numberOfPapers));
        yearOfPublishL->setText("Publish year: " + QString::number(tmpItem.yearOfPublish));
        publishHouseL->setText("Publish house: " + tmpItem.publishHouse);
    } else {
        if (listOfBooks->getSize() == 0) {
            regNumberL->setText("Reg Number: N\\N");
            bookNameL->setText("Name: N\\N");
            authorNameL->setText("Author: N\\N");
            numberOfPapersL->setText("Papers: N\\N");
            yearOfPublishL->setText("Publish year: N\\N");
            publishHouseL->setText("Publish house: N\\N");
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

void mainWindow::findByNameAndYear() {
    searchByNameAndYear a(listOfBooks, resultPTE);
    a.exec();
}

void mainWindow::sortByName() {
    listOfBooks->mergeSort(listOfBooks, 0, listOfBooks->getSize() - 1);
    updateList();
}
