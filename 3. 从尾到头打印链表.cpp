/**
 *  struct ListNode {
 *        int val;
 *        struct ListNode *next;
 *        ListNode(int x) :
 *              val(x), next(NULL) {
 *        }
 *  };
 */
class Solution
{
public:
    //     // 递归调用层数太多，引起段错误
    //     void print_val(std::vector<int>& result, ListNode* head){
    //         if(head->next != NULL){
    //             print_val(result, head->next);
    //         }
    //         result.emplace_back(head->val);
    //         return;
    //     }

    vector<int> printListFromTailToHead(ListNode *head)
    {
        //         print_val(result, head);

        // 先确定数目，O(2N)
        int count      = 0;
        ListNode *node = head;
        while (node != NULL) {
            count++;
            node = node->next;
        }

        std::vector<int> result(count);
        node      = head;
        int index = count - 1;
        while (node != NULL) {
            result[index] = node->val;
            index--;
            node = node->next;
        }

        return result;
    }
};