
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

    void inorder(binaryTreeNode<elemType>* p) const
    {
        if (p != nullptr)
        {
            inorder(p->llink);
            cout << p->info << " ";
            inorder(p->rlink);
        }
    }

    int treeHeight(binaryTreeNode<elemType>* p) const
    {
        if (p == nullptr)
            return 0;

        int leftHeight = treeHeight(p->llink);
        int rightHeight = treeHeight(p->rlink);

        if (leftHeight > rightHeight)
            return leftHeight + 1;

        return rightHeight + 1;
    }

    int countLeaves(binaryTreeNode<elemType>* p) const
    {
        if (p == nullptr)
            return 0;

        if (p->llink == nullptr && p->rlink == nullptr)
            return 1;

        return countLeaves(p->llink) + countLeaves(p->rlink);
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

    void inorderTraversal() const
    {
        inorder(root);
    }

    int height() const
    {
        return treeHeight(root);
    }

    int leavesCount() const
    {
        return countLeaves(root);
    }

    void destroyTree()
    {
        destroy(root);
    }
};

#endif
