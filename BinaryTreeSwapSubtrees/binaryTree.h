#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

using namespace std;

template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType>* lLink;
	binaryTreeNode<elemType>* rLink;
};

template <class elemType>
class binaryTreeType
{
protected:
    binaryTreeNode<elemType>* root;

private:
    void inorder(binaryTreeNode<elemType>* p) const
    {
        if (p != nullptr)
        {
            inorder(p->lLink);
            cout << p->info << " ";
            inorder(p->rLink);
        }
    }
    void preorder(binaryTreeNode<elemType>* p) const
    {
        if (p != nullptr)
        {
            cout << p->info << " ";
            preorder(p->lLink);
            preorder(p->rLink);
        }
    }

    void destroy(binaryTreeNode<elemType>*& p)
    {
        if (p != nullptr)
        {
            destroy(p->lLink);
            destroy(p->rLink);
            delete p;
            p = nullptr;
        }
    }

    void swapSubtrees(binaryTreeNode<elemType>* p)
    {
        if (p != nullptr)
        {
            binaryTreeNode<elemType>* temp = p->lLink;

            p->lLink = p->rLink;
            p->rLink = temp;

            swapSubtrees(p->lLink);
            swapSubtrees(p->rLink);
        }
    }

public:
    binaryTreeType()
    {
        root = nullptr;
    }

    virtual ~binaryTreeType()
    {
        destroy(root);
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void inorderTraversal() const
    {
        inorder(root);
    }

    void preorderTraversal() const
    {
        preorder(root);
    }

    void swapSubtrees()
    {
        swapSubtrees(root);
    }
};

#endif