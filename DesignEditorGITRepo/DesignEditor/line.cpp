#include "line.h"
#include <iostream>
using namespace std;
Line::Line(int ix, int iy, int cx, int cy) : Geometry(Geometry::LINE) {
    this->setTracker(ix, iy, cx, cy);
}

void Line::draw(QPainter *painter) {
    QPen pen = painter->pen();
    pen.setWidth(this->getTrace().getWidth());

    QBrush brush (this->getTrace().getBrushStyle());
    brush.setColor(this->getColor());
    pen.setBrush(brush);

    pen.setCapStyle(this->getTrace().getCap());
    pen.setJoinStyle((this->getTrace().getJoin()));
    painter->setPen(pen);
    painter->drawLine(this->getInitialX(), this->getInitialY(), this->getCurrentX(), this->getCurrentY());
}


void Line::updatePainterPath() {
    this->getPainterPath()->moveTo(QPointF(this->getInitialX(), this->getInitialY()));
    this->getPainterPath()->lineTo(QPointF(this->getCurrentX(), this->getCurrentY()));
}
