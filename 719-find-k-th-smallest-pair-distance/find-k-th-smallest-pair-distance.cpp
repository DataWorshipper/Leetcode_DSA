class Solution {
public:
long long countPairs(int d,vector<int>& nums) {

    long long cnt = 0;
    long long n=nums.size();
    for (int i = 0; i < n; i++) {
        int L = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] - d) - nums.begin();
        int R = upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + d) - nums.begin();
        if (R > L) cnt += (R - L);
    }
    return cnt;
}


        int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int low = 0, high = nums[n-1] - nums[0], ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (countPairs(mid,nums) >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

    
};