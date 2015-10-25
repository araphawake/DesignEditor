#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "geometry.h"

class Ellipse : public Geometry {

    public:
        Ellipse(int ix = 0, int iy = 0, int cx = 0, int cy = 0);
        virtual void draw(QPainter *painter);
        virtual void updatePainterPath();

};

#endif // ELLIPSE_H
