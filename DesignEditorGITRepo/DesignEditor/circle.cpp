#include "circle.h"


Circle::Circle(int radius) : Ellipse(radius, radius, radius, radius) { }

void Circle::draw(QPainter *painter) {
    QPen pen = painter->pen();
    pen.setWidth(this->getTrace().getWidth());

    QBrush brush (this->getTrace().getBrushStyle());
    brush.setColor(this->getColor());
    pen.setBrush(brush);

    pen.setCapStyle(this->getTrace().getCap());
    pen.setJoinStyle((this->getTrace().getJoin()));
    painter->setPen(pen);
    this->radius = this->getCurrentX() - this->getInitialX();

    painter->drawEllipse(this->getInitialX(), this->getInitialY(), radius, radius);
}


void Circle::updatePainterPath() {

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
