#ifndef LINE_H
#define LINE_H

#include "geometry.h"

class Line : public Geometry {

    public:
        Line(int ix = 0, int iy = 0, int cx = 0, int cy = 0);
        virtual void draw(QPainter *painter);
        virtual void updatePainterPath();

};

#endif // LINE_H
