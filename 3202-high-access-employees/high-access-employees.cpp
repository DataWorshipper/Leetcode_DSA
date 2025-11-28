class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;

        for (auto &rec : access_times) {
            string name = rec[0];
            string t = rec[1];
            int hh = stoi(t.substr(0,2));
            int mm = stoi(t.substr(2,2));
            mp[name].push_back(hh * 60 + mm);
        }

        vector<string> ans;

        for (auto &p : mp) {
            auto &times = p.second;
            if (times.size() < 3) continue;
            sort(times.begin(), times.end());
            bool high = false;
            for (int i = 0; i + 2 < times.size(); ++i) {
                auto it = lower_bound(times.begin() + i, times.end(), times[i] + 60);
                int count = it - (times.begin() + i);
                if (count >= 3) { high = true; break; }
            }
            if (high) ans.push_back(p.first);
        }

        return ans;
    }
};
