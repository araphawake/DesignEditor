#include "Zonededessin.h"
#include <iostream>
#include <cstdlib>
#include "QPainter"
#include "line.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polyline.h"
#include "square.h"
#include "circle.h"
#include "mainwindow.h"
using namespace std;

ZoneDeDessin::ZoneDeDessin(QWidget *parent) : QWidget(parent) {

    this->setAttribute(Qt::WA_StaticContents);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    this->drawType = Geometry::LINE;

    this->defaultColor = Qt::black;
    this->pen = QPen(this->defaultColor);
    this->pen.setWidth(3);
    this->enableDrawing = false;
    this->selection = new Selection(0, 0, 0, 0);

    this->currentDrawing = new Line(0, 0, 0, 0);
    this->currentDrawingEditing = this->currentDrawing;
    this->currentBrushStyle = Qt::SolidPattern;
    this->currentCap = Qt::SquareCap;
    this->currentJoin = Qt::BevelJoin;
    this->currentWidth = 1;
    this->isEditing = false;
    this->afterSelectionBegin = false;
    this->translating = false;
}

void ZoneDeDessin::setEditing(bool status) {
    this->isEditing = status;
    this->translating = false;
    this->selection->setSelected(false);

    this->selection->setFocus(Selection::NONE);

    if(this->isEditing) {
        this->currentWidth = 0;
        this->backup.width = this->currentWidth;
        //this->backup.brushStyle = this->currentBrushStyle;
        //this->backup.capStyle = this->currentCap;
        //this->backup.color = this->currentColor;
        //this->backup.joinStyle = this->currentJoin;

        this->currentDrawing->setSelected(false);
    } else {
        //this->enableDrawing = true;
        this->currentDrawing->setSelected(true);
        this->setDrawType(this->getDrawType());

        QList<Geometry*>::iterator i;
        for (i = drawings.begin(); i != drawings.end(); i++) {
            if((*i)->getSelectedState()) {
                (*i)->setSelected(false);
            }
        }
    }

    if(this->currentDrawing) {
        this->currentWidth = 0;
        this->update();

        this->enableDrawing = false;

        if(this->getDrawType() != Geometry::POLYLINE && !this->currentDrawing->isAppended()) {
            this->drawings.append(this->currentDrawing);
            this->currentDrawing->setAppended(true);
            //this->currentDrawing->addPath(this->path.last());
        }

        this->currentDrawing->updateAfterTranslation();
        this->currentDrawing->updatePainterPath();
    }

    this->update();

}

void ZoneDeDessin::setDrawType(Geometry::shape state)  {

    if(state != this->drawType && this->enableDrawing) {
        this->drawType = state;

        int ix = this->currentDrawing->getInitialX();
        int iy = this->currentDrawing->getInitialY();
        int cx = this->currentDrawing->getCurrentX();
        int cy = this->currentDrawing->getCurrentY();

        if(this->getDrawType() == Geometry::CIRCLE) {
            this->currentDrawing = new Circle(ix);
        } else if(this->getDrawType() == Geometry::LINE) {
            this->currentDrawing = new Line(ix, iy, cx, cy);
        } else if(this->getDrawType() == Geometry::ELLIPSE) {
            this->currentDrawing = new Ellipse(ix, iy, cx, cy);
        } else if(this->getDrawType() == Geometry::RECTANGLE) {
            this->currentDrawing = new Rectangle(ix, iy, cx, cy);
        } else if(this->getDrawType() == Geometry::SQUARE) {
            this->currentDrawing = new Square(cx, cy);
        } else if(this->getDrawType() == Geometry::POLYLINE) {
            this->currentDrawing = new Polyline(ix, iy);
            ((Polyline *)(this->currentDrawing))->reset();
            setMouseTracking(false);
            this->enableDrawing = false;
        }

        this->update();
    } else {
        this->drawType = state;

        int ix = this->currentDrawing->getInitialX();
        int iy = this->currentDrawing->getInitialY();
        int cx = this->currentDrawing->getCurrentX();
        int cy = this->currentDrawing->getCurrentY();

        if(this->getDrawType() == Geometry::CIRCLE) {
            this->currentDrawing = new Circle(ix);
        } else if(this->getDrawType() == Geometry::LINE) {
            this->currentDrawing = new Line(ix, iy, cx, cy);
        } else if(this->getDrawType() == Geometry::ELLIPSE) {
            this->currentDrawing = new Ellipse(ix, iy, cx, cy);
        } else if(this->getDrawType() == Geometry::RECTANGLE) {
            this->currentDrawing = new Rectangle(ix, iy, cx, cy);
        } else if(this->getDrawType() == Geometry::SQUARE) {
            this->currentDrawing = new Square(cx, cy);
        } else if(this->getDrawType() == Geometry::POLYLINE) {
            this->currentDrawing = new Polyline(ix, iy);
            ((Polyline *)(this->currentDrawing))->reset();
            setMouseTracking(false);
        }
    }
}

Geometry::shape ZoneDeDessin::getDrawType() {
    return this->drawType;
}

void ZoneDeDessin::interruptDrawing() {

    if(this->enableDrawing == true) {
        this->update();

        this->enableDrawing = false;

        if(!this->currentDrawing->isAppended()) {
            this->drawings.append(this->currentDrawing);
            this->currentDrawing->setAppended(true);
        }
    }
}

void ZoneDeDessin::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {

        if(!this->isEditing) {

            if(this->getDrawType() == Geometry::CIRCLE) {
                this->currentDrawing = new Circle(event->pos().x());
            } else if(this->getDrawType() == Geometry::LINE) {
                this->currentDrawing = new Line(event->pos().x(), event->pos().y(), event->pos().x(), event->pos().y());
            } else if(this->getDrawType() == Geometry::ELLIPSE) {
                this->currentDrawing = new Ellipse(event->pos().x(), event->pos().y(), event->pos().x(), event->pos().y());
            } else if(this->getDrawType() == Geometry::RECTANGLE) {
                this->currentDrawing = new Rectangle(event->pos().x(), event->pos().y(), event->pos().x(), event->pos().y());
            } else if(this->getDrawType() == Geometry::SQUARE) {
                this->currentDrawing = new Square(event->pos().x(), event->pos().y());
            } else if(this->getDrawType() == Geometry::POLYLINE) {
                if(this->currentDrawing->getShapeType() != Geometry::POLYLINE || this->getDrawStatus() == false) {
                    this->currentDrawing = new Polyline(event->pos().x(), event->pos().y());
                    setMouseTracking(true);
                } else {
                    ((Polyline *)(this->currentDrawing))->update(event->pos().x(), event->pos().y());
                }
            }

            this->currentDrawing->updateWidth(this->currentWidth);

            this->currentDrawing->setInitialX(event->pos().x());
            this->currentDrawing->setInitialY(event->pos().y());

            this->enableDrawing = true;
        } else {
            if(this->translating) {
                QList<Geometry*>::iterator i;
                for (i = drawings.begin(); i != drawings.end(); i++) {

                    if((*i)->getShapeType() == Geometry::LINE) {

                        QRectF rect = QRectF(event->pos().x(), event->pos().y(), 8 + (*i)->getTrace().getWidth(), 8 + (*i)->getTrace().getWidth());
                            if((*i)->getPainterPath()->intersects(rect)) {
                                (*i)->setSelected(true);
                                (*i)->setTransX(event->pos().x());
                                (*i)->setTransY(event->pos().y());
                            }
                    } else if((*i)->getPainterPath()->contains(QPointF(event->pos().x(), event->pos().y()))) {
                        (*i)->setSelected(true);
                        (*i)->setTransX(event->pos().x());
                        (*i)->setTransY(event->pos().y());
                    }
                }
            }


                if(!this->translating) {
                    this->afterSelectionBegin = false;
                    this->selection->setInitialX(event->pos().x());
                    this->selection->setInitialY(event->pos().y());
                    this->selection->setEnabled(false);
                    this->selection->setSelected(false);
                    this->isEditing = true;
                }
        }

    } else if (event->button() == Qt::RightButton) {
        if(this->getDrawType() == Geometry::POLYLINE && ((Polyline *)(this->currentDrawing))->checkVoid() == false && this->isEditing == false) {
                setMouseTracking(false);
                ((Polyline *)(this->currentDrawing))->update(event->pos().x(), event->pos().y());
                ((Polyline *)(this->currentDrawing))->updatePainterPath();
                if(!this->currentDrawing->isAppended()) {
                    this->drawings.append(this->currentDrawing);
                    this->currentDrawing->setAppended(true);
                }
                this->currentDrawing = new Polyline(event->pos().x(), event->pos().y());
                this->enableDrawing = false;

                ((Polyline *)(this->currentDrawing))->reset();
                this->update();
        }
    }



}

void ZoneDeDessin::setTranslation(bool state) {
    this->selection->setSelected(true);
    QList<Geometry*>::iterator i;
    for (i = drawings.begin(); i != drawings.end(); i++) {
        if((*i)->getSelectedState()) {
            (*i)->setSelected(false);
        }
    }
    this->translating = state;
    this->isEditing = true;
}

bool ZoneDeDessin::getDrawStatus() const {
    if(this->currentDrawing->getShapeType() == Geometry::POLYLINE) {
        if(((Polyline*)(this->currentDrawing))->checkBlank() == false) {
            return true;
        }
    }

    return false;
}

QColor ZoneDeDessin::getDefaultColor() {
    return this->defaultColor;
}

void ZoneDeDessin::updatePen(QBrush brush, QColor color, int width, Qt::PenStyle style) {
    this->pen.setBrush(brush);
    this->pen.setColor(color);
    this->pen.setWidth(width);
    this->pen.setStyle(style);
}

void ZoneDeDessin::updatePen(QBrush brush, QColor color, int width) {
    this->pen.setBrush(brush);
    this->pen.setColor(color);
    this->pen.setWidth(width);

}

void ZoneDeDessin::updatePen(QColor color, int width) {
    this->pen.setColor(color);
    this->pen.setWidth(width);

}

void ZoneDeDessin::updatePen(QBrush brush, QColor color) {
    this->pen.setBrush(brush);
    this->pen.setColor(color);
}

void ZoneDeDessin::mouseMoveEvent(QMouseEvent *event) {

    if(!this->isEditing) {
        this->currentDrawing->setCurrentX(event->pos().x());
        this->currentDrawing->setCurrentY(event->pos().y());

        this->update();
    } else {

        if(this->translating) {
            QList<Geometry*>::iterator i;
            for (i = drawings.begin(); i != drawings.end(); i++) {
                if((*i)->getSelectedState() && (*i)->getShapeType() != Geometry::POLYLINE) {
                    int dx = event->pos().x() - (*i)->getTransX();
                    int dy = event->pos().y() - (*i)->getTransY();

                    (*i)->setCurrentX((*i)->getCurrentX() + dx);
                    (*i)->setCurrentY((*i)->getCurrentY() + dy);
                    (*i)->setInitialX((*i)->getInitialX() + dx);
                    (*i)->setInitialY((*i)->getInitialY() + dy);
                    (*i)->setTransX(event->pos().x());
                    (*i)->setTransY(event->pos().y());
                    (*i)->updateAfterTranslation();
                    (*i)->updatePainterPath();
                    this->update();
                }
            }

            /*QRectF selection (event->pos().x(), event->pos().y(), 0, 0);

            QList<Geometry*>::iterator i;
            for (i = drawings.begin(); i != drawings.end(); i++) {
                if((*i)->getPainterPath()->intersects(selection)) {
                    (*i)->getPainterPath()->translate(QPointF(event->pos().x(), event->pos().y()));
                    QPainterPath result = (*i)->getPainterPath()->translated(QPointF(event->pos().x(), event->pos().y()));
                    (*i)->setCurrentX(result.currentPosition().x());
                    (*i)->setCurrentY(result.currentPosition().y());
                }

            }
            */
            //this->translating = false;
        } else {

            this->selection->setCurrentX(event->pos().x());
            this->selection->setCurrentY(event->pos().y());

            this->update();
        }

    }

}

void ZoneDeDessin::setCurrentColor(QColor color) {

    if(this->isEditing) {
        this->currentColor = color;
        this->backup.color = this->currentColor;
        this->selection->setFocus(Selection::COLOR);
        this->afterSelectionBegin = true;
    } else {
        this->currentColor = color;
        this->currentDrawing->setColor(this->currentColor);
        this->currentDrawing->updateBrush(this->currentBrushStyle);
    }

    this->update();

}

void ZoneDeDessin::setSlider(QSlider * slider) {
    this->widthSlider = slider;
}

void ZoneDeDessin::setDefaultColor(QColor color) {
    this->defaultColor = color;
}

void ZoneDeDessin::paintEvent(QPaintEvent *e) {

        QWidget::paintEvent(e);

        static int i = 0;

        this->painter = new QPainter(this);

        if(!this->isEditing) {

            if(this->enableDrawing == true || this->currentDrawing->getShapeType() == Geometry::POLYLINE) {
                this->currentDrawing->setColor(this->currentColor);
                this->currentDrawing->updateBrush(this->currentBrushStyle);
                this->currentDrawing->updateCap(this->currentCap);
                this->currentDrawing->updateJoin(this->currentJoin);
            }

            this->painter->setPen(this->pen);

            if(this->currentDrawing != NULL) {
                if(this->currentDrawing->getShapeType() == Geometry::POLYLINE && ((Polyline*)(this->currentDrawing))->checkVoid() == true) {
                } else if(this->enableDrawing == true || this->currentDrawing->getShapeType() == Geometry::POLYLINE){
                    this->currentDrawing->draw(this->painter);
                    i++;
                }
            }

            for(int counter = 0; counter < this->drawings.count(); counter++) {
                this->drawings.at(counter)->draw(this->painter);
            }
        } else {
            if(!this->selection->getSelectedState()) {
                this->selection->drawAndSelect(painter, this->drawings);
                this->afterSelectionBegin = true;
            } else {

                QList<Geometry*>::iterator i;
                for (i = drawings.begin(); i != drawings.end(); i++) {
                    if((*i)->getSelectedState()) {
                        if(this->afterSelectionBegin && !this->translating) {
                            this->currentDrawingEditing = (*i);
                            switch(this->selection->getFocus()) {
                                case Selection::COLOR:
                                    (*i)->setColor(backup.color);
                                    break;
                                case Selection::WIDTH:
                                    if(i != drawings.end() - 1) {
                                        if((*i)->getTrace().getWidth() + backup.width > -1) {
                                            (*i)->updateWidth((*i)->getTrace().getWidth() + backup.width);
                                        } else if(abs(backup.width) != 0) {
                                            (*i)->updateWidth(0);
                                        }
                                    } else {
                                        if((*i)->getTrace().getWidth() + backup.width > -1) {
                                            (*i)->updateWidth((*i)->getTrace().getWidth() + backup.width);
                                        } else if(abs(backup.width) != 0) {
                                            (*i)->updateWidth(0);
                                        }
                                    }
                                    break;
                                case Selection::BRUSH:
                                    (*i)->updateBrush(backup.brushStyle);
                                    break;
                                case Selection::CAP:
                                    (*i)->updateCap(backup.capStyle);
                                    break;
                                case Selection::JOIN:
                                    (*i)->updateJoin(backup.joinStyle);
                                    break;
                                default:
                                    break;

                            }

                        }

                        painter->setPen(this->pen);

                        (*i)->draw(this->painter);
                    } else {

                        (*i)->draw(this->painter);
                    }
                }

                this->currentWidth -= backup.width;
                backup.width = 0;
                if(currentWidth < 0)
                    currentWidth = 0;
            }
        }

}

void ZoneDeDessin::mouseReleaseEvent(QMouseEvent *event) {

    if(!this->isEditing) {
        this->update();

        this->enableDrawing = false;

        if(this->getDrawType() != Geometry::POLYLINE && !this->currentDrawing->isAppended()) {
            this->drawings.append(this->currentDrawing);
            this->currentDrawing->setAppended(true);
            //this->currentDrawing->addPath(this->path.last());
        }

        if(this->currentDrawing->getShapeType() != Geometry::POLYLINE) {
            this->currentDrawing->updateAfterTranslation();
            this->currentDrawing->updatePainterPath();
            //this->currentWidth = 0;
        }

    } else {

        QList<Geometry*>::iterator i;
        if(this->translating) {
            for (i = drawings.begin(); i != drawings.end(); i++) {
                if((*i)->getSelectedState()) {
                    (*i)->setSelected(false);
                }
            }
        }

        this->update();

        this->selection->setCurrentX(event->pos().x());
        this->selection->setCurrentY(event->pos().y());
        this->selection->updatePainterPath();
        this->selection->setEnabled(true);
        this->selection->setSelected(true);

    }

}

void ZoneDeDessin::setStyle(Qt::PenStyle style) {
   this->currentDrawing->updateStyle(style);
   this->update();
}

void ZoneDeDessin::setJoin(Qt::PenJoinStyle join) {

    if(this->isEditing) {
        this->currentJoin = join;
        this->backup.joinStyle = this->currentJoin;
        this->selection->setFocus(Selection::JOIN);
        this->afterSelectionBegin = true;
    } else {
        this->currentJoin = join;
        this->currentDrawing->updateJoin(join);
    }

    this->update();
}

void ZoneDeDessin::setCap(Qt::PenCapStyle cap) {

    if(this->isEditing) {
        this->currentCap = cap;
        this->backup.capStyle = this->currentCap;
        this->selection->setFocus(Selection::CAP);
        this->afterSelectionBegin = true;
    } else {
        this->currentCap = cap;
        this->currentDrawing->updateCap(this->currentCap);
    }

    this->update();
}

Qt::PenStyle ZoneDeDessin::getStyle() const {
    return this->currentDrawing->getTrace().getStyle();
}

Qt::PenJoinStyle ZoneDeDessin::getJoin() const {
    return this->currentDrawing->getTrace().getJoin();
}

Qt::PenCapStyle ZoneDeDessin::getCap() const {
    return this->currentDrawing->getTrace().getCap();
}

int ZoneDeDessin::getWidth() const {
    return this->currentWidth;
}

int ZoneDeDessin::getWidthEditing() const {
    return this->currentDrawingEditing->getTrace().getWidth();
}

void ZoneDeDessin::reset() {
    if(!this->isEditing) {
        this->drawings.clear();
        this->update();
    } else {

        //Erasing individual figures must be fixed for FUTURE RELEASE.
        /*QList<Geometry*>::iterator i;
        for (i = drawings.begin(); i != drawings.end(); i++) {
            if((*i)->getSelectedState()) {
                //if(drawings.at(distance(drawings.begin(), i)) < 0)

                (*i) = NULL;
                drawings.removeAt(distance(drawings.begin(), i));

            }
        }

        //this->currentDrawing = new Line();
        this->afterSelectionBegin = false;
        this->selection->setSelected(false);
        //this->update();*/
    }
}

void ZoneDeDessin::setWidth(int width) {

    if(width < 40) {
        if(this->isEditing) {
            this->backup.width = (width - this->currentWidth);
            this->currentWidth = width;
            this->selection->setFocus(Selection::WIDTH);
            this->afterSelectionBegin = true;
        } else {
            this->currentWidth = width;
            this->currentDrawing->updateWidth(width);
        }
    }
    this->update();
}

bool ZoneDeDessin::getEditState() const {
    return this->isEditing;
}

QBrush ZoneDeDessin::getBrush() const {
    return this->currentDrawing->getTrace().getBrush();
}

void ZoneDeDessin::setBrushStyle(Qt::BrushStyle style) {

    if(this->isEditing) {
        this->currentBrushStyle = style;
        this->backup.brushStyle = this->currentBrushStyle;
        this->selection->setFocus(Selection::BRUSH);
        this->afterSelectionBegin = true;
    } else {
        this->currentBrushStyle = style;
        this->currentDrawing->getTrace().setBrushStyle(this->currentBrushStyle);
        this->currentDrawing->updateBrush(this->currentBrushStyle);
    }

    this->update();
}


Qt::BrushStyle ZoneDeDessin::getBrushStyle() const {
    return this->currentDrawing->getTrace().getBrushStyle();
}

/*QDataStream &operator<<(QDataStream &out, const ZoneDeDessin &paintings) {
    int count = paintings.drawings.length();
    for(unsigned int i = 0; i < count; i++) {
        out <<
    }
}

QDataStream &operator>>(QDataStream &in, ZoneDeDessin &paintings) {

}*/
