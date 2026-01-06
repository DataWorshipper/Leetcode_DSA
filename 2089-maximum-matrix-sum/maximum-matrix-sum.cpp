class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sumAbs = 0;
        int neg = 0, zero = 0;
        int mn = INT_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                if (x < 0) neg++;
                if (x == 0) zero++;
                sumAbs += abs(x);
                mn = min(mn, abs(x));
            }
        }

        if (neg % 2 == 0 || zero > 0)
            return sumAbs;
        else
            return sumAbs - 2LL * mn;
    }
};
