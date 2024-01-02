#include "addDialog.h"

addDialog::addDialog(BooksList *a) {
    listOfBooks = a;

    mainBox = new QVBoxLayout;
    regNumberL = new QLabel("Reg Number:");
    bookNameL = new QLabel("Name:");
    authorNameL = new QLabel("Author:");
    numberOfPapersL = new QLabel("Papers:");
    yearOfPublishL = new QLabel("Publish year:");
    publishHouseL = new QLabel("Publish house:");

    regNumberTE = new QLineEdit();
    auto *validator = new QIntValidator();
    validator->setBottom(1);
    validator->setTop(999999999);
    bookNameTE = new QLineEdit();
    regNumberTE->setValidator(validator);
    authorNameTE = new QLineEdit();
    numberOfPapersTE = new QLineEdit();
    numberOfPapersTE->setValidator(validator);
    yearOfPublishTE = new QLineEdit();
    auto *validatorNew = new QIntValidator();
    validatorNew->setBottom(-9999);
    validatorNew->setTop(9999);
    yearOfPublishTE->setValidator(validatorNew);
    publishHouseTE = new QLineEdit();

    mainBox->addWidget(regNumberL);
    mainBox->addWidget(regNumberTE);
    mainBox->addWidget(bookNameL);
    mainBox->addWidget(bookNameTE);
    mainBox->addWidget(authorNameL);
    mainBox->addWidget(authorNameTE);
    mainBox->addWidget(numberOfPapersL);
    mainBox->addWidget(numberOfPapersTE);
    mainBox->addWidget(yearOfPublishL);
    mainBox->addWidget(yearOfPublishTE);
    mainBox->addWidget(publishHouseL);
    mainBox->addWidget(publishHouseTE);

    findBtn = new QPushButton("Add");
    connect(findBtn, SIGNAL(clicked(bool)), SLOT(findButtonClicked()));
    mainBox->addWidget(findBtn);

    setLayout(mainBox);
}

void addDialog::findButtonClicked() {
    if (regNumberTE->text().isEmpty() ||
        bookNameTE->text().isEmpty() ||
        authorNameTE->text().isEmpty() ||
        numberOfPapersTE->text().isEmpty() ||
        yearOfPublishTE->text().isEmpty() ||
        publishHouseTE->text().isEmpty()) {

        QMessageBox::warning(this, "Error", "U skip same fields");

    } else {

        if (!listOfBooks->findByRegNumber(regNumberTE->text().toLongLong())) {
            BookItem itemBook;
            itemBook.regNumber = regNumberTE->text().toLongLong();
            itemBook.yearOfPublish = yearOfPublishTE->text().toLongLong();
            itemBook.publishHouse = publishHouseTE->text();
            itemBook.numberOfPapers = numberOfPapersTE->text().toLongLong();
            itemBook.nameOfBook = bookNameTE->text();
            itemBook.authorName = authorNameTE->text();
            listOfBooks->push_back(&itemBook);
           close();
        } else {
            QMessageBox::warning(this, "Error", "Book with this RegNumber already exists");
        }
    }
}
