#pragma once

#include <QtWidgets>
#include "../moveRect/moveRect.h"

class figureWindow : public QWidget, private moveRect {
public:
    explicit figureWindow(QWidget *pobj = nullptr);
protected:
    void paintEvent(QPaintEvent* pe);

private:
    QPointF *f = new QPointF;
};
