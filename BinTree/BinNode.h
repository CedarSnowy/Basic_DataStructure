using Rank = unsigned int;

//typedef enum { RB_RED, RB_BLACK} RBColor; //节点颜色


/// @brief 
/// @tparam T 
template <typename T> class BinNode
{
public:

    T data;
    BinNode* parent, *lChild, *rChild;
    Rank height;

    BinNode()
    {
        parent = nullptr;
        lChild = nullptr;
        rChild = nullptr;
        height = 0;
    }
    
    BinNode( T e, BinNode* p =nullptr, BinNode* lc =nullptr,BinNode* rc =nullptr, int h = 0)
    {
        data = e;
        parent = p;
        lChild = lc;
        rChild = rc;
        height = h;
    }

    Rank size()
    {
        Rank s = 1;
        if(lChild)
            s += lChild->size();
        if(rChild)
            s += rChild->size();
        return s;
    }

    bool IsRoot(){return this->parent? false : true;}

    bool IsLChild(){return !IsRoot() && this == this->parent->lChild;}

    bool IsRChild(){return !IsRoot() && this== this->parent->rChild;}

    static int stature(BinNode* x){return x ? x->height : -1;}

    BinNode* insertAsLC( T const& e)
    {
        BinNode* x = new BinNode(e);
        this->lChild = x;
        x->parent = this;
        return x;
    } 

    BinNode* insertAsRC( T const& e)
    {
        BinNode* x = new BinNode(e);
        this->rChild = x;
        x->parent = this;
        return x;
    }

    BinNode* succ()
    {
        BinNode* x = this;
        if(this->rChild)
        {
            x = this->rChild;
            while(x->lChild)
                x = x->lChild;
        }
        else
        {
            while(x->IsRChild())
                x = x->parent;
            x = x->parent;
        }
        return x;
    }

};

