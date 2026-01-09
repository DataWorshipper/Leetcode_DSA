class Solution {
public:
    static const int LOG = 20;
    unordered_map<TreeNode*, int> depth;
    unordered_map<TreeNode*, vector<TreeNode*>> up;

  void dfs(TreeNode* node, TreeNode* parent) {
    up[node] = vector<TreeNode*>(LOG, nullptr);
    up[node][0] = parent;

    for (int i = 1; i < LOG; i++) {
        if (up[node][i-1])
            up[node][i] = up[ up[node][i-1] ][i-1];
    }

    if (node->left) {
        depth[node->left] = depth[node] + 1;
        dfs(node->left, node);
    }
    if (node->right) {
        depth[node->right] = depth[node] + 1;
        dfs(node->right, node);
    }

}

    TreeNode* lca(TreeNode* a, TreeNode* b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i))
                a = up[a][i];
        }

        if (a == b) return a;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }

        return up[a][0];
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth[root] = 0;
        up[root] = vector<TreeNode*>(LOG, nullptr);
        dfs(root, nullptr);

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> last;

        while (!q.empty()) {
            int sz = q.size();
            last.clear();
            while (sz--) {
                TreeNode* node = q.front(); q.pop();
                last.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        TreeNode* curr = last[0];
        for (int i = 1; i < last.size(); i++) {
            curr = lca(curr, last[i]);
        }

        return curr;
    }
};
