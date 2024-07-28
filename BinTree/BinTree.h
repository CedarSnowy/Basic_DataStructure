#include "BinNode.h"
#include <algorithm>
#include <iostream>

template <typename T> class BinTree
{
public:
        Rank _size;
        BinNode<T>* _root;

        virtual Rank updateHeight(BinNode<T>* x)
        {
            return x->height = std::max(BinNode<T>::stature(x->lChild),BinNode<T>::stature(x->rChild)) + 1;
        }

        virtual void updateHeightAbove(BinNode<T>* x)
        {
            while(x)
            {
                updateHeight(x);
                x = x->parent;
            }
        }

        BinTree() : _size( 0 ), _root( nullptr ) {}
        Rank size() const { return _size; } 
        bool empty() const { return !_root; } 
        BinNode<T>* root() const { return _root; }

        BinNode<T>* insert( T const& e ) //插入根节点
        {
            _size = 1;
            return _root = new BinNode<T>(e);
        }
        BinNode<T>* insert( T const& e, BinNode<T>* x) //插入左孩子
        {
            _size++;
            x->insertAsLC(e);
            updateHeightAbove(x);
            return x->lChild;
        }
        BinNode<T>* insert( BinNode<T>* x, T const& e) //插入右孩子
        {
            _size++;
            x->insertAsRC(e);
            updateHeightAbove(x);
            return x->rChild;
        }
        BinNode<T>* attach( BinTree<T>*& S, BinNode<T>* x) //接入左子树
        {
            if(x->lChild = S->root())
                S->root()->parent = x;
            _size += S->size();
            updateHeightAbove(x);

            S->_root = nullptr;
            S->_size = 0;
            S = nullptr;

            return x;
        }

        BinNode<T>* attach( BinNode<T>* x, BinTree<T>*& S) //接入右子树
        {
            if(x->rChild = S->root())
                S->root()->parent = x;
            _size += S->size();
            updateHeightAbove(x);

            S->_root = nullptr;
            S->_size = 0;
            S = nullptr;

            return x;
        }

        Rank remove(BinNode<T>* x)
        {
            if(x->parent)
            {
                if(x->IsLChild())
                    x->parent->lChild = nullptr;
                else
                    x->parent->rChild = nullptr;

                updateHeightAbove(x->parent);
                Rank n = removeAt(x);
                _size -= n;
                return n;
            }
            else
            {
                Rank n = removeAt(x);
                return n;
            }

        }

        static Rank removeAt(BinNode<T>* x)
        {
            if(!x)
                return 0;

            Rank n = 1 + removeAt(x->lChild) + removeAt(x->rChild);
            return n;
        }

};