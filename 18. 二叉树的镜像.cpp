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
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return;

        TreeNode *left  = pRoot->left;
        TreeNode *right = pRoot->right;

        Mirror(left);
        Mirror(right);
        pRoot->left  = right;
        pRoot->right = left;
    }
};