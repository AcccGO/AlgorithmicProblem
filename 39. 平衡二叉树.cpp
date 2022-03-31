class Solution
{
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        //         if(pRoot == NULL) return true;

        //         auto left_height = height(pRoot -> left);
        //         auto right_height = height(pRoot -> right);
        //         if(abs(right_height - left_height) > 1) return false;

        //         return IsBalanced_Solution(pRoot -> left) && IsBalanced_Solution(pRoot -> right);

        // better solution
        // start from bottom to top
        bool success = true;
        dfs(pRoot, success);
        return success;
    }

    //     int height(TreeNode* node){
    //         if(node == NULL) return 0;

    //         return max(height(node -> left), height(node -> right)) + 1;
    //     }

    int dfs(TreeNode* node, bool& success)
    {
        if (node == NULL) return 0;
        if (!success) return 0;  // just skip

        auto left_height  = dfs(node->left, success);
        auto right_height = dfs(node->right, success);
        if (abs(left_height - right_height) > 1) {
            success = false;
            return 0;
        }
        return max(left_height, right_height) + 1;
    }
};