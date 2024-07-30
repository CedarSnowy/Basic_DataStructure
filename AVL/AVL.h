#include "../BinTree/BinTree.h"

template <typename T> class AVL : public BinTree<T> 
{
public:
    static int BalFac(BinNode<T>* x)
    {
        return BinNode<T>::stature(x->lChild) - BinNode<T>::stature(x->rChild);
    }

};
