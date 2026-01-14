class Solution {
public:
    vector<vector<int>> g;
    vector<int> sub;
    int ans = 0;

    void dfs1(int u, int p){
        sub[u] = 1;
        for(int v : g[u]){
            if(v == p) continue;
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }

    void dfs2(int u, int p){
        int val = -1;
        bool ok = true;
        for(int v : g[u]){
            if(v == p) continue;
            if(val == -1) val = sub[v];
            else if(sub[v] != val) ok = false;
            dfs2(v, u);
        }
        if(ok) ans++;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        g.assign(n, {});
        for(auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        sub.assign(n, 0);
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
