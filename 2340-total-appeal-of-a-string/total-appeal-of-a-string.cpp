class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<vector<int>> pos(26);
        
      
        for(int i = 0; i < n; i++){
            pos[s[i] - 'a'].push_back(i);
        }

        long long totalSub = 1LL * n * (n + 1) / 2;
        long long ans = 0;

        for(int c = 0; c < 26; c++){
            if(pos[c].empty()) continue;

            long long avoid = 0;

        
            int first = pos[c][0];
            avoid += 1LL * first * (first + 1) / 2;

            for(int i = 1; i < pos[c].size(); i++){
                int gap = pos[c][i] - pos[c][i-1] - 1;
                avoid += 1LL * gap * (gap + 1) / 2;
            }

            int last = pos[c].back();
            int tail = n - 1 - last;
            avoid += 1LL * tail * (tail + 1) / 2;

            long long contain = totalSub - avoid;
            ans += contain;
        }

        return ans;
    }
};
