class Solution {
public:
    int m, n;
    vector<vector<int>> vis;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        vis[x][y] = 1;
        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (grid[nx][ny] != grid[x][y]) continue;
            if (nx == px && ny == py) continue;
            if (vis[nx][ny]) return true;
            if (dfs(grid, nx, ny, x, y)) return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!vis[i][j] && dfs(grid, i, j, -1, -1))
                    return true;

        return false;
    }
};
