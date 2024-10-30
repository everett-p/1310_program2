#ifndef NODE_H
#define NODE_H

template <typename L>
class ListNode
{
    private: 
        L value;
        ListNode<L> *next;
    public:
        ListNode(L val) : value(val), next(nullptr) {}

        L getData()
        {
            return value;
        }

        void setData(L test) 
        {
            value = test;
        }

        ListNode* iterateForward() 
        {
            return next;
        }

        



};

#endif