class TreeAncestor {
public:

int N=1e5;
 int LOG=20;
vector<vector<int>> up;

void dfs(int node,int p, vector<vector<int>>&adj)
{
    up[node][0]=p;
    for(int i=1;i<LOG;i++)
    {   
        if(up[node][i-1]!=-1)
        up[node][i]=up[up[node][i-1]][i-1];
        else
        up[node][i]=-1;
    }

    for(auto it:adj[node])
    {
        if(it!=p)
        {
            dfs(it,node,adj);
        }
    }
}
    TreeAncestor(int n, vector<int>& parent) {
         up.assign(n, vector<int>(LOG, -1));
        vector<vector<int>>adj(n);
        for(int i=0;i<parent.size();i++)
        {   if(parent[i]!=-1)
            adj[parent[i]].push_back(i);
        }

        dfs(0,-1,adj);
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i=0;i<LOG;i++)
        {
            int bit=(k>>i)&1;
            if(bit==1)
            node=up[node][i];
            if(node==-1)
            return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */