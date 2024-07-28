#include <iostream>
#include "BinNode.h"

using namespace std;

int main()
{
    BinNode<int>* node1 = new BinNode<int>(1);

    BinNode<int>* node2 = node1->insertAsLC(2);
    BinNode<int>* node3 = node1->insertAsRC(3);
    BinNode<int>* node4 = node2->insertAsLC(4);
    BinNode<int>* node5 = node2->insertAsRC(5);


    std::cout << "Size of the tree: " << node1->size() << std::endl;
    std::cout << "Is node1 the root? " << (node1->IsRoot() ? "Yes" : "No") << std::endl;
    std::cout << "Is node2 a left child? " << (node2->IsLChild() ? "Yes" : "No") << std::endl;
    std::cout << "Is node3 a right child? " << (node3->IsRChild() ? "Yes" : "No") << std::endl;


    BinNode<int>* newNode = node3->insertAsLC(6);
    std::cout << "Inserted node with value 7 as the left child of node3." << std::endl;

    newNode = node3->insertAsRC(7);
    std::cout << "Inserted node with value 8 as the right child of node3." << std::endl;

    BinNode<int>* nodeSucc = node5->succ();

    if (nodeSucc)
        std::cout << "The successor of node2: " << nodeSucc->data << std::endl;
    else
        std::cout << "Node2 has no successor." << std::endl;


    return 0;
}
