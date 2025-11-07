typedef long long ll;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = empty, 1 = wall, 2 = guard, 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto &w : walls)  grid[w[0]][w[1]] = 1;
        for (auto &g : guards) grid[g[0]][g[1]] = 2;

        auto mark = [&](int x, int y, int dx, int dy) {
            int i = x + dx, j = y + dy;
            while (i >= 0 && i < m && j >= 0 && j < n) {
                if (grid[i][j] == 1 || grid[i][j] == 2) break;   // wall or guard blocks
                if (grid[i][j] == 0) grid[i][j] = 3;             // mark as guarded
                i += dx; j += dy;                                // continue straight
            }
        };

        for (auto &g : guards) {
            int x = g[0], y = g[1];
            mark(x, y,  1,  0); // down
            mark(x, y, -1,  0); // up
            mark(x, y,  0,  1); // right
            mark(x, y,  0, -1); // left
        }

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0) ++ans;   // unoccupied & not guarded

        return ans;
    }
};
