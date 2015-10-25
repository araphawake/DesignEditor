#ifndef SQUARE_H
#define SQUARE_H
#include "geometry.h"

class Square : public Geometry {

    public:
        Square(int ix = 0, int iy = 0);
        virtual void draw(QPainter *painter);
        virtual void updatePainterPath();
};

#endif // SQUARE_H
