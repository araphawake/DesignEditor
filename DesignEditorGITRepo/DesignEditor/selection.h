#ifndef SELECTION_H
#define SELECTION_H

#include <QPainterPath>
#include "geometry.h"


class Selection : public Geometry {

    public:
        enum focus {
            COLOR,
            BRUSH,
            CAP,
            JOIN,
            WIDTH,
            NONE
        };

        Selection(int ix = 0, int iy = 0, int cx = 0, int cy = 0, bool isEnabled = false);
        virtual void drawAndSelect(QPainter * painter, QList<Geometry*> drawings);
        virtual void draw(QPainter * painter);
        virtual void updatePainterPath();
        virtual void setEnabled(bool);
        virtual focus getFocus() const;
        virtual void setFocus(focus);

    private:
        bool isEnabled;
        focus operation;

};

#endif // SELECTION_H
