class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        vector<vector<int>> mpp(26);
for(int i = 0; i < n; i++){
    mpp[s[i]-'A'].push_back(i);   
}

for(int c = 0; c < 26; c++){
    if(mpp[c].empty()) continue;
    mpp[c].insert(mpp[c].begin(), -1);
    mpp[c].push_back(n);
}

long long ans = 0;

for(int c = 0; c < 26; c++){
    auto &a = mpp[c];
    int m = a.size();
  
for(int i = 1; i <= m-2; i++){
    long long left = a[i] - a[i-1];
    long long right = a[i+1] - a[i];
    ans += left * right;
}
}



return ans;


    }
};