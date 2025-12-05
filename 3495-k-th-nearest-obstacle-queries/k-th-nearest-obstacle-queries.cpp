class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n=queries.size();
        vector<int>result(n,0);
        int z=min(k-2,n-1);
        for(int i=0;i<=z;i++)
        {
            result[i]=-1;
        }   

        priority_queue<int>pq;
        for(int i=0;i<=z;i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];
            int dis=abs(x)+abs(y);
            pq.push(dis);
        }

        for(int i=k-1;i<n;i++)
        {
             int x=queries[i][0];
            int y=queries[i][1];
             int dis=abs(x)+abs(y);
               pq.push(dis);
               while(pq.size()>k)
               {
                pq.pop();
               }

               result[i]=pq.top();
        }


return result;

    }
};