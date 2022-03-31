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
    auto dfs_s(TreeNode* node, std::string& tree) -> void
    {
        if (node == NULL)
            tree += '#';
        else {
            tree += std::to_string(node->val) + ',';  // 注意用符号分割
            dfs_s(node->left, tree);
            dfs_s(node->right, tree);
        }
    }

    char* Serialize(TreeNode* root)
    {
        std::string tree;
        dfs_s(root, tree);

        char* result = new char[tree.size() + 1];
        strcpy(result, tree.c_str());
        return result;
    }

    // 指针的引用
    auto dfs_d(char*& str) -> TreeNode*
    {
        if (*str == '#') {
            str += 1;
            return NULL;
        }

        int val = 0;
        while (*str != ',') {
            val = val * 10 + (*str - '0');  // 注意char转int的计算
            str++;
        }

        TreeNode* root = new TreeNode(val);
        str++;
        root->left  = dfs_d(str);
        root->right = dfs_d(str);

        return root;
    }

    TreeNode* Deserialize(char* str)
    {
        return dfs_d(str);
    }
};