
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    bSearchTreeType<int> tree1;
    bSearchTreeType<int> tree2;
    bSearchTreeType<int> tree3;

    int number;

    cout << "Enter numbers ending with -999: ";

    cin >> number;

    while (number != -999)
    {
        tree1.insert(number);
        cin >> number;
    }

    cout << endl;
    cout << "tree1 nodes in postorder: ";
    tree1.postorderTraversalAndInsert(tree2);
    cout << endl << endl;

    cout << "tree2 nodes in preorder: ";
    tree2.preorderTraversalAndInsert(tree3);
    cout << endl << endl;

    cout << "tree3 nodes in inorder: ";
    tree3.inorderTraversal();
    cout << endl;

    cout << "tree1 height: " << tree1.height() << endl;
    cout << "tree1 leaves: " << tree1.leavesCount() << endl;

    cout << "tree2 height: " << tree2.height() << endl;
    cout << "tree2 leaves: " << tree2.leavesCount() << endl;

    cout << "tree3 height: " << tree3.height() << endl;
    cout << "tree3 leaves: " << tree3.leavesCount() << endl;

    return 0;
}
