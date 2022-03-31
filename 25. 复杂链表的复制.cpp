/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution
{
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        // corner case
        if (pHead == NULL) return NULL;

        // 复制原链表节点
        RandomListNode* head = pHead;
        while (head != NULL) {
            RandomListNode* new_node = new RandomListNode(head->label);
            RandomListNode* next     = head->next;
            head->next               = new_node;
            new_node->next           = next;
            head                     = next;
        }

        // 复制random指向
        head = pHead;
        while (head != NULL) {
            // 重点！看图想想！它们的相对关系还是保留的！厉害之处！
            // 没找出来的问题： 需要额外判断一下random是不是空的
            head->next->random = head->random == NULL ? NULL : head->random->next;

            head = head->next->next;
        }

        // 提取复制的链表
        RandomListNode* result = pHead->next;
        head                   = pHead;
        while (head != NULL) {
            // 又是一个坑点：解链的时候不能直接目标链，要把两条各自都彻彻底底分开，所以不能跳着遍历，必须挨个遍历
            // 因为题目里说到了： 注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空
            RandomListNode* next = head->next;
            if (next != NULL) head->next = next->next;

            head = next;
        }

        return result;
    }
};