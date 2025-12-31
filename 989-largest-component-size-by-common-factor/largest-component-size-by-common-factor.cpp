class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int largestComponentSize(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        parent.resize(mx + 1);
        sz.assign(mx + 1, 1);
        for (int i = 1; i <= mx; i++) parent[i] = i;

        for (int x : nums) {
            int temp = x;
            for (int p = 2; p * p <= temp; p++) {
                if (temp % p == 0) {
                    unite(x, p);
                    while (temp % p == 0) temp /= p;
                }
            }
            
            if (temp > 1) {
                unite(x, temp);
            }
        }

        unordered_map<int, int> cnt;
        int ans = 0;

        for (int x : nums) {
            int root = find(x);
            cnt[root]++;
            ans = max(ans, cnt[root]);
        }

        return ans;
    }
};
