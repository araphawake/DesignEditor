#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "qpainter.h"
#include "trace.h"

class Geometry {

    public:

        enum shape {
            LINE,
            POLYLINE,
            RECTANGLE,
            SQUARE,
            ELLIPSE,
            CIRCLE
        };

        Geometry(shape type = LINE);
        Geometry(int ix, int iy, int cx, int cy, shape type);
        virtual void draw(QPainter *painter) = 0;
        virtual void updatePainterPath() = 0;
        virtual QPainterPath * getPainterPath() const;
        virtual void setPainterPath(QPainterPath *);
        shape getShapeType();
        virtual void setTracker(int ix, int iy, int cx, int cy);
        virtual int getInitialX() const;
        virtual int getInitialY() const;
        virtual int getCurrentX() const;
        virtual int getCurrentY() const;
        virtual int getTransX() const;
        virtual int getTransY() const;
        virtual bool isAppended();
        virtual void setTransX(int);
        virtual void setTransY(int);
        virtual void setInitialX(int);
        virtual void setInitialY(int);
        virtual void setCurrentX(int);
        virtual void setCurrentY(int);
        virtual void setSelected(bool);
        virtual void setAppended(bool);
        virtual bool getSelectedState() const;
        virtual void setShape(shape s);
        virtual void setColor(QColor c);
        virtual QColor getColor();
        virtual void updateTrace(Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join,
                                 int width, QBrush brush, Qt::BrushStyle brushStyle);
        virtual void updateStyle(Qt::PenStyle style);
        virtual void updateCap(Qt::PenCapStyle cap);
        virtual void updateJoin(Qt::PenJoinStyle join);
        virtual void updateWidth(int width);
        virtual void updateBrush(Qt::BrushStyle brushStyle);
        virtual Trace getTrace() const;
        virtual void updateAfterTranslation();




    private:
        shape shapeType;
        QColor color;
        Trace trace;
        QPainterPath * path;
        bool isSelected;
        bool alreadyAppended;

        struct positionTracker {
            int initialX;
            int initialY;
            int currentX;
            int currentY;
            int transPointX;
            int transPointY;
        };

        typedef struct positionTracker PositionTracker;

        PositionTracker tracker;

};

#endif // GEOMETRY_H
