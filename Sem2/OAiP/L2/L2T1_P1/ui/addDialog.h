#ifndef L2T1_ADDDIALOG_H
#define L2T1_ADDDIALOG_H

#include <QtWidgets>
#include "../list_of_books/CallsList.h"
#include "../list_of_books/CallItem.h"

class addDialog : public QDialog {
Q_OBJECT
public:
    explicit addDialog(CallsList *a);

private:
    CallsList *listOfBooks;

    QVBoxLayout *mainBox;
    QLabel
            *phoneNumberL,
            *phoneNumberSecondL,
            *codeL,
            *timeSecondsL,
            *nameOfCityL,
            *tariffL,
            *dateL;

    QLineEdit
            *phoneNumberTE,
            *phoneNumberSecondTE,
            *codeTE,
            *timeSecondsTE,
            *nameOfCityTE,
            *tariffTE;

    QDateEdit *dateDE;

    QPushButton *findBtn;

private
    slots:

    void findButtonClicked();
};


#endif //L2T1_ADDDIALOG_H
