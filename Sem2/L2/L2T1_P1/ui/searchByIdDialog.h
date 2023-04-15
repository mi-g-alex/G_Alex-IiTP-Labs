#ifndef L2T1_SEARCHBYIDDIALOG_H
#define L2T1_SEARCHBYIDDIALOG_H

#include <QtWidgets>
#include "../list_of_books/CallsList.h"
#include "../list_of_books/CallItem.h"

class searchByIdDialog : public QDialog {
Q_OBJECT
public:
    explicit searchByIdDialog(CallsList *a, QPlainTextEdit *resultPTE);

private:
    CallsList *listOfBooks;
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
