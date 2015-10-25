#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"

class Circle : public Ellipse
{
    public:
        Circle(int radius = 0);
        virtual void draw(QPainter *painter);
        virtual void updatePainterPath();

    private:
        int radius;
};

#endif // CIRCLE_H
