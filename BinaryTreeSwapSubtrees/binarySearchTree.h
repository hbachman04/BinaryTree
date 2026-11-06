
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binaryTree.h"

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
private:
    void insertNode(
        binaryTreeNode<elemType>*& p,
        const elemType& insertItem)
    {
        if (p == nullptr)
        {
            p = new binaryTreeNode<elemType>;
            p->info = insertItem;
            p->lLink = nullptr;
            p->rLink = nullptr;
        }
        else if (insertItem < p->info)
        {
            insertNode(p->lLink, insertItem);
        }
        else
        {
            insertNode(p->rLink, insertItem);
        }
    }

public:
    void insert(const elemType& insertItem)
    {
        insertNode(this->root, insertItem);
    }
};

#endif
