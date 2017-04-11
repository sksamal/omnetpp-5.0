//==========================================================================
//  SUBMODULEITEM.H - part of
//
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#ifndef __OMNETPP_QTENV_SUBMODULEITEM_H
#define __OMNETPP_QTENV_SUBMODULEITEM_H

#include "qtutil.h"

#include <QGraphicsColorizeEffect>
#include <QGraphicsObject>
#include <QAbstractGraphicsShapeItem>

namespace omnetpp {

class cModule;
class cDisplayString;

namespace qtenv {

class SubmoduleItem;
class SubmoduleItemUtil {
public:
    static void setupFromDisplayString(SubmoduleItem *si, cModule *mod);
};


class SubmoduleItem : public QGraphicsObject
{
    Q_OBJECT

    // if the bounding rectangle of the shape and the image would be
    // smaller than this in any dimension, this is used instead
    static constexpr double minimumRectSize = 10;

protected:
    cModule *module;

    // Sets the text of the name item, appending the
    // vector index to it if any, and center-aligns it.
    void updateNameItem();

    // Realigns the queue length label, the info text, and the
    // decoration icon. Call this every time after the size
    // of the image or shape changes. Also updates the name.
    void realignAnchoredItems();
    void updateShapeItem();
    void adjustRangeItem(int i);
    // whichever is bigger in each direction, has a minimum size, see above.
    // assumed to be always centered around the origin.
    QRectF shapeImageBoundingRect() const;

protected slots:
    void onPositionChanged(); // keeping the range items underneath ourselves

public:
    enum Shape {
        SHAPE_NONE,
        SHAPE_OVAL,
        SHAPE_RECT
    };

    enum TextPos {
        TEXTPOS_LEFT,
        TEXTPOS_RIGHT,
        TEXTPOS_TOP
    };

    struct RangeData {
        double radius;
        double outlineWidth;
        QColor fillColor; // this will get appied with halved alpha, no need to correct it here
        QColor outlineColor;
    };

protected:
    double zoomFactor = 1;
    double imageSizeFactor = 1;
    QString name;
    int vectorIndex = -1; // if < 0, not displayed
    Shape shape = SHAPE_NONE;
    double shapeWidth = 0; // zero if unspec
    double shapeHeight = 0; // zero if unspec
    QColor shapeFillColor;
    QColor shapeOutlineColor;
    double shapeOutlineWidth = 2;
    QImage *image = nullptr; // not owned
    QImage *decoratorImage = nullptr; // not owned
    QString text;
    TextPos textPos = TEXTPOS_TOP;
    QColor textColor;
    QString queueText;

    QList<RangeData> ranges; // these two lists must be in sync at all times
    QList<QGraphicsEllipseItem *> rangeItems;

    QAbstractGraphicsShapeItem *shapeItem = nullptr;
    QGraphicsPixmapItem *imageItem = nullptr;
    ColorizeEffect *colorizeEffect = nullptr; // owned by the image item
    QGraphicsPixmapItem *decoratorImageItem = nullptr;
    ColorizeEffect *decoratorColorizeEffect = nullptr; // owned by the decorator image item

    OutlinedTextItem *nameItem = nullptr; // includes the vector index
    OutlinedTextItem *textItem = nullptr;
    OutlinedTextItem *queueItem = nullptr;

    GraphicsLayer *rangeLayer = nullptr;

public:
    SubmoduleItem(cModule *mod, GraphicsLayer *rangeLayer);
    virtual ~SubmoduleItem();

    void setZoomFactor(double zoom);
    void setImageSizeFactor(double imageSize);

    void setShape(Shape shape);
    void setWidth(double width);
    void setHeight(double height);
    void setFillColor(const QColor &color);
    void setOutlineColor(const QColor &color);
    void setOutlineWidth(double width);

    void setImage(QImage *image);
    void setImageColor(const QColor &color);
    void setImageColorPercentage(int percent);

    void setDecoratorImage(QImage *image);
    void setDecoratorImageColor(const QColor &color);
    void setDecoratorImageColorPercentage(int percent);

    void setName(const QString &text);
    void setVectorIndex(int index);
    void setQueueText(const QString &queueText);
    void setInfoText(const QString &text, TextPos pos, const QColor &color);

    void setRangeLayer(GraphicsLayer *layer);

    // these return the index of the newly created range, for future reference
    int addRangeItem(double radius, double outlineWidth, const QColor &fillColor, const QColor &outlineColor);
    int addRangeItem(const RangeData &data);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


} // namespace qtenv
} // namespace omnetpp

#endif // __OMNETPP_QTENV_SUBMODULEITEM_H
