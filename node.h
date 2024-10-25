#ifndef NODE_H
#define NODE_H

template <typename L>
class ListNode
{
    private: 
        L value;
        struct ListNode *next;
    public:
        ListNode(L val) : value(val), next(nullptr) {}

        



};

#endif