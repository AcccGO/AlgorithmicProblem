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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        // corner case
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;

        ListNode *head1          = pHead1;
        ListNode *head2          = pHead2;
        ListNode *result_current = new ListNode(-1);
        ListNode *result_head    = result_current;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                result_current->next = head1;
                head1                = head1->next;
            } else {
                result_current->next = head2;
                head2                = head2->next;
            }

            result_current = result_current->next;
        }

        result_current->next = (head1 != NULL
                                    ? head1
                                    : head2);

        return result_head->next;
    }
};