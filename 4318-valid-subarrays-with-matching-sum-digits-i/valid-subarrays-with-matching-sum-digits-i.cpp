class Solution {
public:
 bool check(long long sum, int x) {
        if (sum % 10 != x) return false;

        while (sum >= 10)
            sum /= 10;

        return sum == x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            long long sum = 0;

            for (int r = l; r < n; r++) {
                sum += nums[r];

                if (check(sum, x))
                    ans++;
            }
        }

        return ans;
    }
};