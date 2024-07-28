#include <iostream>
// using namespace std;
#include <algorithm>

using Rank = unsigned int;
#define DEFAULT_CAPACITY  3 //默认的初始容量（实际应用中可设置为更大）

template <typename T> class Vector
{
    protected:
        Rank _size;
        Rank _capacity;
        T *_elem;

        void expand()
        {
            if(_size < _capacity)
                return;
            if(_capacity < DEFAULT_CAPACITY)
                _capacity = DEFAULT_CAPACITY;

            T * old_elem = _elem;
            _elem = new T[_capacity *= 2];
            for (Rank i = 0; i < _size;i++)
                _elem[i] = old_elem[i];
            delete[] old_elem;
        }

        void shrink()
        {
            if (_capacity < DEFAULT_CAPACITY * 2)
                return;
            if (_size*2 > _capacity) // 小于25%
                return;
            T *old_elem = _elem;
            _elem = new T[_capacity >>= 1];
            for (Rank i = 0; i < _size;i++)
                _elem[i] = old_elem[i];
            delete[] old_elem;
        }

    public:

        Vector(Rank c = DEFAULT_CAPACITY,Rank s = 0,T v = 0)
        {
            _elem = new T[_capacity = c];
            for (_size = 0; _size < s;_size++)
                _elem[_size] = v;
        }

        Vector( Vector<T> const& V ,Rank lo,Rank hi)
        {
            copyfrom(V._elem, lo, hi);
        }

        Vector( Vector<T> const& V)
        {
            copyfrom(V._elem, 0, V.size());
        }

        void copyfrom(T const* A,Rank lo,Rank hi)
        {
            _elem = new T[_capacity = std::max<Rank>(DEFAULT_CAPACITY, 2 * (hi - lo))];
            _size = 0;
            while(lo<hi)
                _elem[_size++] = A[lo++];
        }

        T &operator[](Rank r) { return _elem[r]; }
        const T& operator[](Rank r) const { return _elem[r]; }

        Rank size() const
        {
            return _size;
        }

        T get(Rank r) const
        {
            return _elem[r];
        }

        Rank capacity() const
        {
            return _capacity;
        }


        Rank insert(Rank r, T const& e) //插入元素
        {
            expand();
            for (Rank i = _size; i > r;i--)
            {
                _elem[i] = _elem[i-1];
            }
            _elem[r] = e;
            _size++;
            return r;
        }

        Rank remove(Rank lo, Rank hi) // 区间删除
        {
            if (lo == hi)
                return 0;
            while(hi<_size)
                _elem[lo++] = _elem[hi++];
            _size = lo;
            return hi - lo;
        }

        T remove(Rank r) // 单个元素删除
        {
            T e = _elem[r];
            remove(r, r + 1);
            _size--;
            return e;
        }

        Rank find(Rank lo, Rank hi, T const &e) const // 线性查找，O(n);查找范围[lo,hi);若查找失败，返回-1
        {
            while(hi-->lo && _elem[hi] != e);
            return hi;
        } 

        Rank find(T const &e) const
        {
            return find(0, _size, e);
        }

        void merge(Rank lo,Rank mi,Rank hi)
        {
            T *temp = new T[mi - lo];
            for (Rank t = 0; t < mi - lo;t++)
                temp[t] = _elem[lo + t];
            Rank i = 0, j = 0, r = 0;
            while( (i<mi - lo) || (j<hi - mi))
            {
                _elem[lo + r++] = temp[i] <= _elem[mi + j] ? temp[i++] : _elem[mi + j++];
                if(i == mi - lo)
                    break;
                if(j==hi-mi)
                    while(i<mi-lo)
                        _elem[lo + r++] = temp[i++];
            }
            delete[] temp;
        }

        void mergeSort(Rank lo,Rank hi)
        {
            if(hi - lo < 2)
                return;
            Rank mi = (lo + hi) / 2;
            mergeSort(lo, mi);
            mergeSort(mi , hi);
            if(_elem[mi - 1]>_elem[mi])
                merge(lo, mi, hi);
        }

        void traverse()
        {
            for (Rank i = 0; i < _size;i++)
                std::cout <<"[" << _elem[i]<<"]";
            std::cout << std::endl;
        }
};