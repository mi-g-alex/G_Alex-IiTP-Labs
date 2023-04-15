#include "searchByNameAndYear.h"

searchByNameAndYear::searchByNameAndYear(BooksList *a, QPlainTextEdit *resultPTE) {
    listOfBooks = a;
    plainET = resultPTE;

    mainBox = new QVBoxLayout;

    nameOfBookL = new QLabel("Name");
    nameOfBookTE = new QLineEdit();
    yearL = new QLabel("Year");
    yearTE = new QLineEdit();
    auto *validator = new QIntValidator();
    validator->setBottom(1);
    validator->setTop(999999999);
    yearTE->setValidator(validator);
    mainBox->addWidget(nameOfBookL);
    mainBox->addWidget(nameOfBookTE);
    mainBox->addWidget(yearL);
    mainBox->addWidget(yearTE);

    findBtn = new QPushButton("Find");
    connect(findBtn, SIGNAL(clicked(bool)), SLOT(findButtonClicked()));
    mainBox->addWidget(findBtn);

    setLayout(mainBox);
}

void searchByNameAndYear::findButtonClicked() {
    QString tmp;
    if (nameOfBookTE->text().isEmpty()) {

        QMessageBox::warning(this, "Error", "U skip fields");

    } else {
        for (int i = 0; i < listOfBooks->getSize(); i++) {
            BookItem tmpItem = *listOfBooks->getElement(i);
            if (tmpItem.nameOfBook == nameOfBookTE->text() && tmpItem.yearOfPublish == yearTE->text().toLongLong())
                tmp += "Reg Number: " + QString::number(tmpItem.regNumber) +
                       "\nName: " + tmpItem.nameOfBook +
                       "\nAuthor: " + tmpItem.authorName +
                       "\nPapers: " + QString::number(tmpItem.numberOfPapers) +
                       "\nPublish year: " + QString::number(tmpItem.yearOfPublish) +
                       "\nPublish house: " + tmpItem.publishHouse + "\n\n";
        }
        if(tmp.isEmpty()) tmp = "Not Found";
        plainET->setPlainText(tmp);
        close();
    }
}


