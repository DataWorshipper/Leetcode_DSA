class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

       
        vector<int> degree(n + 1, 0);

      
        vector<unordered_map<int,int>> cnt(n + 1);

      
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            degree[u]++;
            degree[v]++;
            int a = min(u, v);
            int b = max(u, v);
            cnt[a][b]++;
        }

       
        vector<int> deg;
        for (int i = 1; i <= n; i++) {
            deg.push_back(degree[i]);
        }
        sort(deg.begin(), deg.end());

        vector<int> ans;

       
        for (int q : queries) {

            long long tot = 0;

            
            for (int i = 0; i < n; i++) {
                int need = q - deg[i];
                auto it = upper_bound(deg.begin(), deg.end(), need);
                tot += (deg.end() - it);
            }

            
            for (int i = 0; i < n; i++) {
                if (2 * deg[i] > q) {
                    tot--;
                }
            }

           
            long long cur = tot / 2;

          
            for (int a = 1; a <= n; a++) {
                for (auto &it : cnt[a]) {
                    int b = it.first;
                    int c = it.second;
                    int s = degree[a] + degree[b];
                    if (s > q && s - c <= q) {
                        cur--;
                    }
                }
            }

            ans.push_back((int)cur);
        }

        return ans;
    }
};
