
#include <iostream>
#include "BST.h"

using namespace std;

int main()
{

    //BinNode<int>* node1 = new BinNode<int>(1);
    BST<int> bstree;
    bstree.insert(2);
    bstree.insert(1);
    bstree.insert(3);
    bstree.insert(4);
    bstree.remove(2);
}
