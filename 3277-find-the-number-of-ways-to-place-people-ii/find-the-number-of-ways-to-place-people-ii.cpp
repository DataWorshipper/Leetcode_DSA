class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> xs, ys;

        for (auto &p : points) {
            xs.push_back(p[0]);
            ys.push_back(p[1]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        unordered_map<int, int> mp_x, mp_y;

        for (int i = 0; i < xs.size(); i++)
            mp_x[xs[i]] = i;

        for (int i = 0; i < ys.size(); i++)
            mp_y[ys[i]] = i;

        int nx = xs.size();
        int ny = ys.size();

        vector<vector<int>> grid(nx, vector<int>(ny, 0));
        vector<vector<int>> pref(nx + 1, vector<int>(ny + 1, 0));

        for (auto &p : points) {
            int x = mp_x[p[0]];
            int y = mp_y[p[1]];

            grid[x][y] = 1;
        }

        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                pref[i + 1][j + 1] =
                    grid[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        auto check = [&](int x1, int y1, int x2, int y2) {
            int xmin = min(x1, x2);
            int xmax = max(x1, x2);
            int ymin = min(y1, y2);
            int ymax = max(y1, y2);

            int cnt =
                pref[xmax + 1][ymax + 1]
                - pref[xmin][ymax + 1]
                - pref[xmax + 1][ymin]
                + pref[xmin][ymin];

            return cnt == 2;
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = mp_x[points[i][0]];
            int y1 = mp_y[points[i][1]];

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                int x2 = mp_x[points[j][0]];
                int y2 = mp_y[points[j][1]];

                if (x1 <= x2 && y1 >= y2) {
                    if (check(x1, y1, x2, y2))
                        ans++;
                }
            }
        }

        return ans;
    }
};