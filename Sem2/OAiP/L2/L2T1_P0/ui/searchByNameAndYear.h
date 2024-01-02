#ifndef L2T1_SEARCHBYNAMEANDYEAR_H
#define L2T1_SEARCHBYNAMEANDYEAR_H


#include <QtWidgets>
#include "../list_of_books/BooksList.h"
#include "../list_of_books/BookItem.h"

class searchByNameAndYear : public QDialog {
Q_OBJECT
public:
    explicit searchByNameAndYear(BooksList *a, QPlainTextEdit *resultPTE);

private:
    BooksList *listOfBooks;
    QVBoxLayout *mainBox;
    QLabel *nameOfBookL, *yearL;
    QLineEdit *nameOfBookTE, *yearTE;
    QPushButton *findBtn;
    QPlainTextEdit *plainET;

private
    slots:

    void findButtonClicked();
};


#endif

