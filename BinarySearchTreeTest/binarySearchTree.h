
#ifndef H_binarySearchTree
#define H_binarySearchTree

#include "binaryTree.h"

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
private:
    using Node = binaryTreeNode<elemType>;

    void insert(Node*& p, const elemType& item)
    {
        if (p == nullptr)
        {
            p = new Node;
            p->info = item;
            p->llink = nullptr;
            p->rlink = nullptr;
        }
        else if (item < p->info)
        {
            insert(p->llink, item);
        }
        else if (item > p->info)
        {
            insert(p->rlink, item);
        }
    }

public:
    void insert(const elemType& item)
    {
        insert(this->root, item);
    }
};

#endif
