#include <iostream>
#include "binaryTree.h"
#include "orderedLinkedList.h"

using namespace std;

int main()
{
    binaryTree tree;
    orderedLinkedList list;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Test 1: Tree with seven values" << endl;

    tree.createList(list);

    cout << "Ordered linked list: ";
    list.print();

    binaryTree singleNodeTree;
    singleNodeTree.insert(25);

    cout << "\nTest 2: Tree with one value" << endl;

    singleNodeTree.createList(list);

    cout << "Ordered linked list: ";
    list.print();

    binaryTree emptyTree;

    cout << "\nTest 3: Empty tree" << endl;

    emptyTree.createList(list);

    cout << "Ordered linked list: ";
    list.print();

    binaryTree reverseTree;
    reverseTree.insert(80);
    reverseTree.insert(60);
    reverseTree.insert(40);
    reverseTree.insert(20);

    cout << "\nTest 4: Values inserted in descending order" << endl;

    reverseTree.createList(list);

    cout << "Ordered linked list: ";
    list.print();

    return 0;
}