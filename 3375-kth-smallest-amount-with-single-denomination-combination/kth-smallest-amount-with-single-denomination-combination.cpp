class Solution {
public:
vector<vector<int>> subs;

void gen(int i, vector<int>& cur, vector<int>& coins) {
    if (i == coins.size()) {
        if (!cur.empty()) subs.push_back(cur);
        return;
    }

    gen(i + 1, cur, coins);


    cur.push_back(coins[i]);
    gen(i + 1, cur, coins);
    cur.pop_back();
}
bool check(long long x, long long k) {
    long long cnt = 0;

    for (auto &v : subs) {
     
        long long lcm = v[0];
        for (int i = 1; i < v.size(); i++) {
            long long g = std::gcd(lcm, (long long)v[i]);
            lcm = (lcm / g) * v[i];
            if (lcm > x) break; 
        }

        if (lcm > x) continue;

        long long add = x / lcm;
        if (v.size() % 2 == 1) cnt += add; 
        else cnt -= add;                 
    }

    return cnt >= k;
}


   long long findKthSmallest(vector<int>& coins, int k) {
    vector<int> cur;
    subs.clear();
    gen(0, cur, coins);

    long long low = *min_element(coins.begin(), coins.end());
    long long high = (long long)(*max_element(coins.begin(), coins.end())) * k;
    long long ans = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

};