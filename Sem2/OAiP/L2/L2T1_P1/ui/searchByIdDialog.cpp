#include "searchByIdDialog.h"

searchByIdDialog::searchByIdDialog(CallsList *a, QPlainTextEdit *resultPTE) {
    listOfBooks = a;
    plainET = resultPTE;

    mainBox = new QVBoxLayout;

    regNumberL = new QLabel("Phone Number");
    regNumberTE = new QLineEdit();
    regNumberTE->setInputMask("0000000000200");

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
        CallItem *tmpItem = listOfBooks->findByRegNumber(regNumberTE->text().toLongLong());
        if (tmpItem) {
            QString tmp = "Phone Number: " + QString::number(tmpItem->phoneNumber) +
                          "\nSec Prone Number" +
                          "\nTariff: " + tmpItem->tariff +
                          "\nCity Name: " + tmpItem->nameOfCity +
                          "\nCode: " + QString::number(tmpItem->code) +
                          "\nTime (Seconds): " + QString::number(tmpItem->timeSeconds) +
                          "\nDate: " + tmpItem->date;
            plainET->setPlainText(tmp);
            close();
        } else {
            QMessageBox::warning(this, "Error", "Book with this RegNumber not found");
        }
    }
}
