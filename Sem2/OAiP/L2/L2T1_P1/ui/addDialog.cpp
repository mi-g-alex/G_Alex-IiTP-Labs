#include "addDialog.h"

addDialog::addDialog(CallsList *a) {
    listOfBooks = a;

    mainBox = new QVBoxLayout;
    phoneNumberL = new QLabel("Phone Number:");
    phoneNumberSecondL = new QLabel("Caller Phone Number:");
    codeL = new QLabel("Code:");
    timeSecondsL = new QLabel("Time (Seconds):");
    nameOfCityL = new QLabel("City Name:");
    tariffL = new QLabel("Tariff Name:");
    dateL = new QLabel("Date:");

    auto *validator = new QIntValidator();

    validator->setBottom(1);
    validator->setTop(999999999);

    phoneNumberTE = new QLineEdit();
    phoneNumberTE->setInputMask("000000000000");
    phoneNumberSecondTE = new QLineEdit();
    phoneNumberSecondTE->setInputMask("000000000000");
    codeTE = new QLineEdit();
    codeTE->setValidator(validator);
    timeSecondsTE = new QLineEdit();
    timeSecondsTE->setValidator(validator);
    nameOfCityTE = new QLineEdit();
    tariffTE = new QLineEdit();
    dateDE = new QDateEdit;
    dateDE->setCalendarPopup(true);

    mainBox->addWidget(phoneNumberL);
    mainBox->addWidget(phoneNumberTE);
    mainBox->addWidget(phoneNumberSecondL);
    mainBox->addWidget(phoneNumberSecondTE);
    mainBox->addWidget(codeL);
    mainBox->addWidget(codeTE);
    mainBox->addWidget(timeSecondsL);
    mainBox->addWidget(timeSecondsTE);
    mainBox->addWidget(nameOfCityL);
    mainBox->addWidget(nameOfCityTE);
    mainBox->addWidget(tariffL);
    mainBox->addWidget(tariffTE);
    mainBox->addWidget(dateL);
    mainBox->addWidget(dateDE);

    findBtn = new QPushButton("Add");
    connect(findBtn, SIGNAL(clicked(bool)), SLOT(findButtonClicked()));
    mainBox->addWidget(findBtn);

    setLayout(mainBox);
}

void addDialog::findButtonClicked() {
    if (phoneNumberTE->text().isEmpty() ||
        phoneNumberSecondTE->text().isEmpty() ||
        codeTE->text().isEmpty() ||
        timeSecondsTE->text().isEmpty() ||
        nameOfCityTE->text().isEmpty() ||
        tariffTE->text().isEmpty() ||
        dateDE->date().isNull()) {

        QMessageBox::warning(this, "Error", "U skip same fields");

    } else {

        if (!listOfBooks->findByRegNumber(phoneNumberTE->text().toLongLong())) {
            CallItem itemBook;
            itemBook.phoneNumber = phoneNumberTE->text().toLongLong();
            itemBook.nameOfCity = nameOfCityTE->text();
            itemBook.tariff = tariffTE->text();
            itemBook.timeSeconds = timeSecondsTE->text().toLongLong();
            itemBook.phoneNumberSecond = phoneNumberSecondTE->text().toLongLong();
            itemBook.code = codeTE->text().toLongLong();
            itemBook.date = dateDE->date().toString("dd.MM.yyyy");
            listOfBooks->push_back(&itemBook);
            close();
        } else {
            QMessageBox::warning(this, "Error", "Book with this RegNumber already exists");
        }
    }
}
