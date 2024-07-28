#include "listNode.h"
#include <iostream>


template <typename T> class List
{
    private:
        Rank _size;
        ListNodePosi<T> trailer, header;

        void init()
        {
            header = new ListNode<T>;
            trailer = new ListNode<T>;
            header->pred = nullptr;
            trailer->succ = nullptr;
            header->succ = trailer;
            trailer->pred = header;
            _size = 0;
        }

    public:
        List() { init(); }

        ListNodePosi<T> first() const { return header->succ; } //首节点位置
        ListNodePosi<T> last() const { return trailer->pred; } //末节点位置
        Rank size() { return _size; }
        bool empty() { return _size<=0; }

        ListNodePosi<T> insert(ListNodePosi<T> p, T const& e)
        {
            _size++;
            return p->insertAsSucc(e);
        }

        ListNodePosi<T> insert(T const& e, ListNodePosi<T> p)
        {
            _size++;
            return p->insertAsPred(e);
        }   

        ListNodePosi<T> insertAsFirst(T const& e)
        {
            _size++;
            return header->insertAsSucc(e);
        }

        
        ListNodePosi<T> insertAsLast(T const& e)
        {
            _size++;
            return trailer->insertAsPred(e);
        }

        ListNodePosi<T> find(T const& e, Rank n, ListNodePosi<T> p) const // 无序查找
        {
            while(n--)
            {
                if( (p = p->pred)->data == e)
                    return p;
            }
            return nullptr;
        }

        ListNodePosi<T> find(T const& e) const // 无序查找
        {
            return find(e, _size, trailer);
        }

        T remove(ListNodePosi<T> p)
        {
            T e = p->data;
            p->succ->pred = p->pred;
            p->pred->succ = p->succ;
            delete p;
            _size--;
            return e;
        }

        void traverse()
        {
            ListNodePosi<T> x = header;
            while((x = x->succ) != trailer)
            {
                std::cout << x->data <<"<--";
            }
            std::cout << std::endl;
        }

        void traverse_re()
        {
            ListNodePosi<T> x = trailer;
            while((x = x->pred) != header)
            {
                std::cout << x->data <<"-->";
            }
            std::cout << std::endl;
        }

        ListNodePosi<T> merge(ListNodePosi<T> p,Rank n , List<T>& L,ListNodePosi<T> q,Rank m)
        {
            ListNodePosi<T> pp = p->pred;
            while(m>0 && q!=p)
            {
                if(n>0 && p->data<=q->data)
                {
                    p = p->succ;
                    n--;
                }
                else
                {
                    q = q->succ;
                    insert(L.remove(q->pred),p);
                    m--;
                }
            }
            return pp->succ;
        }

        void mergeSort(ListNodePosi<T>& p,Rank n)
        {
            if(n<2)
                return;
            Rank mi = n >> 1;
            ListNodePosi<T> q = p;
            for (Rank i = 0; i < mi;i++)
                q = q->succ;
            mergeSort(p, mi);
            mergeSort(q, n-mi);
            p = merge(p, mi,*this,q,n-mi);
        }
        
};