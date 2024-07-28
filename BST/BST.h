#include "../BinTree/BinTree.h"
// #include "../BinTree/BinNode.h"


template <typename T> class BST : public BinTree<T> 
{
public:
    BinNode<T>* _hot;

    BinNode<T>* search(const T& e)
    {
        if(!this->_root || e== this->_root->data)
        {
            _hot = nullptr;
            return this->_root;
        }
        _hot = this->_root;
        while(true)
        {
            BinNode<T> *&v = e < _hot->data ? _hot->lChild : _hot->rChild;
            if(!v || e==v->data)
                return v;
            _hot = v;
        }
    }


    virtual BinNode<T>* insert(const T& e)
    {
        if(this->_size==0)
        {
            this->_size = 1;
            return this->_root = new BinNode<T>(e);
        }
        BinNode<T> *x = search(e);
        if(x)
            return x;

        //x = new BinNode<T>(e);
        //x->parent = _hot;
        if(e<_hot->data)
            BinTree<T>::insert(e,_hot);
        else
            BinTree<T>::insert(_hot, e);

        return x;
    }

    bool remove(const T&e)
    {
        BinNode<T> *x = search(e);
        if(!x)
            return false;

        removeAt(x, _hot);
    }
    
    static removeAt(BinNode<T>*&x,BinNode<T>*& _hot)
    {
        BinNode<T> *succ = nullptr;
        BinNode<T> *w = x;
        if(!x->lChild)
        {
            succ = x->rChild;
        }
        else if(!x->rChild)
        {
            succ = x->lChild;
        }
        else
        {
            succ = x->succ();
            T temp = x->data;
            x->data = succ->data;
            succ->data = temp;

        }
        hot = w->parent;
        if(succ)
    }
};
