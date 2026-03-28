typedef long long ll;

class Solution {
public:
    vector<int> primes;
    vector<vector<int>> adj;
    unordered_map<int,int> freq;
    ll ans = 0;

    void buildSieve(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
    }

    int kernel(int x) {
        int res = 1;

        for (int p : primes) {
            if (p * p > x) break;

            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            if (cnt % 2 == 1) {
                res *= p;
            }
        }

        if (x > 1) res *= x;

        return res;
    }

    void dfs(int u, int parent, vector<int>& ker) {
        ans += freq[ker[u]];
        freq[ker[u]]++;

        for (auto v : adj[u]) {
            if (v == parent) continue;
            dfs(v, u, ker);
        }

        freq[ker[u]]--;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int mx = *max_element(nums.begin(), nums.end());
        buildSieve(mx);

        vector<int> ker(n);
        for (int i = 0; i < n; i++) {
            ker[i] = kernel(nums[i]);
        }

        dfs(0, -1, ker);

        return ans;
    }
};