class Solution {
public:
    int minLengthAfterRemovals(string s) {
        
        vector<int>pref(s.size(),0);
        if(s[0]=='a')
        pref[0]=1;
        else
        pref[0]=-1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='a')
            pref[i]=pref[i-1]+1;
            else
            pref[i]=pref[i-1]-1;
        }

        return abs(pref[pref.size()-1]);
    }
};