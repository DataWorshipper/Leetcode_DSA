typedef long long ll;
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        multiset<ll>left,right;
        ll l=0;
        ll r=0;
        ll n=nums.size();
        vector<ll>cost;
        ll s_l=0;
        ll s_r=0;
        while(r<n)
        {
            if(left.empty() || nums[r]<=*left.rbegin())
            {
                left.insert(nums[r]);
                s_l+=nums[r];

            }
           else  
            {
                right.insert(nums[r]);
                s_r+=nums[r];
            }
            if(left.size()>right.size()+1)
            {
                ll val=*left.rbegin();
                left.erase(prev(left.end()));
                right.insert(val);
                s_l-=val;
                s_r+=val;
            }
             if(right.size()>left.size())
            {
                ll val=*right.begin();
                right.erase(right.begin());
                left.insert(val);
                s_r-=val;
                s_l+=val;
            }
            if(r-l+1>x)
            {
                auto it=left.find(nums[l]);
                if(it!=left.end())
                {
                    left.erase(it);
                    s_l-=nums[l];
                }
                else
                {
                right.erase(right.find(nums[l]));
                s_r-=nums[l];
                }


              if(left.size()>right.size()+1)
            {
                ll val=*left.rbegin();
                left.erase(prev(left.end()));
                right.insert(val);
                s_l-=val;
                s_r+=val;
            }
             if(right.size()>left.size())
            {
                ll val=*right.begin();
                right.erase(right.begin());
                left.insert(val);
                s_r-=val;
                s_l+=val;
            }
            l++;

            }
            if(r-l+1==x)
            {
                ll med=0;
                if(left.size()==right.size()||left.size()>right.size())
                {
                    med=*left.rbegin();
                }
                else
                med=*right.begin();

                ll s1=med*left.size()-s_l;
                ll s2=s_r-med*right.size();
                cost.push_back(s1+s2);
            }
            r++;


        }
        const ll POS=(4e18);
        vector<vector<ll>>dp(n,vector<ll>(k+1,POS));
        dp[0][0]=0;
       
        for(ll i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        for(ll i=1;i<n;i++)
        {
            for(ll l=1;l<=k;l++)
            {
                dp[i][l]=dp[i-1][l];
                    if(i >= x-1)
{
    ll start = i-x+1;

    if(start == 0)
    {
        if(l == 1)
            dp[i][l] = min(dp[i][l], dp[0][0]+cost[0]);
    }
    else
    {
        if(dp[start-1][l-1] != POS)
        {
            dp[i][l] = min(dp[i][l],
                           dp[start-1][l-1] + cost[start]);
        }
    }
}

            }
        }


return dp[n-1][k];
   
    }




        
    
};