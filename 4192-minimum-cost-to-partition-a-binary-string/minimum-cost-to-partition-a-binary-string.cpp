typedef long long ll;
class Solution {
public:
    ll f(int l,int r,vector<int>&prefix,int encCost, int flatCost)
    {
        ll len=r-l+1;

       
        if(len%2==1)
        {
             ll zeroes=prefix[r]-((l>0)?prefix[l-1]:0);
            if(zeroes==0)
            return flatCost;
            else
            return encCost*len*zeroes;
        }

        else
        {
            ll zeroes=prefix[r]-((l>0)?prefix[l-1]:0);
            ll dir_cost=0;
            if(zeroes==0) 
            {
                dir_cost=flatCost;
                return dir_cost;
            }

            else
            {
                dir_cost=len*zeroes*encCost;
                ll mid=l+(r-l)/2;
                ll other=f(l,mid,prefix,encCost,flatCost)+f(mid+1,r,prefix,encCost,flatCost);
                return min((ll)dir_cost,(ll)other);
            }
        }
    }
    long long minCost(string s, int encCost, int flatCost) {
        
        vector<int>prefix(s.size(),0);
        prefix[0]=(s[0]=='1')?1:0;
        for(int i=1;i<s.size();i++)

        {
            if(s[i]=='1')
            prefix[i]=prefix[i-1]+1;
            else
              prefix[i]=prefix[i-1];
        }   


        return f(0,s.size()-1,prefix,encCost,flatCost);




    }
};