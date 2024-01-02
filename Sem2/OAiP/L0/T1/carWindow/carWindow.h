#pragma once

#include <QtWidgets>
#include "../moveRect/moveRect.h"

class carWindow : public QWidget, private moveRect {
public:
    explicit carWindow(QWidget *pobj = nullptr);
protected:
    void paintEvent(QPaintEvent* pe);
private:
    QPointF *f = new QPointF;
};
