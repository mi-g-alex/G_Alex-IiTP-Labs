#include "moveRect.h"

void moveRect::moveUP(QPointF *point, qreal y) {
    point->ry() -= y;
}

void moveRect::moveDown(QPointF *point, qreal y) {
    point->ry() += y;
}

void moveRect::moveLeft(QPointF *point, qreal x) {
    point->rx() -= x;
}

void moveRect::moveRight(QPointF *point, qreal x) {
    point->rx() += x;
}


