

typedef long long ll;
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) return nums1 == nums2 ? 0 : -1;

        ll p_s = 0, n_s = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int d = nums2[i] - nums1[i];
            if (d % k != 0) return -1;

            if (d > 0) p_s += d;
            else n_s -= d; // careful: d is negative, so minus
        }

        if (p_s != n_s) return -1;

        return p_s / k;
    }
};
