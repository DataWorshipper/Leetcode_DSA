class DSU
{   public:
    vector<int>parent,rank,compand;

    DSU(int n)
    {
        parent.resize(n,0);
        rank.resize(n,0);
        compand.resize(n,(1<<30)-1);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int find_parent(int u)
    {
        if(u==parent[u])
        return u;
        return parent[u]=find_parent(parent[u]);

    }
    void unite(int u,int v,int w)
    {
        int pu=find_parent(u);
        int pv=find_parent(v);
        int ru=rank[pu];
        int rv=rank[pv];
        if(pu==pv)
        {
          compand[pu]&=w;
            return;
        }
        if(ru>rv)
        {
        parent[pv]=pu;
        compand[pu]&=(compand[pv]&w);
        }
        else if(rv>ru)
        {
        parent[pu]=pv;
        compand[pv]&=(compand[pu]&w);
        }
        else
        {
            parent[pu]=pv;
            rank[pv]++;
            compand[pv]&=(compand[pu]&w);
        }

    }
};
class Solution {
public:

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            
                dsu.unite(u,v,w);
            
        }
        vector<int>ans;
        for(auto it:queries)
        {
            int u=it[0];
            int v=it[1];
            if(dsu.find_parent(u)!=dsu.find_parent(v))
            {
                ans.push_back(-1);
            }
            else
            ans.push_back(dsu.compand[dsu.find_parent(u)]);
        }
        return ans;
    }

};