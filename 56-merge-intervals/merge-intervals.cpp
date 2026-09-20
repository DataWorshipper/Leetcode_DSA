class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
         
        sort(intervals.begin(),intervals.end());
        int st=intervals[0][0];
        int end=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++)
        {
            int st_1=intervals[i][0];
           int end_1=intervals[i][1];
            if(st_1<=end)
            {
                end=max(end,end_1);
            }
            else
            {
                ans.push_back({st,end});
                st=st_1;
                end=end_1;
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};