
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>

using namespace std;

template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType>* llink;
    binaryTreeNode<elemType>* rlink;
};

template <class elemType>
class binaryTreeType
{
protected:
    binaryTreeNode<elemType>* root;

private:
    void postorder(binaryTreeNode<elemType>* p) const
    {
        if (p != nullptr)
        {
            postorder(p->llink);
            postorder(p->rlink);
            cout << p->info << " ";
        }
    }

    void destroy(binaryTreeNode<elemType>*& p)
    {
        if (p != nullptr)
        {
            destroy(p->llink);
            destroy(p->rlink);
            delete p;
            p = nullptr;
        }
    }

public:
    binaryTreeType()
    {
        root = nullptr;
    }

    virtual ~binaryTreeType()
    {
        destroyTree();
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void postorderTraversal() const
    {
        postorder(root);
    }

    void destroyTree()
    {
        destroy(root);
    }
};

#endif
