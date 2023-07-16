#ifndef NODEGRAPHIC_H
#define NODEGRAPHIC_H
#include <QLineEdit>


class QGraphicsEllipseItem;
class QGraphicsItem;
class QGraphicsTextItem;
class QGraphicsLineItem;


class NodeGraphic
{
public:
    NodeGraphic();
    NodeGraphic(QRectF);

    QGraphicsEllipseItem* m_circle;
    QGraphicsTextItem* m_text;
    QPointF m_center;
    QGraphicsLineItem* m_arrow;
    int m_limit;
};

#endif // NODEGRAPHIC_H
