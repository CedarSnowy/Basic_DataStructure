#include "../BST/BST.h"

template <typename T> class AVL : public BST<T> 
{
public:
    static int BalFac(BinNode<T>* x)
    {
        return BinNode<T>::stature(x->lChild) - BinNode<T>::stature(x->rChild);
    }

    static bool AvlBalanced(BinNode<T>* x)
    {
        return (-2 < BalFac(x) && BalFac(x) < 2);
    }

    static BinNode<T>* tallerChild(BinNode<T>* x)
    {
        if(BinNode<T>::stature(x->lChild) > BinNode<T>::stature(x->rChild))
            return x->lChild;
        else if(BinNode<T>::stature(x->lChild) < BinNode<T>::stature(x->rChild))
            return x->rChild;
        else
        {
            if(x->lChild)
                return x->lChild;
            else
                return nullptr;
        }
    }

    static BinNode<T>* rotateAt(BinNode<T>* v)
    {   
        BinNode<T>* p = v->parent;
        BinNode<T>* g = p->parent;

        int vp = v->IsLChild();
        int pg = p->IsLChild();

        switch (vp | pg<<1)
        {
        case 0b11:
            return connect34(v,p,g,v->lChild,v->rChild,p->rChild,g->rChild);
            break;
        case 0b00:
            return connect34(g,p,v,g->lChild,p->lChild,v->lChild,v->rChild);
            break;
        case 0b01:
            return connect34(g,v,p,g->lChild,v->lChild,v->rChild,p->rChild);
            break;
        case 0b10:
            return connect34(p,v,g,p->lChild,v->lChild,v->rChild,g->rChild);
            break;
        }

    }

    static BinNode<T>* connect34(BinNode<T>* a, BinNode<T>* b, BinNode<T>* c,BinNode<T>* T0, BinNode<T>* T1, BinNode<T>* T2, BinNode<T>* T3)
    {
        a->lChild = T0;
        if(T0) T0->parent = a;
        a->rChild = T1;
        if(T1) T1->parent = a;

        b->lChild = a;
        b->rChild = c;

        c->lChild = T2;
        if(T2) T2->parent = c;
        c->rChild = T3;
        if(T3) T3->parent = c;

        return b;

    }

    BinNode<T>* insert(const T & e)
    {
        if(this->_size==0)
        {
            return BinTree<T>::insert(e);
        }

        BinNode<T>* x = search(e);
        if(x) return x;

        if(e<_hot->data)
            x = this->_hot->insertAsLC(e);
        else
            x = this->_hot->insertAsRC(e);

        BinNode<T>* g = _hot;
        while(g)
        {
            if(AvlBalanced(g))
                updateHeight(g);
            else
            {
                BinNode<T>* center =  rotateAt(tallerChild(tallerChild(g)));
                break;
            }

            g=g->parent;
        }

        return x;
    }

    bool remove(const T & e)
    {

    }



};
