class Solution {
public:
    int numSub(string s) {
        

        int l=0;
        int r=0;
        long long c=0;
        const long long MOD=1E9+7;
        int len=0;
        while(r<s.size())
        {   
                if(s[r]=='1')
                len++;
           else  if(s[r]=='0')
            {
                

                c+=(long long)(len)*(len+1)/2;
                
                len=0;
                l=r+1;
            }
            r++;
        }
         c+=(long long)(len)*(len+1)/2;

        return (c%MOD);
    }
};