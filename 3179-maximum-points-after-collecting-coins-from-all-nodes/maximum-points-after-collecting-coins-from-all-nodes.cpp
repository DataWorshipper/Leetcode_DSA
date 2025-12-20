class Solution {
    long long dp[100001][16];

public:
    long long f(int node, int parent, int halves,
                vector<vector<int>>&adj,
                vector<int>& coins,
                int k)
    {
        if (dp[node][halves] != -1)
            return dp[node][halves];

        long long ans = LLONG_MIN;
         long long effective = coins[node] / (1LL << halves);
         long long firstchoiceans=effective-k;
         long long secondchoiceans=effective/2;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
           
               

                

               firstchoiceans +=
                     f(it, node, halves, adj, coins, k);

            
            if(halves<14){
            secondchoiceans +=
                   f(it, node, halves+1, adj, coins, k);}

            
            }

                return dp[node][halves]= max(firstchoiceans, secondchoiceans);
            

        }


       
    

    long long maximumPoints(vector<vector<int>>& edges,
                            vector<int>& coins,
                            int k)
    {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        memset(dp, -1, sizeof(dp));

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return f(0, -1, 0, adj, coins, k);
    }
};
