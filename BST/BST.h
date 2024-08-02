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
            return BinTree<T>::insert(e);
        }
        BinNode<T> *x = search(e);
        if(x) return x;

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

        removeAt(x, this->_hot);
        BinTree<T>::updateHeightAbove(this->_hot);
        return true;
    }
    
    static BinNode<T> * removeAt(BinNode<T>*&x,BinNode<T>*& hot)
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
            w = w->succ();
            T temp = x->data;
            x->data = w->data;
            w->data = temp;
            BinNode<T> *u = w->parent;

            succ = w->rChild;
            if(u==x)
            {
                u->rChild = succ;
            }
            else
                u->lChild = succ;
        }

        hot = w->parent;

        if(succ)
        {
            succ->parent = hot;
        }
        else // 被删除的节点是叶节点,没有左右孩子
        {
            if(x->IsRoot())
                return nullptr;
            if(x->IsLChild())
                hot->lChild = nullptr;
            else
                hot->rChild = nullptr;
        }
        return succ;
    }
};
