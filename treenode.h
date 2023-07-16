#ifndef TREENODE_H
#define TREENODE_H
#include <QGraphicsEllipseItem>

class QGraphicsItem;
class QGraphicsTextItem;
class NodeGraphic;

class TreeNode
{
public:
    TreeNode();
    TreeNode(QRectF,int);

    TreeNode* m_right;
    TreeNode* m_left;
    TreeNode* m_parent;
    NodeGraphic* m_node;
    int m_value;

    void check(TreeNode*,TreeNode*);
    int distance(TreeNode*,TreeNode*);
    void move(TreeNode*,int);
    void upDateArrow(TreeNode*);
    void upDateText(TreeNode*);
    void upDateLimit(TreeNode*);
    void upDateCenter(TreeNode*);
};

#endif // TREENODE_H
