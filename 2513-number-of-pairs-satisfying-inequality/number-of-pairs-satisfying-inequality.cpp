class Solution {
public:
    long long ans = 0;

    vector<int> f(vector<int>& arr, int l, int r, int diff) {
        if (l == r) {
            return {arr[l]};
        }

        int mid = (l + r) / 2;

        vector<int> left = f(arr, l, mid, diff);
        vector<int> right = f(arr, mid + 1, r, diff);

        
        int j = 0;
        for (int i = 0; i < left.size(); i++) {
            while (j < right.size() && right[j] < left[i] - diff) {
                j++;
            }
            ans += (right.size() - j);
        }

     
        int i = 0;
        j = 0;
        vector<int> res;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                res.push_back(left[i++]);
            } else {
                res.push_back(right[j++]);
            }
        }

        while (i < left.size()) res.push_back(left[i++]);
        while (j < right.size()) res.push_back(right[j++]);

        return res;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = nums1[i] - nums2[i];
        }

        f(arr, 0, n - 1, diff);

        return ans;
    }
};