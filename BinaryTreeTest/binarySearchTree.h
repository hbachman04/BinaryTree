
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

    void postorderInsert(Node* p, bSearchTreeType<elemType>& destination) const
    {
        if (p != nullptr)
        {
            postorderInsert(p->llink, destination);
            postorderInsert(p->rlink, destination);

            cout << p->info << " ";
            destination.insert(p->info);
        }
    }

    void preorderInsert(Node* p, bSearchTreeType<elemType>& destination) const
    {
        if (p != nullptr)
        {
            cout << p->info << " ";
            destination.insert(p->info);

            preorderInsert(p->llink, destination);
            preorderInsert(p->rlink, destination);
        }
    }

public:
    void insert(const elemType& item)
    {
        insert(this->root, item);
    }

    void postorderTraversalAndInsert(bSearchTreeType<elemType>& destination) const
    {
        postorderInsert(this->root, destination);
    }

    void preorderTraversalAndInsert(bSearchTreeType<elemType>& destination) const
    {
        preorderInsert(this->root, destination);
    }
};

#endif
