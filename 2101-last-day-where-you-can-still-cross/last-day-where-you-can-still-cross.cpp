class Solution {
public:
bool check(int day, int row, int col, vector<vector<int>>& cells) {
    vector<vector<int>> grid(row, vector<int>(col, 0));

 
    for (int i = 0; i < day; i++) {
        grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
    }

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(row, vector<bool>(col, false));

    for (int j = 0; j < col; j++) {
        if (grid[0][j] == 0) {
            q.push({0, j});
            vis[0][j] = true;
        }
    }

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == row - 1) return true;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                !vis[nr][nc] && grid[nr][nc] == 0) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return false;
}

 
        
        int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    int low = 1, high = row * col;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid, row, col, cells)) {
            ans = mid;
            low = mid + 1; 
        } else {
            high=mid-1;
        }
    }

    return ans;
}

    
};