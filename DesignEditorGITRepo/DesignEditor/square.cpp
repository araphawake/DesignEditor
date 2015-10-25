#include "square.h"


Square::Square(int ix, int iy) : Geometry(Geometry::SQUARE) {
    this->setTracker(ix, iy, ix, iy);
}

void Square::draw(QPainter *painter) {
    QPen pen = painter->pen();
    pen.setWidth(this->getTrace().getWidth());

    QBrush brush (this->getTrace().getBrushStyle());
    brush.setColor(this->getColor());
    pen.setBrush(brush);

    pen.setCapStyle(this->getTrace().getCap());
    pen.setJoinStyle((this->getTrace().getJoin()));

    painter->setPen(pen);
    int side = this->getCurrentX() - this->getInitialX();

    painter->drawRect(this->getInitialX(), this->getInitialY(), side, side);

}

void Square::updatePainterPath() {

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

    this->getPainterPath()->addRect(QRectF(left, top, right - left, right - left));
}

