class Solution {
    map<pair<int,int>,int> mpp;
    vector<int> depth;
    vector<int> res;

    void depth_calc(int node, int parent, vector<vector<int>>& adj, int d) {
        depth[node] = d;
        for (int it : adj[node]) {
            if (it == parent) continue;
            depth_calc(it, node, adj, d + 1);
        }
    }

    void res_calc(int node, int parent,
                  vector<vector<int>>& adj,
                  vector<vector<int>>& primes,
                  vector<int>& nums) {
        if (parent != -1) {
            int bestDepth = -1, bestNode = -1;
            for (int val : primes[node]) {
                auto it = mpp.lower_bound({val, -1});
                while (it != mpp.end() && it->first.first == val) {
                    int cand = it->first.second;
                    if (depth[cand] > bestDepth) {
                        bestDepth = depth[cand];
                        bestNode = cand;
                    }
                    ++it;
                }
            }
            res[node] = bestNode;
        }

        mpp[{nums[node], node}]++;

        for (int it : adj[node]) {
            if (it == parent) continue;
            res_calc(it, node, adj, primes, nums);
        }

        auto key = make_pair(nums[node], node);
        if (--mpp[key] == 0) mpp.erase(key);
    }

public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> primes(n), adj(n);

        for (int i = 0; i < n; i++)
            for (int j = 1; j <= 50; j++)
                if (gcd(nums[i], j) == 1)
                    primes[i].push_back(j);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        depth.assign(n, 0);
        res.assign(n, -1);

        depth_calc(0, -1, adj, 0);
        res_calc(0, -1, adj, primes, nums);

        return res;
    }
};
