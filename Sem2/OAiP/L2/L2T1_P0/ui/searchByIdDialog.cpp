#include "searchByIdDialog.h"

searchByIdDialog::searchByIdDialog(BooksList *a, QPlainTextEdit *resultPTE) {
    listOfBooks = a;
    plainET = resultPTE;

    mainBox = new QVBoxLayout;

    regNumberL = new QLabel("Reg Number");
    regNumberTE = new QLineEdit();
    auto *validator = new QIntValidator();
    validator->setBottom(1);
    validator->setTop(999999999);

    mainBox->addWidget(regNumberL);
    mainBox->addWidget(regNumberTE);

    findBtn = new QPushButton("Find");
    connect(findBtn, SIGNAL(clicked(bool)), SLOT(findButtonClicked()));
    mainBox->addWidget(findBtn);

    setLayout(mainBox);
}

void searchByIdDialog::findButtonClicked() {
    if (regNumberTE->text().isEmpty()) {

        QMessageBox::warning(this, "Error", "U skip field");

    } else {
        BookItem *tmpItem = listOfBooks->findByRegNumber(regNumberTE->text().toLongLong());
        if (tmpItem) {
            QString tmp = "Reg Number: " + QString::number(tmpItem->regNumber) +
            "\nName: " + tmpItem->nameOfBook +
            "\nAuthor: " + tmpItem->authorName +
            "\nPapers: " + QString::number(tmpItem->numberOfPapers) +
            "\nPublish year: " + QString::number(tmpItem->yearOfPublish) +
            "\nPublish house: " + tmpItem->publishHouse;
            plainET->setPlainText(tmp);
            close();
        } else {
            QMessageBox::warning(this, "Error", "Book with this RegNumber not found");
        }
    }
}
