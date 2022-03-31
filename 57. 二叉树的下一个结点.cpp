/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution
{
public:
    auto in_order(TreeLinkNode* node, std::vector<TreeLinkNode*>& tree) -> void
    {
        if (node == NULL) return;
        in_order(node->left, tree);
        tree.emplace_back(node);
        in_order(node->right, tree);
    }

    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* root{NULL};
        auto tmp = pNode;
        while (tmp != NULL) {
            root = tmp;
            tmp  = tmp->next;
        }

        std::vector<TreeLinkNode*> tree;
        in_order(root, tree);

        auto index = 0;
        for (auto const& i : tree) {
            if (i == pNode && index + 1 < tree.size()) return tree[index + 1];  // 注意判断是否越界
            index++;
        }

        return NULL;
    }
};