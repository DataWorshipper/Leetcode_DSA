class Solution {
public:
    vector<vector<int>> g1, g2;
    vector<int> cnt1, cnt2;
    int K;
    int curCnt;

    void dfs_count(int u, int p, int depth, int limit, vector<vector<int>>& g){
        if(depth > limit) return;
        curCnt++;
        for(int v : g[u]){
            if(v == p) continue;
            dfs_count(v, u, depth+1, limit, g);
        }
    }

    vector<int> solveTree(int n, vector<vector<int>>& edges, int limit){
        vector<vector<int>> g(n);
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> cnt(n);
        for(int i=0;i<n;i++){
            curCnt = 0;
            dfs_count(i, -1, 0, limit, g);
            cnt[i] = curCnt;
        }
        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2,
                               int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        K = k;

     
        cnt1 = solveTree(n, edges1, k);

       
        cnt2 = solveTree(m, edges2, k-1);

        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            int best = 0;
            for(int j=0;j<m;j++){
                best = max(best, cnt1[i] + cnt2[j]);
            }
            ans[i] = best;
        }
        return ans;
    }
};
