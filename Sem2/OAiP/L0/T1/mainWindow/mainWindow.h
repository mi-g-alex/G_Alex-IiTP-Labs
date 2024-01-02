#pragma once

#include <QtWidgets>
#include "../figureWindow/figureWindow.h"
#include "../carWindow/carWindow.h"

class mainWindow : public QWidget {
Q_OBJECT
public:
    explicit mainWindow(QWidget *pobj = nullptr);

private:
    figureWindow *figure = new figureWindow;
    carWindow *car = new carWindow;

private slots:
    void on_closeButton_clicked();

    void on_figureButton_clicked();

    void on_carButton_clicked();

protected:
};
