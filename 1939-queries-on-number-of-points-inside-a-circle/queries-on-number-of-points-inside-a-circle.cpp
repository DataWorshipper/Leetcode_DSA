class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto &q : queries) {
            int x = q[0], y = q[1], r = q[2], cnt = 0;
            for (auto &p : points) {
                int dx = p[0] - x, dy = p[1] - y;
                if ((long long)dx * dx + (long long)dy * dy <= (long long)r * r) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};