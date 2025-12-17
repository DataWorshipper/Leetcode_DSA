class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<x.size();i++)
        {
            mpp[x[i]].push_back(i);
        }

priority_queue<int>pq;
vector<int>ymax;
        for(auto it:mpp)

        {
            int num=it.first;
            vector<int>v=it.second;
            for(int i=0;i<v.size();i++)
            {
                pq.push(y[v[i]]);
            }
            ymax.push_back(pq.top());
            pq = priority_queue<int>();

        }

        sort(ymax.rbegin(),ymax.rend());
        if(ymax.size()<3)
        return -1;
        else
        return ymax[0]+ymax[1]+ymax[2];

    }
};