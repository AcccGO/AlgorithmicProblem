/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution
{
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return dfs(pRoot, pRoot);
    }

    bool dfs(TreeNode* n1, TreeNode* n2)
    {
        if (n1 == NULL && n2 == NULL) return true;
        if (n1 == NULL || n2 == NULL) return false;
        return n1->val == n2->val && dfs(n1->left, n2->right) && dfs(n1->right, n2->left);
    }
};