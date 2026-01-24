class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, long long> mpp;
        mpp[0] = 1;

        int mask = 0;
        long long ans = 0;

        for (char c : word) {
            int d = c - 'a';
            mask ^= (1 << d);

            if (mpp.count(mask))
                ans += mpp[mask];

            for (int j = 0; j < 10; j++) {
                int prev_mask = mask ^ (1 << j);
                if (mpp.count(prev_mask))
                    ans += mpp[prev_mask];
            }

            mpp[mask]++;
        }

        return ans;
    }
};
