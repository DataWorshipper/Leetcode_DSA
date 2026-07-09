typedef long long ll;
class Solution {
public:
    string longestPalindrome(string s) {
        ll n=s.size();
        string ans="";
        for(ll i=0;i<n;i++)
        {
            ll l=i;
            ll r=i;
            while(l>=0 &&r<n &&s[l]==s[r])
            {
                if(r-l+1>ans.size())
                {
                    ans=s.substr(l,r-l+1);

                }
                l--;
                r++;
            }
             l=i;
             r=i+1;
              while(l>=0 &&r<n &&s[l]==s[r])
            {
                if(r-l+1>ans.size())
                {
                    ans=s.substr(l,r-l+1);

                }
                l--;
                r++;
            }


        }
        return ans;
        
    }
};