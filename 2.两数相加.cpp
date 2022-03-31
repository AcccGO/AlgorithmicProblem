/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        std::vector<int> result;
        result.push_back(0);

        int index = 0;
        auto ll1 = l1, ll2 = l2;

        while (ll1 != NULL && ll2 != NULL) {
            result.push_back(0);
            auto temp = ll1->val + ll2->val;
            if (index > 0) {
                temp += result[index];
            }

            result[index] = temp % 10;
            if (temp > 9) {
                result[index + 1] = 1;
            }

            index++;
            ll1 = ll1->next;
            ll2 = ll2->next;
        }

        while (ll1 != NULL) {
            result.push_back(0);
            auto temp = ll1->val;
            if (index > 0) {
                temp += result[index];
            }

            result[index] = temp % 10;
            if (temp > 9) {
                result[index + 1] = 1;
            }

            index++;
            ll1 = ll1->next;
        }

        while (ll2 != NULL) {
            result.push_back(0);
            auto temp = ll2->val;
            if (index > 0) {
                temp += result[index];
            }

            result[index] = temp % 10;
            if (temp > 9) {
                result[index + 1] = 1;
            }

            index++;
            ll2 = ll2->next;
        }

        if (result.back() == 0)
            result.pop_back();

        auto length       = result.size();
        ListNode* final   = NULL;
        ListNode* current = NULL;
        ListNode* temp    = NULL;
        for (int i = length - 1; i >= 0; i--) {
            current       = new ListNode(result[i]);
            current->next = temp;
            temp          = current;
        }
        return current;
    }
};
// @lc code=end

// Best solution
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL and l2 == NULL)
            return NULL;
        else if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;

        int a       = l1->val + l2->val;
        ListNode* p = new ListNode(a % 10);
        p->next     = addTwoNumbers(l1->next, l2->next);
        if (a >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
        return p;
    }
};