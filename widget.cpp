#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPainter>
#include <QPushButton>
#include "widget.h"
#include "nodegraphic.h"
#include "binarytree.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    createMembers();
    setupMembers();
    setupLayout();
    makeConnections();
}

void MainWidget::createMembers()
{
    m_tree = new BinaryTree();
    m_scene = new QGraphicsScene();
    m_view = new QGraphicsView();
    m_insertButton = new QPushButton("insert");
    m_number = new QLineEdit();
}

void MainWidget::setupMembers()
{
    m_scene -> setSceneRect(-250, -250, 500, 500);
    m_view -> setScene(m_scene);

}

void MainWidget::setupLayout()
{

    QVBoxLayout* mainLay = new QVBoxLayout;
    QHBoxLayout* lay = new QHBoxLayout;

    m_number -> setFixedSize(150,20);
    m_insertButton -> setFixedSize(150,20);

    lay -> addWidget(m_insertButton);
    lay -> addWidget(m_number);

    mainLay -> addLayout(lay);
    mainLay -> addWidget(m_view);

    setLayout(mainLay);
}

void MainWidget:: makeConnections(){
    connect(m_insertButton, &QPushButton::clicked, this, &MainWidget:: addNode);


}

void MainWidget:: addNode()
{
    QString inputText = m_number -> text();
    int value = inputText.toInt();
    TreeNode* tmp = m_tree -> insert(value);
    if(tmp -> m_parent && tmp -> m_parent -> m_parent) {
        tmp -> check(tmp,tmp -> m_parent);
    }
    addCircleText(tmp);

    addArrow(tmp);

    m_scene -> createItemGroup({ tmp -> m_node -> m_circle,
                              tmp ->m_node -> m_text,
                              tmp -> m_node -> m_arrow,
                              });

}

void MainWidget:: addCircleText(TreeNode* tmp){
    QRectF rect = tmp -> m_node -> m_circle -> rect();
    tmp -> m_node  -> m_circle = m_scene -> addEllipse(rect);
    tmp -> m_node -> m_text = m_scene -> addText(QString::number(tmp -> m_value));
    tmp -> m_node -> m_text -> setPos(rect.x() + 10, rect.y() + 10);

}

void MainWidget:: addArrow(TreeNode * tmp){

    int x1 = tmp -> m_node -> m_center.x();
    int y1 = tmp -> m_node -> m_center.y();

    if(!tmp -> m_parent) {
        tmp -> m_node -> m_arrow -> setLine (x1 - 20,
                                      y1,
                                      x1 - 20,
                                      y1);
        return;
    }

    int x = tmp -> m_parent -> m_node -> m_center.x();
    int y = tmp -> m_parent -> m_node -> m_center.y();


    {
        if(tmp == (tmp -> m_parent -> m_left)){
            tmp -> m_node -> m_arrow -> setLine(x - 15,
                                          y + 15,
                                          x1,
                                          y1 - 20);

        }
        else  {
            tmp -> m_node -> m_arrow -> setLine(x + 15,
                                          y + 15,
                                          x1,
                                          y1 - 20);
        }

        return;
    }

}




