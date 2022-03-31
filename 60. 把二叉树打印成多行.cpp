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
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector<vector<int> > result;
        print_node(pRoot, 0, result);
        return result;
    }

    void print_node(TreeNode* node, int level, vector<vector<int> >& result)
    {
        if (node == NULL) return;
        if (result.size() < level + 1) result.emplace_back(std::vector<int>{});

        result[level].emplace_back(node->val);

        print_node(node->left, level + 1, result);
        print_node(node->right, level + 1, result);
    }
};