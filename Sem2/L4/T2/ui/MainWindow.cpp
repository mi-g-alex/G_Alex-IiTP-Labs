#include "MainWindow.h"

MainWindow::MainWindow() {
    buttonsHB->addWidget(memcpyPB);
    buttonsHB->addWidget(memmovePB);
    buttonsHB->addWidget(strcpyPB);
    buttonsHB->addWidget(strncpyPB);
    buttonsHB->addWidget(strcatPB);
    buttonsHB->addWidget(strncatPB);
    buttonsHB->addWidget(memcmpPB);
    buttonsHB->addWidget(strcmpPB);
    buttonsHB->addWidget(strncmpPB);
    buttonsHB->addWidget(memsetPB);
    buttonsHB->addWidget(strerrorPB);
    buttonsHB->addWidget(strlenPB);
    buttonsHB->addWidget(textEdit);
    buttonsHB->addWidget(setS1PB);
    buttonsHB->addWidget(setS2PB);
    buttonsHB->addWidget(resetPB);

    connect(memcpyPB, SIGNAL(clicked(bool)), SLOT(memcpyClicked()));
    connect(memmovePB, SIGNAL(clicked(bool)), SLOT(memmoveClicked()));
    connect(strcpyPB, SIGNAL(clicked(bool)), SLOT(strcpyClicked()));
    connect(strncpyPB, SIGNAL(clicked(bool)), SLOT(strncpyClicked()));
    connect(strcatPB, SIGNAL(clicked(bool)), SLOT(strcatClicked()));
    connect(strncatPB, SIGNAL(clicked(bool)), SLOT(strncatClicked()));
    connect(memcmpPB, SIGNAL(clicked(bool)), SLOT(memcmpClicked()));
    connect(strcmpPB, SIGNAL(clicked(bool)), SLOT(strcmpClicked()));
    connect(strncmpPB, SIGNAL(clicked(bool)), SLOT(strncmpClicked()));
    connect(memsetPB, SIGNAL(clicked(bool)), SLOT(memsetClicked()));
    connect(strerrorPB, SIGNAL(clicked(bool)), SLOT(strerrorClicked()));
    connect(strlenPB, SIGNAL(clicked(bool)), SLOT(strlenClicked()));
    connect(setS1PB, SIGNAL(clicked(bool)), SLOT(setS1Clicked()));
    connect(setS2PB, SIGNAL(clicked(bool)), SLOT(setS2Clicked()));
    connect(resetPB, SIGNAL(clicked(bool)), SLOT(resetClicked()));

    resultHB->addStretch(100000000);
    resultHB->addWidget(s1L);
    resultHB->addWidget(s2L);
    resultHB->addStretch(100000000);

    mainVB->addLayout(buttonsHB, 1);
    mainVB->addSpacing(20);

    mainVB->addLayout(resultHB, 1);

    setLayout(mainVB);

    update();
}


void MainWindow::memcpyClicked() {
    my_memcpy(s1.data(), s2.data(), my_strlen(s1.data()));
    update();
}

void MainWindow::memmoveClicked() {
    my_memmove(s1.data(), s2.data(), my_strlen(s1.data()));
    update();
}

void MainWindow::strcpyClicked() {
    my_strcpy(s1.data(), s2.data());
    update();
}

void MainWindow::strncpyClicked() {
    my_strncpy(s1.data(), s2.data(), my_strlen(s1.data()));
    update();
}

void MainWindow::strcatClicked() {
    s1.reserve(my_strlen(s1.data()) + my_strlen(s2.data()));
    my_strcat(s1.data(), s2.data());

    update();
}

void MainWindow::strncatClicked() {
    s1.reserve(my_strlen(s1.data()) + my_strlen(s2.data()));
    my_strncat(s1.data(), s2.data(), my_strlen(s1.data()));
    update();
}

void MainWindow::memcmpClicked() {
    size_t i = my_memcmp(s1.data(), s2.data(), my_strlen(s1.data()) - 3);
    MyString a;
    if (i == -1) a = "S1<S2";
    if (i == 1) a = "S1>S2";
    if (i == 0) a = "S1=S2";

    QMessageBox::information(this, "Result", QString(a.data()));

    update();
}

void MainWindow::strcmpClicked() {
    size_t i = my_strcmp(s1.data(), s2.data());
    MyString a;
    if (i == -1) a = "S1<S2";
    if (i == 1) a = "S1>S2";
    if (i == 0) a = "S1=S2";

    QMessageBox::information(this, "Result", QString(a.data()));

    update();
}

void MainWindow::strncmpClicked() {
    size_t i = my_strncmp(s1.data(), s2.data(), my_strlen(s1.data()) - 3);
    MyString a;
    if (i == -1) a = "S1<S2";
    if (i == 1) a = "S1>S2";
    if (i == 0) a = "S1=S2";

    QMessageBox::information(this, "Result", QString(a.data()));

    update();
}

void MainWindow::memsetClicked() {
    int t = textEdit->text().toInt();
    memset(s1.data(), t, 10);
    update();
}

void MainWindow::strerrorClicked() {
    int t = textEdit->text().toInt();
    QMessageBox::information(this, "1", QString(strerror(t)));
}

void MainWindow::strlenClicked() {
    qDebug() << QString::number(my_strlen(s1.data()));
    QMessageBox::information(this, "Result", "s1: " + QString::number(my_strlen(s1.data())) + "\n"
                                             + "s2: " + QString::number(my_strlen(s2.data())));

}

void MainWindow::setS1Clicked() {
    s1 = textEdit->text().toStdString().data();
    update();
}

void MainWindow::setS2Clicked() {
    s2 = textEdit->text().toStdString().data();
    update();
}

void MainWindow::update() {
    s1L->setText("S1 - " + QString(s1.data()));
    s2L->setText("S2 - " + QString(s2.data()));
}

void MainWindow::resetClicked() {
    s1 = "12345";
    s2 = "06789";
    update();
}


