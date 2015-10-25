#include "selection.h"
#include <iostream>

using namespace std;

Selection::Selection(int ix, int iy, int cx, int cy, bool isEnabled) : Geometry(Geometry::RECTANGLE) {

    this->isEnabled = isEnabled;
    this->operation = Selection::NONE;
    this->updateBrush(Qt::VerPattern);

}

void Selection::drawAndSelect(QPainter * painter, QList<Geometry*> drawings) {

    if(!this->isEnabled) {

        QList<Geometry*>::iterator object;
        for (object = drawings.begin(); object != drawings.end(); object++) {
            (*object)->setSelected(false);
        }

        int width = this->getCurrentX() - this->getInitialX();
        int height = this->getCurrentY() - this->getInitialY();

        int left = 0;
        int top = 0;
        int right = 0;
        int bottom = 0;

        if(this->getInitialX() > this->getCurrentX()) {
            left = this->getCurrentX();
            right = this->getInitialX();
        } else {

            left = this->getInitialX();
            right = this->getCurrentX();
        }

        if(this->getInitialY() > this->getCurrentY()) {
            top = this->getCurrentY();
            bottom = this->getInitialY();
        } else {
            top = this->getInitialY();
            bottom = this->getCurrentY();
        }

        QRectF selection (left, top, right - left, bottom - top);

        painter->drawRect(left, top, right - left, bottom - top);

        QList<Geometry*>::iterator i;
        for (i = drawings.begin(); i != drawings.end(); i++) {
            (*i)->setSelected((*i)->getPainterPath()->intersects(selection));
            (*i)->draw(painter);
        }

    } else {
        QList<Geometry*>::iterator i;
        for (i = drawings.begin(); i != drawings.end(); i++) {
            (*i)->draw(painter);
        }
    }

}

void Selection::setEnabled(bool status) {
    this->isEnabled = status;
}

Selection::focus Selection::getFocus() const {
    return this->operation;
}

void Selection::setFocus(focus f) {
    this->operation = f;
}

void Selection::draw(QPainter * painter) { }
void Selection::updatePainterPath() {

    int left = 0;
    int top = 0;
    int right = 0;
    int bottom = 0;

    if(this->getInitialX() > this->getCurrentX()) {
        left = this->getCurrentX();
        right = this->getInitialX();
    } else {

        left = this->getInitialX();
        right = this->getCurrentX();
    }

    if(this->getInitialY() > this->getCurrentY()) {
        top = this->getCurrentY();
        bottom = this->getInitialY();
    } else {
        top = this->getInitialY();
        bottom = this->getCurrentY();
    }

    this->getPainterPath()->addRect(QRectF(left, top, right - left, bottom - top));

}
