#ifndef L2T1_ADDDIALOG_H
#define L2T1_ADDDIALOG_H

#include <QtWidgets>
#include "../list_of_books/BooksList.h"
#include "../list_of_books/BookItem.h"

class addDialog : public QDialog {
Q_OBJECT
public:
    explicit addDialog(BooksList *a);

private:
    BooksList *listOfBooks;

    QVBoxLayout *mainBox;
    QLabel
            *regNumberL,
            *bookNameL,
            *authorNameL,
            *numberOfPapersL,
            *yearOfPublishL,
            *publishHouseL;

    QLineEdit
            *regNumberTE,
            *bookNameTE,
            *authorNameTE,
            *numberOfPapersTE,
            *yearOfPublishTE,
            *publishHouseTE;

    QPushButton *findBtn;

private
    slots:
            void findButtonClicked();
};


#endif //L2T1_ADDDIALOG_H
