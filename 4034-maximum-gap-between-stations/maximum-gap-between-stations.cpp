class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        vector<int> earliest(n, -1);
        vector<int> latest(n, -1);

        int i = 0;
        int j = 0;

     
        while (i < m && j < n) {
            while (i < m && station[i] != skill[j]) {
                i++;
            }

            if (i < m && station[i] == skill[j]) {
                earliest[j] = i;
                j++;
                i++;
            }
        }

        i = m - 1;
        j = n - 1;

        while (i >= 0 && j >= 0) {
            while (i >= 0 && station[i] != skill[j]) {
                i--;
            }

            if (i >= 0 && station[i] == skill[j]) {
                latest[j] = i;
                j--;
                i--;
            }
        }

        int ans = INT_MIN;

        for (int i = 1; i < n; i++) {
            ans = max(ans, latest[i] - earliest[i - 1]);
        }

        return ans == INT_MIN ? 0 : ans;
    }
};