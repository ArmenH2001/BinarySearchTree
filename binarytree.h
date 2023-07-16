#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "treenode.h"
class BinaryTree
{
public:
    BinaryTree();
    TreeNode* insert(int item);
    TreeNode* insertRight(TreeNode*,TreeNode*);
    TreeNode* insertLeft(TreeNode*, TreeNode*);

    TreeNode* deleteNode(TreeNode*);
    TreeNode* m_root;
    int m_count;

};

#endif // BINARYTREE_H
