#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QRectF>
#include "treenode.h"
#include "nodegraphic.h"

using namespace std;

TreeNode:: TreeNode()
{
    m_right = nullptr;
    m_left = nullptr;
    m_parent = nullptr;
    m_node = nullptr;

}

TreeNode:: TreeNode(QRectF rect, int item){
    m_right = nullptr;
    m_left = nullptr;
    m_parent = nullptr;
    m_value = item;
    m_node = new NodeGraphic(rect);


}



void TreeNode:: check(TreeNode* tmp,TreeNode* root){
    if(!root) return;
    if(!tmp) return;
    if(!tmp -> m_parent) return;

    if(distance(tmp, root) == 0){
        if(tmp -> m_parent -> m_node -> m_center.x() < root -> m_node -> m_center.x()){
            move(root -> m_left, -25);
            check(tmp -> m_parent, root);
        }
        else {

            move(root -> m_right, +25);
            check(root -> m_right -> m_left, root);
            check(root -> m_right -> m_right, root);
            check(tmp -> m_parent, root);
        }
    }
    else {
        if(tmp -> m_left) check(tmp -> m_left, root);
        if(tmp -> m_right) check(tmp -> m_right, root);
    }
    check(tmp,root -> m_parent);

    return;
}
void TreeNode:: upDateLimit(TreeNode* root){
    if(!root) return;
    if(!root -> m_parent) return;
    if(root -> m_left &&
        root -> m_node -> m_limit - 25 !=
            root -> m_left -> m_node -> m_limit
        )
        root -> m_left -> m_node -> m_limit =
            root -> m_node -> m_limit - 25;
    if(root -> m_right &&
        root -> m_node -> m_limit + 25 !=
            root -> m_right -> m_node -> m_limit
        )
        root -> m_right -> m_node -> m_limit =
            root -> m_node -> m_limit + 25;
    upDateLimit(root -> m_left);
    upDateLimit(root -> m_right);

}

void TreeNode:: move(TreeNode* root, int x){
    if(!root) return;
    QRectF rect = root -> m_node -> m_circle -> rect();
    root -> m_node -> m_circle -> setRect(rect.x() + x, rect.y(),40,40);
    upDateLimit(root);
    upDateCenter(root);
    upDateArrow(root);
    upDateText(root);
    move(root -> m_left, x);
    move(root -> m_right, x);
}
void TreeNode:: upDateArrow(TreeNode* root){
    if(!root -> m_parent) return;
    int x1 = root -> m_node -> m_center.x();
    int y1 = root -> m_node -> m_center.y();


    int x = root -> m_parent -> m_node -> m_center.x();
    int y = root -> m_parent -> m_node -> m_center.y();


    {
        if(root == (root -> m_parent -> m_left)){
           root -> m_node -> m_arrow -> setLine(x - 15,
                                     y + 15,
                                     x1,
                                     y1 - 20);


        }
        else  {
          root -> m_node -> m_arrow -> setLine(x + 15,
                                     y + 15,
                                     x1,
                                     y1 - 20);

        }

        return;
    }

}
void TreeNode:: upDateText(TreeNode* root){
    QRectF rect = root -> m_node -> m_circle -> rect();
    root -> m_node -> m_text -> setPos(rect.x() + 10, rect.y() + 10);
}
int TreeNode:: distance(TreeNode* tmp, TreeNode* root){
    if(tmp -> m_node -> m_center.x() -
            root -> m_node -> m_center.x() == 0)
        return 0;
    else return 1;

}

void TreeNode:: upDateCenter(TreeNode* tmp){
        tmp -> m_node -> m_center =
        tmp -> m_node -> m_circle -> boundingRect().center() +
        tmp -> m_node -> m_circle -> pos();
}

