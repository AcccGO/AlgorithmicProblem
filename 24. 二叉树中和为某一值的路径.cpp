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
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
    {
        std::vector<int> current_path;
        std::vector<std::vector<int>> result;
        if (root == NULL) return result;

        DFS(root, expectNumber, current_path, result);

        // 排序
        std::sort(result.begin(), result.end(), [](const std::vector<int> x, const std::vector<int> y) { return x.size() > y.size(); });

        return result;
    }

    auto DFS(TreeNode* root, int expectNumber, std::vector<int>& current_path, std::vector<std::vector<int>>& result) -> void
    {
        current_path.emplace_back(root->val);

        // 已到达叶子节点
        if (root->left == NULL && root->right == NULL && root->val == expectNumber) {
            result.emplace_back(current_path);
        }

        if (root->left != NULL)
            DFS(root->left, expectNumber - root->val, current_path, result);

        if (root->right != NULL)
            DFS(root->right, expectNumber - root->val, current_path, result);

        // 不要忘了弹出当前节点
        current_path.pop_back();
    }
};