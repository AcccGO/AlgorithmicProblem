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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL) return NULL;

        std::stack<TreeNode*> m_stack;
        auto node  = pRoot;
        auto index = 0;
        while (node != NULL || !m_stack.empty()) {
            while (node != NULL) {
                m_stack.emplace(node);
                node = node->left;
            }

            node = m_stack.top();
            m_stack.pop();
            index++;
            if (index == k) return node;

            node = node->right;
        }

        return NULL;
    }
};