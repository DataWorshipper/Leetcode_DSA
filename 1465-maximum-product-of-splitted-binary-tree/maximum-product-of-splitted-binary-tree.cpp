class Solution {
    long long tot_sum = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    long long dfs_sum(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs_sum(root->left);
        long long right = dfs_sum(root->right);

        long long curr = root->val + left + right;

        ans = max(ans, curr * (tot_sum - curr));

        return curr;
    }

public:
    int maxProduct(TreeNode* root) {
     
        function<void(TreeNode*)> getSum = [&](TreeNode* node) {
            if (!node) return;
            tot_sum += node->val;
            getSum(node->left);
            getSum(node->right);
        };

        getSum(root);

        dfs_sum(root);

        return ans % MOD;
    }
};
