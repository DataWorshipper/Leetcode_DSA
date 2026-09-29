class Solution {
public:
     static bool cmp( const vector<int>&a, const vector<int>&b)
    {
        int q1=a[0];
        int w1=a[1];
        int q2=b[0];
        int w2=b[1];
        return w1*q2<w2*q1;
    }   
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
            int n=quality.size();
            vector<int>pref(n,0);
            pref[0]=quality[0];
            for(int i=1;i<n;i++)
            {
                pref[i]=pref[i-1]+quality[i];
            }
            vector<vector<int>>arr;
            for(int i=0;i<n;i++)
            {
                arr.push_back({quality[i],wage[i]});
            }

            priority_queue<int>pq;
            sort(arr.begin(),arr.end(),cmp);
            int s=0;
            double cost=1e18;
            for(int i=0;i<n;i++)
            {
                int q=arr[i][0];
                int w=arr[i][1];
                if(pq.size()==k-1)
                {
                    cost=min(cost,(double)w/q*(s+q));
                }
                pq.push(q);
                s+=q;
                while(pq.size()>k-1)
                {
                    s-=pq.top();
                    pq.pop();
                }

            }
            return cost;


    }
};