/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == NULL || k == 1)
            return head;

        int length = 0;
        auto tmp   = head;  // !不要直接用head
        while (tmp != NULL) {
            tmp = tmp->next;
            length++;
        }

        int group = length / k;

        ListNode* last_item_in_last_group = NULL;
        ListNode* last_item               = NULL;
        ListNode* final_head              = NULL;
        ListNode* current_item            = head;

        for (auto i = 0; i < group; i++) {
            ListNode* temp_last_item_in_last_group = NULL;
            for (auto j = 0; j < k; j++) {
                auto val      = current_item->val;
                ListNode* now = new ListNode(current_item->val);
                if (j == 0) {
                    temp_last_item_in_last_group = now;
                } else {
                    now->next = last_item;
                }

                if (j == k - 1) {
                    if (i == 0) {
                        final_head = now;
                    } else {
                        last_item_in_last_group->next = now;
                    }
                }

                last_item    = now;
                current_item = current_item->next;
            }
            last_item_in_last_group = temp_last_item_in_last_group;
        }
        if (last_item_in_last_group != NULL)
            last_item_in_last_group->next = current_item;
        return final_head;
    }
};
// @lc code=end
