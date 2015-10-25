#include "ellipse.h"
#include <iostream>
using namespace std;
Ellipse::Ellipse(int ix, int iy, int cx, int cy) : Geometry(Geometry::ELLIPSE) {
    this->setTracker(ix, iy, cx, cy);
}

void Ellipse::draw(QPainter *painter) {
    QPen pen = painter->pen();
    pen.setWidth(this->getTrace().getWidth());
    //pen.setColor(this->getColor());

    QBrush brush (this->getTrace().getBrushStyle());
    brush.setColor(this->getColor());
    pen.setBrush(brush);
    pen.setCapStyle(this->getTrace().getCap());
    pen.setJoinStyle((this->getTrace().getJoin()));
    painter->setPen(pen);
    int width = this->getCurrentX() - this->getInitialX();
    int height = this->getCurrentY() - this->getInitialY();

    painter->drawEllipse(this->getInitialX(), this->getInitialY(), width, height);

}


void Ellipse::updatePainterPath() {

    int width = this->getCurrentX() - this->getInitialX();
    int height = this->getCurrentY() - this->getInitialY();

    int left = 0;
    int top = 0;
    int right = 0;
    int bottom = 0;

    if(this->getInitialX() > this->getCurrentX()) {
        left = this->getCurrentX();
        right = this->getInitialX();
    } else {

        left = this->getInitialX();
        right = this->getCurrentX();
    }

    if(this->getInitialY() > this->getCurrentY()) {
        top = this->getCurrentY();
        bottom = this->getInitialY();
    } else {
        top = this->getInitialY();
        bottom = this->getCurrentY();
    }

    this->getPainterPath()->addEllipse(left, top, right - left, bottom - top);

}
