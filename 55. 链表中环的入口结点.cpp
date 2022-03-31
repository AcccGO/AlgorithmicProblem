/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution
{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        std::set<ListNode*> st;
        auto p = pHead;
        while (p) {
            st.emplace(p);
            if (st.find(p->next) != st.end()) return p->next;
            p = p->next;
        }
        return NULL;
    }
};