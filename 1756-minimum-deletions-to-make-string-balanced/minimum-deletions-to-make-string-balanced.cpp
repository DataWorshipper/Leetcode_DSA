class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> sa(n), pb(n);

      
        sa[n-1] = (s[n-1]=='a');
        for(int i=n-2;i>=0;i--)
            sa[i] = sa[i+1] + (s[i]=='a');

    
        pb[0] = (s[0]=='b');
        for(int i=1;i<n;i++)
            pb[i] = pb[i-1] + (s[i]=='b');

        int ans = min(sa[0], pb[n-1]);  

        for(int k=0;k<n-1;k++) {
            int cost = pb[k] + sa[k+1];
            ans = min(ans, cost);
        }

        return ans;
    }
};
