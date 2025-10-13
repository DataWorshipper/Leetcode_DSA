class Solution {
public:
    int dist(long long a, long long b) {
        int d = 0;
        while (a != b) {
            if (a > b) a /= 2;
            else b /= 2;
            d++;
        }
        return d;
    }

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto &q : queries) {
            long long a = q[0], b = q[1];
            ans.push_back(dist(a, b) + 1);
        }

        return ans;
    }
};
