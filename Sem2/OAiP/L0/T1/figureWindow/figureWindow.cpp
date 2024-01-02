#include "figureWindow.h"

figureWindow::figureWindow(QWidget *pobj) {
    *f = {30, 100};
}

void figureWindow::paintEvent(QPaintEvent *pe) {
    QWidget::paintEvent(pe);
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(int(f->rx()), int(f->ry()), 105, 60);

    if (int(f->ry()) == -60) f->ry() = QWidget::height();

    moveRect::moveUP(f, 0.015);

    update();
}
