#ifndef L2T1_MAINWINDOW_H
#define L2T1_MAINWINDOW_H

#include <QtWidgets>
#include "../list_of_books/BookItem.h"
#include "../list_of_books/BooksList.h"
#include "addDialog.h"
#include "searchByIdDialog.h"
#include "searchByNameAndYear.h"

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
            *regNumberL,
            *bookNameL,
            *authorNameL,
            *numberOfPapersL,
            *yearOfPublishL,
            *publishHouseL;

    QHBoxLayout *viewHB;

    QPushButton
            *addBookPB,
            *deleteBookPB,
            *searchByIdPB,
            *searchByNameYearPB;

    QHBoxLayout *sortMenuHB;
    QPushButton *sortByPB;

protected slots:

    void openDolphin();

    void saveToFile();

    void addBookItem();

    void setInformation();

    void deleteBtnClicked();

    void findById();

    void findByNameAndYear();

    void sortByName();

private:
    QString pathToFile;
    QString projDir;
    QFile file;
    BooksList *listOfBooks;

    void setNotVisible();

    void setVisible();

    void readFile();

    void updateList();
};


#endif
