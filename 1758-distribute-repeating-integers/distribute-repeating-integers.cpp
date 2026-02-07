class Solution {
public:

bool dp[51][1<<10];
bool vis[51][1<<10];

bool f(int index,int mask, vector<int>&cnt,
       vector<int>& quantity, unordered_map<int,int>&sum)
{   
    int n = quantity.size();
    int m = cnt.size();

    if(mask == ((1<<n)-1))
        return true;

    if(index == m)
        return false;

    if(vis[index][mask])
        return dp[index][mask];

    vis[index][mask] = true;

    for(int sub=0; sub<(1<<n); sub++)
    {
        if((mask & sub)!=0) 
            continue;

      
        if(sum[sub] <= cnt[index])
        {
          
            if(f(index+1, mask|sub, cnt, quantity, sum))
                return dp[index][mask] = true;
        }
    }

  
    return dp[index][mask] = false;
}

bool canDistribute(vector<int>& nums, vector<int>& quantity) {

    unordered_map<int,int> mpp;
    for(auto it:nums)
        mpp[it]++;

    vector<int> cnt;
    for(auto it:mpp)
        cnt.push_back(it.second);

    unordered_map<int,int> sum;
    int m = quantity.size();

    for(int sub=0; sub<(1<<m); sub++)
    {
        int s = 0;
        for(int i=0;i<m;i++)
            if(sub & (1<<i))
                s += quantity[i];

        sum[sub] = s;
    }

    memset(vis,false,sizeof(vis));

    return f(0,0,cnt,quantity,sum);  
}
};
