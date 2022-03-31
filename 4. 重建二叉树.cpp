/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        // corner case / return case
        if (pre.empty())
            return NULL;

        // return case
        int root = pre[0];
        int i;
        for (i = 0; i < vin.size(); i++) {
            if (vin[i] == root)
                break;
        }
        TreeNode *new_node = new TreeNode(root);

        // assign 左闭右开
        if (i > 0) {
            vector<int> new_pre_left(pre.begin() + 1, pre.begin() + i + 1);
            vector<int> new_vin_left(vin.begin(), vin.begin() + i);
            new_node->left = reConstructBinaryTree(new_pre_left, new_vin_left);
        }
        if (i < pre.size() - 1) {
            vector<int> new_pre_right(pre.begin() + i + 1, pre.end());
            vector<int> new_vin_right(vin.begin() + i + 1, vin.end());
            new_node->right = reConstructBinaryTree(new_pre_right, new_vin_right);
        }
        return new_node;
    }
};