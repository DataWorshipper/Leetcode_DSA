class Solution {
    struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

    int comp_size(int x) {
        return size[find(x)];
    }
};

public:
    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int,int>id;
        unordered_map<int,int>freq;
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            int mask=0;
            for(int j=0;j<s.size();j++)
            {
                int pos=s[j]-'a';
                mask=mask^(1<<pos);
            }
            id[mask]=i;
            freq[mask]++;
        }

        DSU dsu(words.size()+1);

        for(auto it:id)
        {
            int mask=it.first;
            int mask1=mask;
            int mask2=mask;
            int mask3=mask;
            for(int i=0;i<26;i++)
            {
                if(!(mask&(1<<i)))
               { mask1=mask^(1<<i);
                if(id.find(mask1)!=id.end())
                dsu.unite(id[mask1],id[mask]);
               }

            }
             for(int i=0;i<26;i++)
            {
                if((mask&(1<<i)))
               { mask1=mask^(1<<i);
                if(id.find(mask1)!=id.end())
                dsu.unite(id[mask1],id[mask]);
               }


            }

            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(mask&(1<<i) && !(mask&(1<<j)))
                    {
                        mask3=mask^(1<<i)^(1<<j);
                       
                        if(id.find(mask3)!=id.end())
                dsu.unite(id[mask3],id[mask]);
                    }
                }
            }}


            unordered_map<int,int>comp;
            int m=INT_MIN;
            for(auto it:id)
            {
                int mask=it.first;
                int root=dsu.find(it.second);
                comp[root]+=freq[mask];
                m=max(m,comp[root]);
            }

            int group=comp.size();
            return {group,m};
            
        }
        
    
};