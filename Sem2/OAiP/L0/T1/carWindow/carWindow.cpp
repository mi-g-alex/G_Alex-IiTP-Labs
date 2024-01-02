#include "carWindow.h"

carWindow::carWindow(QWidget *) {
    *f = {15, 65};
}

void carWindow::paintEvent(QPaintEvent *pe) {
    static bool was = true;
    QWidget::paintEvent(pe);
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);

    painter.drawRect(int(f->rx()), int(f->ry()), 105, 60);
    if (f->ry() > 10 && f->ry() <= 66) {
        was ? moveRect::moveUP(f, 0.015) : moveRect::moveDown(f, 0.015);
    } else {
        if (was) f->ry() = 11;
        else f->ry() = 65;
        was = !was;

    }


    painter.drawRect(15, 128, 165, 15);
    painter.drawRect(127, 65, 52, 60);

    painter.setBrush(Qt::white);

    painter.drawEllipse(15, 146, 30, 30);
    painter.drawEllipse(50, 146, 30, 30);
    painter.drawEllipse(144, 146, 30, 30);

    painter.drawRect(135, 72, 30, 30);

    update();
}