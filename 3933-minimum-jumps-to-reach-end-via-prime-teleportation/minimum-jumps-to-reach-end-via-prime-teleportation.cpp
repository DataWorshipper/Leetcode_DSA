class Solution {
public:
    vector<int> spf;

    void build_spf(int N) {
        spf.resize(N + 1);

        for (int i = 0; i <= N; i++)
            spf[i] = i;

        for (int i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());
        build_spf(mx);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];
                mp[p].push_back(i);

                while (x % p == 0)
                    x /= p;
            }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<bool> vis(n, false);
        vis[0] = true;

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1)
                return steps;

            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = true;
                q.push({idx - 1, steps + 1});
            }

            if (idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = true;
                q.push({idx + 1, steps + 1});
            }

            if (spf[nums[idx]] == nums[idx]) {
                int p = nums[idx];

                if (!usedPrime.count(p)) {
                    usedPrime.insert(p);

                    for (int next : mp[p]) {
                        if (!vis[next]) {
                            vis[next] = true;
                            q.push({next, steps + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};