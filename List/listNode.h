using Rank = unsigned int;

template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*; //列表节点位置

template <typename T> struct ListNode
{
    T data;
    ListNodePosi<T> pred, succ;

    ListNode(){}
    ListNode(T e,ListNodePosi<T> p = nullptr,ListNodePosi<T> s = nullptr)
    {
        data = e;
        pred = p;
        succ = s;
    }

    ListNodePosi<T> insertAsSucc(T const& e)
    {
        ListNodePosi<T> x = new ListNode(e,this,this->succ);
        this->succ->pred = x;
        this->succ = x;
        return x;
    }

    ListNodePosi<T> insertAsPred(T const& e)
    {
        ListNodePosi<T> x = new ListNode(e,this->pred,this);
        this->pred->succ = x;
        this->pred = x;
        return x;
    }
};