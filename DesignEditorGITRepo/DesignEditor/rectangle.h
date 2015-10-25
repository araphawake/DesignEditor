#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "geometry.h"

class Rectangle : public Geometry {
    public:
        Rectangle(int ix = 0, int iy = 0, int cx = 0, int cy = 0);
        virtual void draw(QPainter *painter);
        virtual void updatePainterPath();
};

#endif // RECTANGLE_H
