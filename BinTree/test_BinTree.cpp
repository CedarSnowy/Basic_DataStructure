#include <iostream>
#include "BinTree.h"

int main() {
    BinTree<int> tree;

    // 测试插入根节点
    tree.insert(1);
    std::cout << "root value: " << tree.root()->data << std::endl;

    // 测试插入左孩子
    BinNode<int>* leftChild = tree.insert(2, tree.root());
    std::cout << "left child value: " << leftChild->data << std::endl;

    // 测试插入右孩子
    BinNode<int>* rightChild = tree.insert(tree.root(), 3);
    std::cout << "right child value: " << rightChild->data << std::endl;

    // 测试接入左子树
    BinTree<int>* subTree = new BinTree<int>();
    BinNode<int>* subRoot = subTree->insert(4);
    BinNode<int>* attachedNode = tree.attach(subTree, leftChild);
    std::cout << "attached node value: " << attachedNode->data << std::endl;

    // 测试接入右子树
    subTree = new BinTree<int>();
    subRoot = subTree->insert(5);
    attachedNode = tree.attach(rightChild, subTree);
    std::cout << "attached node value: " << attachedNode->data << std::endl;

    tree.remove(tree._root);

    return 0;
}
