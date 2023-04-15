#ifndef L2T1_SEARCHBYIDDIALOG_H
#define L2T1_SEARCHBYIDDIALOG_H

#include <QtWidgets>
#include "../list_of_books/BooksList.h"
#include "../list_of_books/BookItem.h"

class searchByIdDialog : public QDialog {
Q_OBJECT
public:
    explicit searchByIdDialog(BooksList *a, QPlainTextEdit *resultPTE);

private:
    BooksList *listOfBooks;
    QVBoxLayout *mainBox;
    QLabel *regNumberL;
    QLineEdit *regNumberTE;
    QPushButton *findBtn;
    QPlainTextEdit *plainET;

private
    slots:

    void findButtonClicked();
};


#endif
