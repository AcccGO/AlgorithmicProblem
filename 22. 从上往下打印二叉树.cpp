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
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        //         std::vector<int> result;
        //         std::vector<TreeNode*> nodes;

        //         if(root == NULL) return result;

        //         nodes.emplace_back(root);
        //         int index = 0;

        //         while(index < nodes.size()){
        //             auto node = nodes[index];
        //             result.emplace_back(node->val);
        //             if(node->left != NULL) nodes.emplace_back(node->left);
        //             if(node->right != NULL) nodes.emplace_back(node->right);

        //             index ++;
        //         }

        //         return result;

        // 不用vector， queue合适
        std::vector<int> result;
        if (root == NULL) return result;

        std::queue<TreeNode*> nodes;
        nodes.emplace(root);

        while (!nodes.empty()) {
            auto& node = nodes.front();
            result.emplace_back(node->val);
            if (node->left != NULL) nodes.emplace(node->left);
            if (node->right != NULL) nodes.emplace(node->right);

            nodes.pop();
        }

        return result;
    }
};