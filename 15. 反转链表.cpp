/*
struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
                        val(x), next(NULL) {
        }
};*/
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *last    = NULL;
        ListNode *current = pHead;
        ListNode *next    = NULL;  // 作用仅仅是为了让current向前迈步，可以直接放到循环里去赋值。这样就不用提前处理head为空的corner case了

        while (current != NULL) {
            next          = current->next;
            current->next = last;
            last          = current;
            current       = next;
        }

        return last;
    }
};