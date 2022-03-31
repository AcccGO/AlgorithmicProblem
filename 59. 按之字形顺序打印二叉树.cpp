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
        std::deque<TreeNode*> tree;
        vector<vector<int> > result;

        if (pRoot == NULL) return result;
        tree.emplace_back(pRoot);

        int level = 0;
        while (!tree.empty()) {
            int size = tree.size();
            std::deque<TreeNode*> tmp_tree;
            vector<int> current_level;

            while (size) {
                // 根据方向判断从前相互还是从后向前
                auto current_node = (level % 2 == 0) ? tree.front() : tree.back();
                current_level.emplace_back(current_node->val);

                // 捋清楚这边的deque里的顺序，始终保持存放的是从左到右的节点，不同层只改变遍历方向
                if (level % 2 == 0) {
                    if (current_node->left) tmp_tree.push_back(current_node->left);
                    if (current_node->right) tmp_tree.push_back(current_node->right);
                    tree.pop_front();
                } else {
                    if (current_node->right) tmp_tree.push_front(current_node->right);
                    if (current_node->left) tmp_tree.push_front(current_node->left);
                    tree.pop_back();
                }

                size--;
            }

            level++;
            tree = tmp_tree;

            // 还有一种思路是根据level直接reverse vector
            //             reverse(current_level.begin(), current_level.end());
            result.emplace_back(std::move(current_level));
        }

        return result;
    }
};