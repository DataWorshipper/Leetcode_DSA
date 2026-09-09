class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> idx(1 << n, -1);

        for (int i = 0; i < m; i++) {
            int mask = 0;

            for (int j = 0; j < n; j++)
                mask |= grid[i][j] << j;

            if (idx[mask] != -1)
                continue;

            idx[mask] = i;
        }

        if (idx[0] != -1)
            return {idx[0]};

        for (int a = 0; a < (1 << n); a++) {
            if (idx[a] == -1) continue;

            for (int b = a + 1; b < (1 << n); b++) {
                if (idx[b] == -1) continue;

                if ((a & b) == 0)
                    return {min(idx[a], idx[b]), max(idx[a], idx[b])};
            }
        }

        return {};
    }
};