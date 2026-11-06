
#include <iostream>
#include "binaryTree.h"
#include "binarySearchTree.h"

using namespace std;

int main()
{
    bSearchTreeType<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "TEST 1: Tree with seven nodes" << endl;

    cout << "Inorder before swapping: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Preorder before swapping: ";
    tree.preorderTraversal();
    cout << endl;

    tree.swapSubtrees();

    cout << "Inorder after swapping: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Preorder after swapping: ";
    tree.preorderTraversal();
    cout << endl;

    tree.swapSubtrees();

    cout << "Inorder after swapping twice: ";
    tree.inorderTraversal();
    cout << endl << endl;

    bSearchTreeType<int> singleNodeTree;
    singleNodeTree.insert(25);

    cout << "TEST 2: Tree with one node" << endl;

    cout << "Before swapping: ";
    singleNodeTree.inorderTraversal();
    cout << endl;

    singleNodeTree.swapSubtrees();

    cout << "After swapping: ";
    singleNodeTree.inorderTraversal();
    cout << endl << endl;


    bSearchTreeType<int> emptyTree;

    cout << "TEST 3: Empty tree" << endl;

    cout << "Is the tree empty? "
        << (emptyTree.isEmpty() ? "Yes" : "No")
        << endl;

    emptyTree.swapSubtrees();

    cout << "After swapping, is the tree empty? "
        << (emptyTree.isEmpty() ? "Yes" : "No")
        << endl;

    cout << "Inorder traversal after swapping: ";
    emptyTree.inorderTraversal();
    cout << endl;

    return 0;
}
