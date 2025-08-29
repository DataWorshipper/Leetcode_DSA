class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> f1(n), f2(n), f3(n), f4(n);

        for (int i = 0; i < n; i++) {
            f1[i] = arr1[i] + arr2[i] + i;
            f2[i] = arr1[i] - arr2[i] + i;
            f3[i] = -arr1[i] + arr2[i] + i;
            f4[i] = -arr1[i] - arr2[i] + i;
        }

        auto getMaxDiff = [&](vector<int>& f) {
            int mn = INT_MAX, mx = INT_MIN;
            for (int v : f) {
                mn = min(mn, v);
                mx = max(mx, v);
            }
            return mx - mn;
        };

        return max({getMaxDiff(f1), getMaxDiff(f2), getMaxDiff(f3), getMaxDiff(f4)});
    }
};
