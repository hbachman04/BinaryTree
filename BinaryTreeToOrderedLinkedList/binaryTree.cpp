#include "binaryTree.h"

binaryTree::binaryTree()
{
    root = nullptr;
}

binaryTree::~binaryTree()
{
    destroyTree(root);
}

void binaryTree::insert(int value)
{
    insertNode(root, value);
}

void binaryTree::insertNode(treeNode*& current, int value)
{
    if (current == nullptr)
    {
        current = new treeNode;
        current->info = value;
        current->left = nullptr;
        current->right = nullptr;
    }
    else if (value < current->info)
    {
        insertNode(current->left, value);
    }
    else
    {
        insertNode(current->right, value);
    }
}

void binaryTree::createList(orderedLinkedList& list)
{
    list.initializeList();
    insertIntoLinkedList(root, list);
}

void binaryTree::insertIntoLinkedList(
    treeNode* current,
    orderedLinkedList& list)
{
    if (current != nullptr)
    {
        insertIntoLinkedList(current->left, list);

        list.insert(current->info);

        insertIntoLinkedList(current->right, list);
    }
}

void binaryTree::destroyTree(treeNode* current)
{
    if (current != nullptr)
    {
        destroyTree(current->left);
        destroyTree(current->right);
        delete current;
    }
}