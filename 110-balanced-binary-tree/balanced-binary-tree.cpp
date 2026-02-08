/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    int maxDepth(TreeNode* root) {
        TreeNode *node=root;
        if(node==NULL)
        return 0;
         int lh= maxDepth(node->left);
        int rh= maxDepth(node->right);
        if(lh==-1||rh==-1)
        return -1;
        if(abs(lh-rh)>1)
        return -1;

return max(rh,lh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        TreeNode *node=root;
        if(root==NULL)
        return true;
        int m=maxDepth(node);
        if(m==-1)
        return false;
        else return true;
    }
};