#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QgraphicsView>

#include "nodegraphic.h"
#include "treenode.h"


NodeGraphic::NodeGraphic()
{

}

NodeGraphic::NodeGraphic(QRectF rect){
    m_circle = new QGraphicsEllipseItem(rect);
    m_text = new QGraphicsTextItem();
    m_center = m_circle -> boundingRect().center() + m_circle -> pos();
    m_text -> setPos(m_center);
    m_arrow = new QGraphicsLineItem();
}



