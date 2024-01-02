#ifndef L2T1_MAINWINDOW_H
#define L2T1_MAINWINDOW_H

#include <QtWidgets>
#include "../list_of_books/CallItem.h"
#include "../list_of_books/CallsList.h"
#include "addDialog.h"
#include "searchByIdDialog.h"

class mainWindow : public QWidget {
Q_OBJECT
public:
    explicit mainWindow(QString s);

private:
    QHBoxLayout *mainHB;
    QPlainTextEdit *resultPTE;

    QVBoxLayout *actionsMainVL;
    QGroupBox *viewGB;
    QVBoxLayout *viewVL;
    QComboBox *selectBookCB;

    QHBoxLayout *openSaveHB;
    QPushButton *open;
    QPushButton *save;

    QLabel
            *phoneNumberL,
            *phoneNumberSecondL,
            *codeL,
            *timeSecondsL,
            *nameOfCityL,
            *tariffL,
            *dateL;

    QHBoxLayout *viewHB;

    QPushButton
            *addBookPB,
            *deleteBookPB,
            *searchByIdPB;

    QHBoxLayout *sortMenuHB;
    QPushButton *sortByPB;

protected slots:

    void openDolphin();

    void saveToFile();

    void addBookItem();

    void setInformation();

    void deleteBtnClicked();

    void findById();

    void sortByName();

private:
    QString pathToFile;
    QString projDir;
    QFile file;
    CallsList *listOfBooks;

    void setNotVisible();

    void setVisible();

    void readFile();

    void updateList();
};


#endif //L2T1_MAINWINDOW_H
