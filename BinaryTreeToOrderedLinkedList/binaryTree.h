#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "orderedLinkedList.h"

class binaryTree
{
private:
    struct treeNode
    {
        int info;
        treeNode* left;
        treeNode* right;
    };

    treeNode* root;

    void insertNode(treeNode*& current, int value);
    void insertIntoLinkedList(
        treeNode* current,
        orderedLinkedList& list);

    void destroyTree(treeNode* current);

public:
    binaryTree();
    ~binaryTree();

    void insert(int value);
    void createList(orderedLinkedList& list);
};

#endif