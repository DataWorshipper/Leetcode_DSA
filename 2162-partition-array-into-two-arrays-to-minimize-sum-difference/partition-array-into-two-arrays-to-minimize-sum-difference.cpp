#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    void generateSubsetSums(const vector<ll>& nums, int index, ll sum, int count, vector<pair<ll,int>>& res) {
        if(index == nums.size()) {
            res.push_back({sum, count});
            return;
        }
        generateSubsetSums(nums, index + 1, sum, count, res);
        generateSubsetSums(nums, index + 1, sum + nums[index], count + 1, res);
    }

    int minimumDifference(vector<int>& nums) {
        int n2 = nums.size();
        int n = n2 / 2;
        vector<ll> left(nums.begin(), nums.begin() + n);
        vector<ll> right(nums.begin() + n, nums.end());
        vector<pair<ll,int>> s1, s2;
        generateSubsetSums(left, 0, 0, 0, s1);
        generateSubsetSums(right, 0, 0, 0, s2);

        map<int, vector<ll>> countToSums;
        for(auto [sum, cnt] : s2)
            countToSums[cnt].push_back(sum);
        for(auto& [cnt, vec] : countToSums)
            sort(vec.begin(), vec.end());

        ll totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        ll ans = LLONG_MAX;

        for(auto [sum1, cnt1] : s1) {
            int cnt2 = n - cnt1;
            if(countToSums.find(cnt2) == countToSums.end()) continue;
            auto& vec = countToSums[cnt2];
            ll target = totalSum / 2 - sum1;
            auto it = lower_bound(vec.begin(), vec.end(), target);
            if(it != vec.end())
                ans = min(ans, abs(totalSum - 2*(sum1 + *it)));
            if(it != vec.begin()) {
                it--;
                ans = min(ans, abs(totalSum - 2*(sum1 + *it)));
            }
        }

        return ans;
    }
};
