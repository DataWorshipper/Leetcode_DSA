class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        vector<long long>pref(n,0);
        pref[0]=s[0]-'0';
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+(s[i]-'0');
        }
long long  ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                ans+=(long long)((n-i)-pref[i]);
            }

        }
        return ans;
    }
};