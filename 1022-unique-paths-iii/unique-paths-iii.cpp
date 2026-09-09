class Solution {
public:
    int m, n;

    bool check(vector<vector<int>>& grid, vector<vector<int>>& vis) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1 && vis[i][j] == 0)
                    return false;
            }
        }
        return true;
    }

    int dfs(int r, int c, vector<vector<int>>& grid,
            vector<vector<int>>& vis) {

        vis[r][c] = 1;

        if (grid[r][c] == 2) {
            int res = check(grid, vis);
            vis[r][c] = 0;
            return res;
        }

        int ans = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (grid[nr][nc] == -1 || vis[nr][nc])
                continue;

            ans += dfs(nr, nc, grid, vis);
        }

        vis[r][c] = 0;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int sr, sc;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
            }
        }

        return dfs(sr, sc, grid, vis);
    }
};