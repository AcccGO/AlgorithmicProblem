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
    int TreeDepth(TreeNode* pRoot)
    {
        //         int max_depth = 0;
        //         int current_depth = 0;

        //         m_TreeDepth(pRoot, current_depth, max_depth);

        //         return max_depth;

        if (pRoot == NULL) return 0;
        return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }

    //     void m_TreeDepth(TreeNode* node, int& current_depth, int& max_depth)
    //     {
    //         if(node == NULL){
    //             max_depth = max(max_depth, current_depth);
    //         } else {
    //             current_depth++;
    //             m_TreeDepth(node->left, current_depth, max_depth);
    //             m_TreeDepth(node->right, current_depth, max_depth);
    //             current_depth--;
    //         }

    //         return;
    //     }
};