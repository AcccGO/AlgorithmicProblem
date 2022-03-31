/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution
{
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        // corner case
        if (pRootOfTree == NULL) return NULL;

        // 根据样例要求，最后得返回最小的节点
        // 一开始返回了原本的根节点， 但是题干里没对返回的数进行说明啊
        return m_Convert(pRootOfTree, false);
    }

    // 题目的本质是中序遍历
    TreeNode* m_Convert(TreeNode* pRootOfTree, bool is_left)
    {
        // return case
        if (pRootOfTree == NULL) return NULL;

        auto prev = m_Convert(pRootOfTree->left, true);
        if (prev != NULL) {
            prev->right       = pRootOfTree;
            pRootOfTree->left = prev;
        }

        auto next = m_Convert(pRootOfTree->right, false);
        if (next != NULL) {
            next->left         = pRootOfTree;
            pRootOfTree->right = next;
        }

        if (is_left) {
            while (pRootOfTree->right != NULL) pRootOfTree = pRootOfTree->right;
        } else {
            while (pRootOfTree->left != NULL) pRootOfTree = pRootOfTree->left;
        }

        return pRootOfTree;
    }
};