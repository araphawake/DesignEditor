#ifndef ZONEDEDESSIN_H
#define ZONEDEDESSIN_H

#include "qwidget.h"
#include <QMouseEvent>
#include <QPoint>
#include <QPen>
#include <QPainter>
#include <QStyle>
#include "geometry.h"
#include "selection.h"
#include "qslider.h"


class ZoneDeDessin : public QWidget {

    Q_OBJECT

    private:

        typedef struct editBackup {
            int width;
            QColor color;
            Qt::BrushStyle brushStyle;
            Qt::PenJoinStyle joinStyle;
            Qt::PenCapStyle capStyle;
        } EditBackup;

        EditBackup backup;
        bool translating;
        bool afterSelectionBegin;
        QColor defaultColor;
        QColor currentColor;
        int currentWidth;
        Geometry::shape drawType;
        bool enableDrawing;
        QPen pen;
        Geometry * currentDrawing;
        Geometry * currentDrawingEditing;
        QList<Geometry*> drawings;
        QPainter * painter;
        Selection * selection;
        Qt::BrushStyle currentBrushStyle;
        Qt::PenCapStyle currentCap;
        Qt::PenJoinStyle currentJoin;
        QSlider * widthSlider;
        bool isEditing;


    public:
        explicit ZoneDeDessin(QWidget *parent = 0);
        virtual void setEditing(bool status);
        virtual void setDrawType(Geometry::shape);
        virtual void setSlider(QSlider * slider);
        virtual bool getDrawStatus() const;
        virtual Geometry::shape getDrawType();
        virtual void updatePen(QBrush brush, QColor color, int width, Qt::PenStyle style);
        virtual void updatePen(QBrush brush, QColor color, int width);
        virtual void updatePen(QColor color, int width);
        virtual void updatePen(QBrush brush, QColor color);
        virtual QColor getDefaultColor();
        virtual void setCurrentColor(QColor color);
        virtual void setStyle(Qt::PenStyle style);
        virtual void setJoin(Qt::PenJoinStyle join);
        virtual void setCap(Qt::PenCapStyle cap);
        virtual Qt::PenStyle getStyle() const;
        virtual Qt::PenJoinStyle getJoin() const;
        virtual Qt::PenCapStyle getCap() const;
        virtual int getWidth() const;
        virtual int getWidthEditing() const;
        virtual void setWidth(int width);
        virtual QBrush getBrush() const;
        virtual bool getEditState() const;
        virtual void setBrushStyle(Qt::BrushStyle style);
        virtual Qt::BrushStyle getBrushStyle() const;
        virtual void setDefaultColor(QColor color);
        virtual void interruptDrawing();
        virtual void reset();
        virtual void setTranslation(bool state);

    protected:
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *e);
        void mouseReleaseEvent(QMouseEvent *event);

};

//QDataStream &operator<<(QDataStream &out, const ZoneDeDessin &paintings);
//QDataStream &operator>>(QDataStream &in, ZoneDeDessin &paintings);

#endif // ZONEDEDESSIN_H
