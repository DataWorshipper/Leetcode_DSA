class Solution {
public:

int dp[13][1<<12];

int f(int index, int mask, vector<int>& jobs,
      int k, vector<int>& sum)
{   
    int n = jobs.size();

    if(index == k)
    {
        if(mask == ((1<<n)-1))
            return 0;
        else
            return INT_MAX/2;
    }

    if(dp[index][mask] != -1)
        return dp[index][mask];

    int ans = INT_MAX;

    for(int sub=0; sub<(1<<n); sub++)
    {
        if(mask & sub)
            continue;

        int s = sum[sub]; 

        ans = min(ans,
                  max(s,
                      f(index+1, mask|sub, jobs, k, sum)));
    }

    return dp[index][mask] = ans;
}

int minimumTimeRequired(vector<int>& jobs, int k) {

    int n = jobs.size();

  
    vector<int> sum(1<<n, 0);

    for(int mask=0; mask<(1<<n); mask++)
        for(int i=0;i<n;i++)
            if(mask & (1<<i))
                sum[mask] += jobs[i];
   

    memset(dp, -1, sizeof(dp));

    return f(0, 0, jobs, k, sum);
}
};
