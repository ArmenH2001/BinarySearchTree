#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include "binarytree.h"

class QPushButton;
class QGraphicsScene;
class QGraphicsView;
class QLineEdit;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    //~MainWindow();
private:
    void createMembers();
    void setupMembers();
    void setupLayout();
    void makeConnections();
    void addArrow(TreeNode*);
    void addCircleText(TreeNode*);

public slots:
    void addNode();
private:
    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
    QPushButton* m_insertButton;
    QLineEdit* m_number;
    BinaryTree* m_tree;



};
#endif // MAINWIDGET_H
