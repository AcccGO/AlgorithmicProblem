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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        // corner case
        if (pListHead == NULL || k == 0)
            return NULL;

        // 设置两个指针，p2指针先走（k-1）步，然后再一起走，当p2为最后一个时，p1就为倒数第k个数
        ListNode *head0 = pListHead;
        ListNode *head1 = head0;

        for (unsigned int i = 0; i < k; i++) {
            if (head1 != NULL)
                head1 = head1->next;
            else
                return NULL;
        }

        while (head1 != NULL) {
            head0 = head0->next;
            head1 = head1->next;
        }

        return head0;
    }
};