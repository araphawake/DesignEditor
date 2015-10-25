#ifndef TRACE_H
#define TRACE_H

#include <QPen>
#include <QStyle>
#include <QBrush>

class Trace {
    public:
        Trace();
        Trace(Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join, int width, Qt::BrushStyle brushStyle);
        virtual void setStyle(Qt::PenStyle style);
        virtual void setJoin(Qt::PenJoinStyle join);
        virtual void setCap(Qt::PenCapStyle cap);
        virtual Qt::PenStyle getStyle() const;
        virtual Qt::PenJoinStyle getJoin() const;
        virtual Qt::PenCapStyle getCap() const;
        virtual int getWidth() const;
        virtual void setWidth(int width);
        virtual QBrush getBrush() const;
        virtual void setBrushStyle(Qt::BrushStyle style);
        virtual Qt::BrushStyle getBrushStyle() const;


    private:
        int width;
        Qt::PenStyle style;
        Qt::PenCapStyle cap;
        Qt::PenJoinStyle join;
        QBrush brush;
        Qt::BrushStyle brushStyle;

};

#endif // TRACE_H
