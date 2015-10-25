#include "geometry.h"

Geometry::Geometry(shape type) {
    this->shapeType = type;
    this->tracker.currentX = 0;
    this->tracker.currentY = 0;
    this->tracker.initialX = 0;
    this->tracker.initialY = 0;
    this->tracker.transPointX = 0;
    this->tracker.transPointY = 0;
    this->color = Qt::black;
    this->path = new QPainterPath();
    this->trace = Trace ();
    this->isSelected = false;
    this->alreadyAppended = false;

}

Geometry::Geometry(int ix, int iy, int cx, int cy, shape type) {
    this->shapeType = type;
    this->tracker.currentX = cx;
    this->tracker.currentY = cy;
    this->tracker.initialX = ix;
    this->tracker.initialY = iy;
    this->tracker.transPointX = cx;
    this->tracker.transPointY = cy;
    this->color = Qt::black;
    this->trace = Trace ();
    this->path = new QPainterPath();
    this->isSelected = false;
    this->alreadyAppended = false;
}

QPainterPath * Geometry::getPainterPath() const {
   return this->path;
}

void Geometry::updatePainterPath() { }

Geometry::shape Geometry::getShapeType() {
   return this->shapeType;
}

void Geometry::setPainterPath(QPainterPath * p) {
    this->path = p;
}

bool Geometry::isAppended() {
    return this->alreadyAppended;
}

void Geometry::setAppended(bool state) {
    this->alreadyAppended = state;
}

void Geometry::setTracker(int ix, int iy, int cx, int cy) {
    this->tracker.initialX = ix;
    this->tracker.initialY = iy;
    this->tracker.currentX = cx;
    this->tracker.currentY = cy;
    this->tracker.transPointX = cx;
    this->tracker.transPointY = cy;
}

int Geometry::getTransX() const {
    return this->tracker.transPointX;
}

int Geometry::getTransY() const {
    return this->tracker.transPointY;
}

void Geometry::setTransX(int p) {
    this->tracker.transPointX = p;
}

void Geometry::setTransY(int p) {
    this->tracker.transPointY = p;
}

void Geometry::updateAfterTranslation() {
    delete this->path;
    this->path = NULL;
    this->path = new QPainterPath();
}

void Geometry::setColor(QColor c) {
    this->color = c;
}

QColor Geometry::getColor() {
    return this->color;
}

int Geometry::getInitialX() const {
    return this->tracker.initialX;
}

int Geometry::getInitialY() const {
    return this->tracker.initialY;
}

int Geometry::getCurrentX() const {
    return this->tracker.currentX;
}

int Geometry::getCurrentY() const {
    return this->tracker.currentY;
}

void Geometry::setInitialX(int ix) {
    this->tracker.initialX = ix;
}

void Geometry::setSelected(bool isSelected) {
    this->isSelected = isSelected;
}

void Geometry::setInitialY(int iy) {
    this->tracker.initialY = iy;
}

void Geometry::setCurrentX(int cx) {
    this->tracker.currentX = cx;
}

void Geometry::setCurrentY(int cy) {
    this->tracker.currentY = cy;
}

void Geometry::setShape(shape s) {
    this->shapeType = s;
}

Trace Geometry::getTrace() const {
    return this->trace;
}

void Geometry::updateTrace(Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join, int width, QBrush brush, Qt::BrushStyle brushStyle) {

}

void Geometry::updateCap(Qt::PenCapStyle cap) {
    this->trace.setCap(cap);
}

void Geometry::updateJoin(Qt::PenJoinStyle join) {
    this->trace.setJoin(join);
}

void Geometry::updateWidth(int width) {
    if(width < 40)
        this->trace.setWidth(width);
}

void Geometry::updateBrush(Qt::BrushStyle brushStyle) {

    this->trace.setBrushStyle(brushStyle);
}

void Geometry::updateStyle(Qt::PenStyle style) {

}

bool Geometry::getSelectedState() const { return this->isSelected; }
