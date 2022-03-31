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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        auto p1 = pHead1, p2 = pHead2;
        if (p1 == NULL || p2 == NULL) return NULL;

        // 假设公共节点后长度为n
        // p1长度 a + n
        // p2长度 b + n
        // p1在遍历 a + n + b
        // p2在遍历 b + n + a
        // 以后，两者相遇

        // 对公共节点定义存疑。。
        while (p1 != p2) {
            p1 = p1 == NULL ? pHead2 : p1->next;
            p2 = p2 == NULL ? pHead1 : p2->next;
        }

        return p1;
    }
};