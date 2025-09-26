class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> freq(n+1, vector<int>(26,0));
        
        for(int i = 0; i < n; i++){
            for(int c = 0; c < 26; c++) freq[i+1][c] = freq[i][c];
            freq[i+1][s[i]-'a']++;
        }
        
        vector<bool> ans;
        for(auto &q : queries){
            int l = q[0], r = q[1], k = q[2];
            int odd_count = 0;
            for(int c = 0; c < 26; c++){
                int cnt = freq[r+1][c] - freq[l][c];
                if(cnt % 2) odd_count++;
            }
            ans.push_back(odd_count/2 <= k);
        }
        return ans;
    }
};
