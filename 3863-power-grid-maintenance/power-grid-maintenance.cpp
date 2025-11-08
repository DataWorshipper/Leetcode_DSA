class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i = 1; i <= n; i++) parent[i] = i;
        }
        int find(int x){
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int a, int b){
            a = find(a);
            b = find(b);
            if(a == b) return;
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    };

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        for(auto &e : connections) dsu.unite(e[0], e[1]);

        vector<multiset<int>> comp(c+1);
        vector<bool> online(c+1, true);

        for(int i = 1; i <= c; i++){
            int r = dsu.find(i);
            comp[r].insert(i);
        }

        vector<int> ans;

        for(auto &q : queries){
            int t = q[0], x = q[1];
            int r = dsu.find(x);
            if(t == 1){
                if(online[x]) ans.push_back(x);
                else {
                    if(comp[r].empty()) ans.push_back(-1);
                    else ans.push_back(*comp[r].begin());
                }
            } else {
                if(online[x]){
                    comp[r].erase(comp[r].find(x));
                    online[x] = false;
                }
            }
        }

        return ans;
    }
};
