#include "polyline.h"
#include <iostream>
using namespace std;
Polyline::Polyline(int ix, int iy) : Geometry(Geometry::POLYLINE) {
    this->setTracker(ix, iy, ix, iy);
    this->points.append(new QPoint(ix, iy));
    this->isBlank = false;
}

void Polyline::draw(QPainter *painter) {
    const int size = this->points.length();

    QPen pen = painter->pen();
    pen.setWidth(this->getTrace().getWidth());

    QBrush brush (this->getTrace().getBrushStyle());
    brush.setColor(this->getColor());
    pen.setBrush(brush);

    pen.setCapStyle(this->getTrace().getCap());
    pen.setJoinStyle((this->getTrace().getJoin()));
    painter->setPen(pen);

    if(this->isBlank == false) {
        if(size > 1) {

            QVector<QPoint> polypts;

            for(int index = 0; index < size; index++) {
                polypts << *(this->points.at(index));
            }

            painter->drawPolyline(polypts);
            painter->drawLine(this->link.x(), this->link.y(), this->getCurrentX(), this->getCurrentY());

        } else {
            painter->drawLine(this->points.first()->x(), this->points.first()->y(), this->getCurrentX(), this->getCurrentY());
        }
    }
}

void Polyline::update(int x, int y) {
    this->points.append(new QPoint(x, y));
    this->link.setX(x);
    this->link.setY(y);
}

int Polyline::getLastX() {
    return this->points.back()->x();
}

int Polyline::getLastY() {
    return this->points.back()->y();
}

bool Polyline::checkVoid() const {
    return (this->points.length() == 0);
}

bool Polyline::checkBlank() const {
    return this->isBlank;
}
void Polyline::reset() {
    this->isBlank = true;
    this->points.clear();
}

void Polyline::updatePainterPath() {

    if(this->points.length() > 0) {
        this->getPainterPath()->moveTo(QPointF(*this->points.first()));

        QList<QPoint*>::iterator i;
        for (i = this->points.begin(); i != this->points.end(); i++)
            this->getPainterPath()->lineTo(QPointF(*(*i)));

        this->getPainterPath()->lineTo(QPointF(*(this->points.last())));

    }
}
