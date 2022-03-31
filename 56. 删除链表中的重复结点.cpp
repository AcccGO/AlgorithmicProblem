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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* head = new ListNode(0);
        head->next     = pHead;
        auto last      = head;
        auto current   = pHead;

        while (current != NULL) {
            if (current->next && current->next->val == current->val) {
                while (current->next && current->next->val == current->val) {
                    current = current->next;
                }
                current    = current->next;
                last->next = current;
            } else {
                last    = current;
                current = current->next;
            }
        }

        return head->next;
    }
};