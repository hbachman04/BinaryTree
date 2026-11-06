#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    bSearchTreeType<int> intTree;

    cout << "Test 1: Empty Tree" << endl;
    cout << "Postorder traversal: ";
    intTree.postorderTraversal();
    cout << endl << endl;

    cout << "Test 2: One Item" << endl;
    intTree.insert(50);

    cout << "Postorder traversal: ";
    intTree.postorderTraversal();
    cout << endl << endl;

    intTree.destroyTree();

    cout << "Test 3: Multiple Items" << endl;

    intTree.insert(50);
    intTree.insert(30);
    intTree.insert(70);
    intTree.insert(20);
    intTree.insert(40);
    intTree.insert(60);
    intTree.insert(80);

    cout << "Postorder traversal: ";
    intTree.postorderTraversal();
    cout << endl << endl;

    intTree.destroyTree();

    cout << "Tree memory has been released." << endl;

    return 0;
}