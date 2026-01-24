class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int mask=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            int d=s[i]-'0';
            mask=mask^(1<<d);
            if(mpp.count(mask))
            {
                ans=max(ans,i-mpp[mask]);
            }
               
                for(int j=0;j<=9;j++)
                { int mask2=0;
                    mask2=mask2^(1<<j);
                    int prev_mask=mask^mask2;
                    if(mpp.count(prev_mask))
                    {
                        ans=max(ans,i-mpp[prev_mask]);
                    }
                }
                if(!mpp.count(mask))
                {
                    mpp[mask]=i;
                }
        }
        return ans;
    }
};