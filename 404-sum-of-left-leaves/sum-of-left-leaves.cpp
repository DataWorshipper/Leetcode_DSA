class Solution {
public:

bool isLeaf(TreeNode* node){
    return node && node->left == NULL && node->right == NULL;
}

int ans = 0;

void f(TreeNode* root)
{
    if(root == NULL)
        return;

    if(isLeaf(root->left))
        ans += root->left->val;

    f(root->left);
    f(root->right);
}

int sumOfLeftLeaves(TreeNode* root) {
    f(root);
    return ans;
}
};