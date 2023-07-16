#include "binarytree.h"
#include "treenode.h"
#include "nodegraphic.h"
BinaryTree::BinaryTree()
{
    m_root = nullptr;
    m_count = 0;
}

TreeNode* BinaryTree::insert(int item)
{

    QRectF rect(-50, -250, 40, 40);
    TreeNode* newNode = new TreeNode(rect,item);
    if (m_root == nullptr) {
        m_root = newNode;
        m_root -> m_node -> m_limit = -50;
        m_count++;
        return newNode;
    }


    TreeNode* tmp = m_root;
    while (tmp != nullptr) {
        if(item < tmp -> m_value)
        {
            if(!(tmp -> m_left)) return insertLeft(tmp, newNode);
            tmp = tmp -> m_left;
        }
        else {
            if(!(tmp -> m_right)) return insertRight(tmp, newNode);
            tmp = tmp -> m_right;
        }
    }
    return newNode;
}
TreeNode* BinaryTree::insertLeft(TreeNode* root,TreeNode* newNode){


    QRectF rect = root -> m_node -> m_circle -> rect();
        rect.setX(rect.x() - 25);
        newNode  -> m_node -> m_circle -> setRect(rect.x(),
                                           rect.y() + 40,
                                           40,
                                           40);
        newNode  -> upDateCenter(newNode);
        newNode -> m_node -> m_limit = root -> m_node -> m_limit - 25;

        root -> m_left = newNode;
        newNode -> m_parent = root;
    return newNode;
}
TreeNode* BinaryTree::insertRight(TreeNode* root,TreeNode* newNode){

    QRectF rect = root -> m_node -> m_circle -> rect();
        rect.setX(rect.x() + 25);
        newNode -> m_node -> m_circle -> setRect(rect.x(),
                                          rect.y() + 40,
                                          40, 40);
        newNode  -> upDateCenter(newNode);
        newNode -> m_node -> m_limit = root -> m_node -> m_limit + 25;
    root -> m_right = newNode;
    newNode -> m_parent = root;


    newNode -> m_node -> m_circle -> setRect(rect.x(),
                                       rect.y() + 40,
                                       40, 40);

    newNode  -> upDateCenter(newNode);
    return newNode;
}

