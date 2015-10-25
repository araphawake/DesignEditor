#ifndef POLYLINE_H
#define POLYLINE_H

#include "geometry.h"

class Polyline : public Geometry {
    public:
        Polyline(int ix = 0, int iy = 0);
        virtual void draw(QPainter *painter);
        virtual int getLastX();
        virtual int getLastY();
        virtual void update(int x, int y);
        virtual bool checkVoid() const;
        virtual bool checkBlank() const;
        virtual void reset();
        virtual void updatePainterPath();

    private:
        QList<QPoint*> points;
        QPoint link;
        bool isBlank;
};

#endif // POLYLINE_H
