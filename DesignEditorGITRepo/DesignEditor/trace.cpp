#include "trace.h"
#include <iostream>

using namespace std;
Trace::Trace() {
    this->cap = Qt::SquareCap;
    this->style = Qt::SolidLine;
    this->join = Qt::BevelJoin;
    this->width = 0;
    this->brushStyle = Qt::VerPattern;
    this->brush = QBrush (this->brushStyle);
}

Trace::Trace(Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join, int width, Qt::BrushStyle brushStyle) {
    this->cap = cap;
    this->style = style;
    this->join = join;
    this->width = width;
    this->brushStyle = brushStyle;
    this->brush = QBrush (this->brushStyle);
}

void Trace::setStyle(Qt::PenStyle style) {
   this->style = style;
}

void Trace::setJoin(Qt::PenJoinStyle join) {
    this->join = join;
}

void Trace::setCap(Qt::PenCapStyle cap) {
    this->cap = cap;
}

Qt::PenStyle Trace::getStyle() const {
    return this->style;
}

Qt::PenJoinStyle Trace::getJoin() const {
    return this->join;
}

Qt::PenCapStyle Trace::getCap() const {
    return this->cap;
}

int Trace::getWidth() const {
    return this->width;
}

void Trace::setWidth(int width) {
    if(width < 40)
        this->width = width;
}


QBrush Trace::getBrush() const {
    return this->brush;
}

void Trace::setBrushStyle(Qt::BrushStyle style) {
    this->brushStyle = style;
    this->brush.setStyle(style);
}


Qt::BrushStyle Trace::getBrushStyle() const {
    return this->brushStyle;
}
